#pragma once

#include <QDir>
#include <QFile>
#include <QSemaphore>
#include <QTreeWidget>
#include <QCryptographicHash>

#include "config.h"

class DataServer : public QObject
{
	Q_OBJECT

public:
	DataServer() = delete;
	explicit DataServer(quint8 id, QTreeWidget *widget, QObject *parent = nullptr);
	~DataServer();

public slots:
	void writeChunk(quint32 fileId, quint32 chunkId, QByteArray chunkData, QSemaphore *semaphore);
	void readChunk(quint32 fileId, quint32 chunkId, QByteArray *chunkBuf, QSemaphore *semaphore);
	void deleteServer(quint8 id);

private:
	quint8 serverId;
	QDir *storeDir;
	QTreeWidget *fileTree;

	bool compareId(quint8 id);


};

