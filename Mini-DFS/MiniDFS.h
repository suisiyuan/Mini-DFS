#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniDFS.h"

#include <QDebug>
#include <QThread>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>

#include "config.h"
#include "NameServer.h"
#include "DataServer.h"


class MiniDFS : public QMainWindow
{
	Q_OBJECT

public:
	MiniDFS(QWidget *parent = Q_NULLPTR);
	~MiniDFS();


public slots:
	void fileUploaded();
	void dirCreated();
	void fileDownloaded();
	void chunkDownloaded();

private:
	Ui::MiniDFSClass ui;
	

	QTreeWidgetItem *currentItem;

	QThread *nameThread;
	QThread *dataThreads[DATASERVER_NUM];
	NameServer *nameServer;
	DataServer *dataServers[DATASERVER_NUM];


private slots:
	void on_uploadBtn_clicked();
	void on_createDirBtn_clicked();

	void on_downloadBtn_clicked();
	void on_downloadChunkBtn_clicked();

	void on_fileTree_currentItemChanged();


	void on_deleteBtn_1_clicked();
	void on_deleteBtn_2_clicked();
	void on_deleteBtn_3_clicked();
	void on_deleteBtn_4_clicked();
	

signals:
	void uploadFile(QString filePath, QString uploadPath);
	void createDir(QString dirpath, QString dirName);
	void downloadFile(QTreeWidgetItem *item, QString path);
	void downloadChunk(QTreeWidgetItem *item, quint32 offset, QString path);
};
