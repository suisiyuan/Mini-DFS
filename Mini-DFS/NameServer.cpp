#include "NameServer.h"

NameServer::NameServer(QTreeWidget *fileWidget, QTreeWidget *chunkWidget[DATASERVER_NUM], QObject *parent) :
	QObject(parent),
	fileTree(fileWidget),
	currentId(0)
{
	// 创建子线程和服务器实例，并将对应服务器实例移至对应子线程。
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		qDebug() << "Create Data Server Thread" << i;
		dataThreads[i] = new QThread(this);
		dataServers[i] = new DataServer(i, chunkWidget[i]);
		dataServers[i]->moveToThread(dataThreads[i]);
	}


	// 连接信号与槽函数
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		// 写chunk
		QObject::connect(
			this, SIGNAL(writeChunk(quint32, quint32, quint8, QByteArray, QSemaphore *)),
			dataServers[i], SLOT(writeChunk(quint32, quint32, quint8, QByteArray, QSemaphore *)),
			Qt::QueuedConnection
		);
		// 读chunk
		QObject::connect(
			this, SIGNAL(readChunk(quint32, quint32, QByteArray *, QSemaphore *)),
			dataServers[i], SLOT(readChunk(quint32, quint32, QByteArray *, QSemaphore *)),
			Qt::QueuedConnection
		);
		// 删除数据
		QObject::connect(
			this, SIGNAL(deleteServer(quint8)),
			dataServers[i], SLOT(deleteServer(quint8)),
			Qt::QueuedConnection
		);
	}

	// 开启Data Server Thread
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		dataThreads[i]->start();
		qDebug() << "Start Data Server Thread" << i;
	}

}

NameServer::~NameServer()
{
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		if (dataThreads[i] != nullptr) {
			dataThreads[i]->terminate();
			delete dataThreads[i];
		}	
		if (dataServers[i] != nullptr) {
			delete dataServers[i];
		}
	}
}


// 文件上传
void NameServer::uploadFile(QString filePath, QString uploadPath)
{
	QFile file(filePath);
	QFileInfo fileInfo(filePath);

	qint64 fileSize = file.size();
	quint32 chunkNum = qCeil(fileSize / (double)CHUNK_SIZE);
	
	file.open(QIODevice::ReadOnly);

	QSemaphore *semaphore = new QSemaphore(0);
	for (quint32 i = 0; i < chunkNum; i++) {
		QByteArray chunk = file.read(CHUNK_SIZE);
		emit writeChunk(currentId, i, ALL_SERVERS, chunk, semaphore);
		semaphore->acquire(REPLICA_NUM);
	}
	delete semaphore;

	file.close();

	QStringList info;
	QString str0 = fileInfo.fileName();
	QString str1 = QString("False");
	QString str2 = QString::number(currentId++);
	QString str3;
	double size = fileSize;
	if (size < 1024.0) {
		str3 = QString::number(size, 'f', 2) + " B";
	}
	else if ((size /= 1024) && size < 1024.0) {
		str3 = QString::number(size, 'f', 2) + " KB";
	}
	else if ((size /= 1024) && size < 1024.0) {
		str3 = QString::number(size, 'f', 2) + " MB";
	}
	else {
		size /= 1024;
		str3 = QString::number(size, 'f', 2) + " GB";
	}

	QString str4 = QString::number(chunkNum);
	info << str0 << str1 << str2 << str3 << str4;

	QList<QTreeWidgetItem *> dirs = this->fileTree->findItems(uploadPath, Qt::MatchFixedString | Qt::MatchRecursive, FILE_COL);
	QTreeWidgetItem *dir = dirs.first();
	dir->insertChild(0, new QTreeWidgetItem(info));
	dir->sortChildren(FILE_COL, Qt::AscendingOrder);

	emit fileUploaded();
}


// 新建文件夹
void NameServer::createDir(QString dirPath, QString dirName)
{
	QStringList info;
	QString str0 = dirPath + dirName + "/";
	QString str1 = QString("True");
	info << str0 << str1;

	QList<QTreeWidgetItem *> dirs = this->fileTree->findItems(dirPath, Qt::MatchFixedString | Qt::MatchRecursive, FILE_COL);
	QTreeWidgetItem *dir = dirs.first();
	
	quint32 count = dir->childCount();
	for (quint32 i = 0; (i < count) && itemIsDirectory(dir->child(i)); i++) {
		if (dir->child(i)->text(FILE_COL) == str0) {
			return;
		}
	}

	dir->insertChild(0, new QTreeWidgetItem(info));
	dir->sortChildren(FILE_COL, Qt::AscendingOrder);
	
	emit dirCreated();
}

// 下载文件
void NameServer::downloadFile(QTreeWidgetItem *item, QString path)
{
	QFile file(path);
	file.open(QIODevice::WriteOnly | QIODevice::Truncate);

	quint32 downloadId = item->text(ID_COL).toInt();
	quint32 downloadChunks = item->text(CHUNK_COL).toInt();
	QByteArray chunkBuf[DATASERVER_NUM];

	QSemaphore *semaphore = new QSemaphore(0);
	QByteArray data;

	for (quint32 i = 0; i < downloadChunks; i++) {
		emit readChunk(downloadId, i, chunkBuf, semaphore);
		semaphore->acquire(DATASERVER_NUM);
		bool correct = chunkIntegrity(i, chunkBuf, data);
		if (!correct) {
			file.close();
			file.remove();
			delete semaphore;
			emit serverCorrupted();
			return;
		}
		file.write(data);
	}

	file.close();
	delete semaphore;

	emit fileDownloaded();
}


// 下载chunk
void NameServer::downloadChunk(QTreeWidgetItem *item, quint32 offset, QString path)
{
	QFile file(path);
	file.open(QIODevice::WriteOnly | QIODevice::Truncate);

	quint32 downloadId = item->text(ID_COL).toInt();
	QByteArray chunkBuf[DATASERVER_NUM];

	QSemaphore *semaphore = new QSemaphore(0);
	QByteArray data;
	emit readChunk(downloadId, offset, chunkBuf, semaphore);
	semaphore->acquire(DATASERVER_NUM);
	delete semaphore;
	bool correct = chunkIntegrity(offset, chunkBuf, data);

	if (!correct) {
		file.close();
		file.remove();

		emit serverCorrupted();
		return;
	}
	else {
		file.write(data);
		file.close();

		emit chunkDownloaded();
		return;
	}

	
}


// 恢复数据服务器
void NameServer::recoverServer(quint8 id)
{
	QList<QTreeWidgetItem *> items = fileTree->findItems("False", Qt::MatchFixedString | Qt::MatchRecursive, DIR_COL);
	if (items.isEmpty()) {
		emit serverRecovered();
		return;
	}
	
	QSemaphore *semaphore = new QSemaphore(0);
	for (auto item : items) {
		quint32 fileId = item->text(ID_COL).toInt();
		quint32 chunkNum = item->text(CHUNK_COL).toInt();
		for (quint32 i = 0; i < chunkNum; i++) {
			if (i % DATASERVER_NUM == id)
				continue;
			QByteArray chunkBuf[DATASERVER_NUM];
			
			QByteArray data;
			emit readChunk(fileId, i, chunkBuf, semaphore);
			semaphore->acquire(DATASERVER_NUM);
			
			QByteArray orig = getOriChunk(i, id, chunkBuf);

			emit writeChunk(fileId, i, (0x01 << id), orig, semaphore);
			semaphore->acquire(1);		
		}
	}
	delete semaphore;
	emit serverRecovered();
	return;
}

// 判断一个item是不是文件夹
bool NameServer::itemIsDirectory(QTreeWidgetItem *item)
{
	return (item->text(DIR_COL) == QString("True"));
}

// 判断chunk是否完整
bool NameServer::chunkIntegrity(quint32 chunkId, QByteArray chunkBuf[DATASERVER_NUM], QByteArray &result)
{
	QList<QByteArray> checksum;
	quint8 point = chunkId % DATASERVER_NUM;
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		if (i != point) {
			checksum << QCryptographicHash::hash(chunkBuf[i], QCryptographicHash::Md5);
		}
	}

	if ((checksum.at(0) == checksum.at(1)) && (checksum.at(1) == checksum.at(2))) {
		quint8 index = (chunkId + 1) % DATASERVER_NUM;
		result = chunkBuf[index];
		return true;
	}
	else {
		return false;
	}
}

// 恢复原始chunk
QByteArray NameServer::getOriChunk(quint32 chunkId, quint8 serverId, QByteArray chunkBuf[DATASERVER_NUM])
{
	quint8 point = chunkId % DATASERVER_NUM;
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		if ((i != point) && (i != serverId)) {
			return chunkBuf[i];
		}
	}

}