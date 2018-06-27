#pragma once

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QMutex>
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
	void writeChunk(quint32 fileId, quint32 chunkId, quint8 servers, QByteArray chunkData, QSemaphore *semaphore);
	void readChunk(quint32 fileId, quint32 chunkId, QByteArray *chunkBuf, QSemaphore *semaphore);
	void deleteServer(quint8 id);

private:
	quint8 serverId;
	quint8 serverMask;

	QDir *storeDir;
	QTreeWidget *fileTree;


};

