#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniDFS.h"

#include <QDebug>
#include <QThread>
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

private:
	Ui::MiniDFSClass ui;

	NameServer *nameServer;
	DataServer *dataServer_0, dataServer_1, dataServer_2, dataServer_3;

	
	QTreeWidgetItem *currentDir;
	QTreeWidgetItem *currentItem;
	bool isFile;


private slots:
	void on_getFileBtn_clicked();
	void on_uploadBtn_clicked();
	void update_uploadPathEdit(bool isFile, QString dir, QString name);

	void on_fileTree_currentItemChanged();
	void on_createDirBtn_clicked();

signals:
	void itemChanged(bool isFile, QString dir, QString name);
};
