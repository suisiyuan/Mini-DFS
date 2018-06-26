#include "DataServer.h"


// Constuctor
DataServer::DataServer(quint8 id, QObject *parent) :
	QObject(parent),
	serverId(id)
{
	storeDir = new QDir(QDir(DATA_DIR).filePath(QString::number(id)));

	if (!storeDir->exists()) {
		storeDir->mkpath(".");
	}
	else {
		QStringList fileList = storeDir->entryList(QDir::Files);
		for (QString fileName : fileList) {
			QFile(storeDir->filePath(fileName)).remove();
		}
	}
}

// Destructor
DataServer::~DataServer()
{
	delete storeDir;
}


// Receive Signal: Add Chunk 
void DataServer::addChunk(quint32 fileId, quint32 chunkId, quint32 chunkNum, QByteArray chunkData)
{
	if (chunkId % DATASERVER_NUM == serverId)
		return;

	QString fileName = QString::number(fileId) + "_" + QString::number(chunkId) + ".chunk";

	qDebug() << fileName;
	QFile chunkFile(storeDir->filePath(fileName));
	chunkFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
	chunkFile.write(chunkData);

	chunkFile.close();
}
