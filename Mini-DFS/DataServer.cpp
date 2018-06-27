#include "DataServer.h"


// Constuctor
DataServer::DataServer(quint8 id, QTreeWidget *widget, QObject *parent) :
	QObject(parent),
	serverId(id),
	serverMask(0x01),
	storeDir(nullptr),
	fileTree(widget)
{
	serverMask = serverMask << serverId;
	storeDir = new QDir(QDir(DATA_DIR).filePath(QString::number(serverId)));

	if (!storeDir->exists()) {
		storeDir->mkpath(".");
	}
}

// Destructor
DataServer::~DataServer()
{
	fileTree->clear();

	QStringList fileList = storeDir->entryList(QDir::Files);
	if (fileList.isEmpty())
		return;

	for (QString fileName : fileList) {
		QFile(storeDir->filePath(fileName)).remove();
	}
	delete storeDir;
}


// Ð´chunk
void DataServer::writeChunk(quint32 fileId, quint32 chunkId, quint8 servers, QByteArray chunkData, QSemaphore *semaphore)
{
	if ((chunkId % DATASERVER_NUM == serverId) || !(serverMask & servers))
		return;

	QString fileName = QString::number(fileId) + "_" + QString::number(chunkId) + ".chunk";
	QFile chunkFile(storeDir->filePath(fileName));
	chunkFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
	chunkFile.write(chunkData);
	chunkFile.close();

	QMutex mutex;
	mutex.lock();
	semaphore->release(1);
	mutex.unlock();
	
	QList<QTreeWidgetItem *> items = fileTree->findItems(QString::number(fileId), Qt::MatchFixedString, 0);
	if (items.isEmpty()) {
		QStringList top;
		top << QString::number(fileId);
		QTreeWidgetItem *fileItem = new QTreeWidgetItem(top);
		fileTree->addTopLevelItem(fileItem);

		QStringList child;
		child << QString::number(chunkId) << QCryptographicHash::hash(chunkData, QCryptographicHash::Md5).toHex();
		fileItem->addChild(new QTreeWidgetItem(child));
	}
	else {
		QStringList child;
		child << QString::number(chunkId) << QCryptographicHash::hash(chunkData, QCryptographicHash::Md5).toHex();
		items.front()->addChild(new QTreeWidgetItem(child));
	}

	return;
}

// ¶Áchunk
void DataServer::readChunk(quint32 fileId, quint32 chunkId, QByteArray *chunkBuf, QSemaphore *semaphore)
{
	if (chunkId % DATASERVER_NUM == serverId) {
		chunkBuf[serverId] = QByteArray();
		QMutex mutex;
		mutex.lock();
		semaphore->release(1);
		mutex.unlock();
		return;
	}
		
	QString fileName = QString::number(fileId) + "_" + QString::number(chunkId) + ".chunk";
	QFile chunkFile(storeDir->filePath(fileName));
	if (!chunkFile.exists()) {
		chunkBuf[serverId] = QByteArray();
		QMutex mutex;
		mutex.lock();
		semaphore->release(1);
		mutex.unlock();
		return;
	}
	else {
		chunkFile.open(QIODevice::ReadOnly);
		QByteArray chunkData = chunkFile.readAll();
		chunkFile.close();
		chunkBuf[serverId] = chunkData;
		QMutex mutex;
		mutex.lock();
		semaphore->release(1);
		mutex.unlock();
		return;
	}	
}


// É¾³ýÊý¾Ý
void DataServer::deleteServer(quint8 id)
{
	if (serverMask & id) {
		QStringList fileList = storeDir->entryList(QDir::Files);
		for (QString fileName : fileList) {
			QFile(storeDir->filePath(fileName)).remove();
		}
		fileTree->clear();
	}
}

