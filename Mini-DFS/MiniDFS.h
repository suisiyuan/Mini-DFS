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

private:
	Ui::MiniDFSClass ui;
	
	bool isFile;

	QThread *nameThread;
	QThread *dataThreads[DATASERVER_NUM];
	NameServer *nameServer;
	DataServer *dataServers[DATASERVER_NUM];


private slots:
	void on_getFileBtn_clicked();
	void on_uploadBtn_clicked();
	void on_createDirBtn_clicked();

	void on_fileTree_currentItemChanged();
	

signals:
	void uploadFile(QString filePath, QString uploadPath);
	void createDir(QString dirpath, QString dirName);

};
