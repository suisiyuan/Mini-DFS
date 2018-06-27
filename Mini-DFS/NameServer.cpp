#include "NameServer.h"

NameServer::NameServer(QTreeWidget *treeWidget, DataServer *servers[DATASERVER_NUM], QObject *parent) :
	QObject(parent),
	fileTree(treeWidget),
	currentId(0)
{
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		dataServers[i] = servers[i];
		// 写chunk
		QObject::connect(
			this, SIGNAL(writeChunk(quint32, quint32, QByteArray, QSemaphore *)),
			dataServers[i], SLOT(writeChunk(quint32, quint32, QByteArray, QSemaphore *)),
			Qt::QueuedConnection
		);
		// 读chunk
		QObject::connect(
			this, SIGNAL(readChunk(quint32, quint32, QByteArray *, QSemaphore *)),
			dataServers[i], SLOT(readChunk(quint32, quint32, QByteArray *, QSemaphore *)),
			Qt::QueuedConnection
		);
	}
}

NameServer::~NameServer()
{
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
		emit writeChunk(currentId, i, chunk, semaphore);
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
		chunkIntegrity(i, chunkBuf, data);
		file.write(data);
	}
	delete semaphore;

	file.close();

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
	chunkIntegrity(offset, chunkBuf, data);
	file.write(data);

	delete semaphore;
	file.close();

	emit chunkDownloaded();
}





// 判断一个item是不是文件夹
bool NameServer::itemIsDirectory(QTreeWidgetItem *item)
{
	return (item->text(DIR_COL) == QString("True"));
}

// 判断chunk是否完整
bool NameServer::chunkIntegrity(quint32 chunkId, QByteArray chunkBuf[DATASERVER_NUM], QByteArray &result)
{
	quint8 index = (chunkId + 1) % DATASERVER_NUM;
	result = chunkBuf[index];

	return true;
}