#pragma once

#include <QtMath>
#include <QDebug>
#include <QThread>
#include <QTreeWidget>
#include <QMutex>
#include <QSemaphore>

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
	void downloadFile(QTreeWidgetItem *item, QString path);
	void downloadChunk(QTreeWidgetItem *item, quint32 offset, QString path);


private:
	// 内部变量
	QTreeWidget *fileTree;
	DataServer *dataServers[DATASERVER_NUM];
	quint32 currentId;

	bool itemIsDirectory(QTreeWidgetItem *item);
	bool chunkIntegrity(quint32 chunkId, QByteArray chunkBuf[DATASERVER_NUM], QByteArray &result);


signals:
	// 发送给Data Server
	void writeChunk(quint32 fileId, quint32 chunkId, QByteArray chunkData, QSemaphore *semaphore);
	void readChunk(quint32 fileId, quint32 chunkId, QByteArray *chunkData, QSemaphore *semaphore);

	// 发送给UI界面
	void fileUploaded();
	void dirCreated();
	void fileDownloaded();
	void chunkDownloaded();
};

