#include "MiniDFS.h"

MiniDFS::MiniDFS(QWidget *parent): 
	QMainWindow(parent),
	isFile(false)
{
	ui.setupUi(this);
	
	// 当前UI线程
	qDebug() << "UI Thread ID: " << QThread::currentThreadId();
	qDebug();

	// 创建子线程和服务器实例，并将对应服务器实例移至对应子线程。
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		qDebug() << "Create Data Server Thread" << i;
		dataThreads[i] = new QThread(this);
		dataServers[i] = new DataServer(i);
		dataServers[i]->moveToThread(dataThreads[i]);
	}

	qDebug() << "Create Name Server Thread";
	nameThread = new QThread(this);
	nameServer = new NameServer(ui.fileTree, dataServers);
	nameServer->moveToThread(nameThread);

	qDebug();

	// 连接信号与槽

	// 上传文件
	{
		// 上传文件
		QObject::connect(
			this, SIGNAL(uploadFile(QString, QString)),
			nameServer, SLOT(uploadFile(QString, QString)),
			Qt::QueuedConnection
		);
		// 新建文件夹
		QObject::connect(
			this, SIGNAL(createDir(QString, QString)),
			nameServer, SLOT(createDir(QString, QString)),
			Qt::QueuedConnection
		);
		// 已上传文件
		QObject::connect(
			nameServer, SIGNAL(fileUploaded()),
			this, SLOT(fileUploaded()),
			Qt::QueuedConnection
		);
	}
	

	// 开启Name Server Thread
	nameThread->start();
	qDebug() << "Start Name Server Thread";

	// 开启Data Server Thread
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		dataThreads[i]->start();
		qDebug() << "Start Data Server Thread" << i;
	}

	qDebug();
}

MiniDFS::~MiniDFS()
{
	nameThread->terminate();
	delete nameThread;
	delete nameServer;
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		dataThreads[i]->terminate();
		delete dataThreads[i];
		delete dataServers[i];
	}
}


/*上传文件*/

// 获取文件
void MiniDFS::on_getFileBtn_clicked()
{
	QString filePath = QFileDialog::getOpenFileName(this, "Upload File", QDir::homePath());
	if (filePath != nullptr)
		ui.uploadFileEdit->setText(filePath);
	else
		ui.uploadFileEdit->clear();
}

// 点击上传按钮
void MiniDFS::on_uploadBtn_clicked()
{
	QString filePath = ui.uploadFileEdit->text();
	QString uploadPath = ui.uploadPathEdit->text();
	if (filePath.isEmpty()) {
		QMessageBox::warning(this, "Warning", "Please input file path.");
		return;
	}
	else if (!QFileInfo(filePath).isFile()) {
		QMessageBox::warning(this, "Warning", "Please input correct file path.");
		return;
	}
	
	emit uploadFile(filePath, uploadPath);
}

// 创建文件夹
void MiniDFS::on_createDirBtn_clicked()
{
	bool ok = false;
	QString text = QInputDialog::getText(this, "Directory Name", "Please input directory name: ", QLineEdit::Normal, "", &ok);
	if (ok && !text.isEmpty())
		emit createDir(ui.uploadPathEdit->text(), text);
}


// 上传文件成功
void MiniDFS::fileUploaded()
{
	ui.uploadFileEdit->clear();
	QMessageBox::information(this, "Information", "File was uploaded successfully.");
}


/*下载文件*/





/*文件列表视图*/
void MiniDFS::on_fileTree_currentItemChanged()
{
	QTreeWidgetItem *item = ui.fileTree->currentItem();
	isFile = (item->text(DIR_COL) != QString("True"));

	if (isFile) {
		ui.uploadPathEdit->setText(item->parent()->text(FILE_COL));
		ui.downloadPathEdit->setText(item->parent()->text(FILE_COL));
		ui.downloadNameEdit->setText(item->text(FILE_COL));
		ui.downloadIdEdit->setText(item->text(ID_COL));
	}
	else {
		ui.uploadPathEdit->setText(item->text(FILE_COL));
		ui.downloadPathEdit->setText(item->text(FILE_COL));
		ui.downloadNameEdit->clear();
		ui.downloadIdEdit->clear();
	}
}








