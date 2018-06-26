#pragma once

#include <QtMath>
#include <QDebug>
#include <QThread>
#include <QTreeWidget>
#include "DataServer.h"
#include "NameServer.h"

#include "config.h"

class NameServer : public QObject
{
	Q_OBJECT

public:
	NameServer() = delete;
	explicit NameServer(QTreeWidget *treeWidget, DataServer *servers[DATASERVER_NUM], QObject *parent = nullptr);
	~NameServer();
	
public slots:
	void uploadFile(QString filePath, QString uploadPath);
	void createDir(QString dirPath, QString dirName);


private:
	QTreeWidget *fileTree;
	DataServer *dataServers[DATASERVER_NUM];

	quint32 fileId;

signals:
	void addChunk(quint32 fileId, quint32 chunkId, quint32 chunkNum, QByteArray chunkData);
	void fileUploaded();
	void dirCreated();
};

