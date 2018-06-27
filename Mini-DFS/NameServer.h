#pragma once

#include <QtMath>
#include <QDebug>
#include <QThread>
#include <QTreeWidget>
#include <QMutex>
#include <QSemaphore>
#include <QCryptographicHash>

#include "DataServer.h"
#include "NameServer.h"

#include "config.h"



class NameServer : public QObject
{
	Q_OBJECT

public:
	NameServer() = delete;
	explicit NameServer(QTreeWidget *fileWidget, QTreeWidget *chunkWidget[DATASERVER_NUM], QObject *parent = nullptr);
	~NameServer();
	

public slots:
	void uploadFile(QString filePath, QString uploadPath);
	void createDir(QString dirPath, QString dirName);
	void downloadFile(QTreeWidgetItem *item, QString path);
	void downloadChunk(QTreeWidgetItem *item, quint32 offset, QString path);

	
	void recoverServer(quint8 id);


private:
	// 内部变量
	QTreeWidget *fileTree;
	quint32 currentId;

	// DataServer 变量
	QThread *dataThreads[DATASERVER_NUM];
	DataServer *dataServers[DATASERVER_NUM];

	bool itemIsDirectory(QTreeWidgetItem *item);
	bool chunkIntegrity(quint32 chunkId, QByteArray chunkBuf[DATASERVER_NUM], QByteArray &result);
	QByteArray getOriChunk(quint32 chunkId, quint8 serverId, QByteArray chunkBuf[DATASERVER_NUM]);

signals:
	// 发送给Data Server
	void writeChunk(quint32 fileId, quint32 chunkId, quint8 servers, QByteArray chunkData, QSemaphore *semaphore);
	void readChunk(quint32 fileId, quint32 chunkId, QByteArray *chunkData, QSemaphore *semaphore);

	void deleteServer(quint8 id);


	// 发送给UI界面
	void fileUploaded();
	void dirCreated();
	void fileDownloaded();
	void chunkDownloaded();
	void serverCorrupted();
	void serverRecovered();
};

