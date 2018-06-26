#pragma once

#include <QDir>
#include <QDebug>
#include <QFile>

#include "config.h"

class DataServer : public QObject
{
	Q_OBJECT

public:
	DataServer() = delete;
	explicit DataServer(quint8 id, QObject *parent = nullptr);
	~DataServer();



public slots:
	void addChunk(quint32 fileId, quint32 chunkId, quint32 chunkNum, QByteArray chunkData);

private:
	quint8 serverId;
	QDir *storeDir;
};

