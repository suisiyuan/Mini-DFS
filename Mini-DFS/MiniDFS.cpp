#include "MiniDFS.h"

MiniDFS::MiniDFS(QWidget *parent): 
	QMainWindow(parent),
	currentItem(nullptr)
{
	ui.setupUi(this);
	
	// ��ǰUI�߳�
	qDebug() << "UI Thread ID: " << QThread::currentThreadId();
	
	QTreeWidget *widgets[DATASERVER_NUM] = {
		ui.chunkTree_1,
		ui.chunkTree_2,
		ui.chunkTree_3,
		ui.chunkTree_4
	};

	// �������̺߳ͷ�����ʵ����������Ӧ������ʵ��������Ӧ���̡߳�
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		qDebug() << "Create Data Server Thread" << i;
		dataThreads[i] = new QThread(this);
		dataServers[i] = new DataServer(i, widgets[i]);
		dataServers[i]->moveToThread(dataThreads[i]);
	}

	qDebug() << "Create Name Server Thread";
	nameThread = new QThread(this);
	nameServer = new NameServer(ui.fileTree, dataServers);
	nameServer->moveToThread(nameThread);

	qDebug();

	// �����ź����

	// �ϴ��ļ�
	{
		// �ϴ��ļ�
		QObject::connect(
			this, SIGNAL(uploadFile(QString, QString)),
			nameServer, SLOT(uploadFile(QString, QString)),
			Qt::QueuedConnection
		);
		// �½��ļ���
		QObject::connect(
			this, SIGNAL(createDir(QString, QString)),
			nameServer, SLOT(createDir(QString, QString)),
			Qt::QueuedConnection
		);
		// �����ļ�
		QObject::connect(
			this, SIGNAL(downloadFile(QTreeWidgetItem *, QString)),
			nameServer, SLOT(downloadFile(QTreeWidgetItem *, QString)),
			Qt::QueuedConnection
		);
		// ����chunk
		QObject::connect(
			this, SIGNAL(downloadChunk(QTreeWidgetItem *, quint32, QString)),
			nameServer, SLOT(downloadChunk(QTreeWidgetItem *, quint32, QString)),
			Qt::QueuedConnection
		);

		// ���ϴ��ļ�
		QObject::connect(
			nameServer, SIGNAL(fileUploaded()),
			this, SLOT(fileUploaded()),
			Qt::QueuedConnection
		);

		// �Ѵ����ļ���
		QObject::connect(
			nameServer, SIGNAL(dirCreated()),
			this, SLOT(dirCreated()),
			Qt::QueuedConnection
		);

		// �������ļ�
		QObject::connect(
			nameServer, SIGNAL(fileDownloaded()),
			this, SLOT(fileDownloaded()),
			Qt::QueuedConnection
		);

		// ������chunk
		QObject::connect(
			nameServer, SIGNAL(chunkDownloaded()),
			this, SLOT(chunkDownloaded()),
			Qt::QueuedConnection
		);
	}
	

	// ����Name Server Thread
	nameThread->start();
	qDebug() << "Start Name Server Thread";

	// ����Data Server Thread
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		dataThreads[i]->start();
		qDebug() << "Start Data Server Thread" << i;
	}

	qDebug();
}

MiniDFS::~MiniDFS()
{
	nameThread->terminate();
	if (nameThread != nullptr)
		delete nameThread;
	if (nameServer != nullptr)
		delete nameServer;
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		dataThreads[i]->terminate();
		if (dataThreads[i] != nullptr)
			delete dataThreads[i];
		if (dataServers[i] != nullptr)
			delete dataServers[i];
	}
}


/*�ϴ��ļ�*/

// ����ϴ���ť
void MiniDFS::on_uploadBtn_clicked()
{
	//QString filePath = ui.uploadFileEdit->text();
	QString filePath = QFileDialog::getOpenFileName(this, "Upload File", QDir::homePath());
	QString uploadPath = ui.uploadPathEdit->text();
	if (filePath.isEmpty()) {
		return;
	}
	else if (!QFileInfo(filePath).isFile()) {
		QMessageBox::warning(this, "Warning", "Please input correct file path.");
		return;
	}
	
	emit uploadFile(filePath, uploadPath);
}

// �����ļ���
void MiniDFS::on_createDirBtn_clicked()
{
	bool ok = false;
	QString text = QInputDialog::getText(this, "Directory Name", "Please input directory name: ", QLineEdit::Normal, "", &ok);
	if (ok && !text.isEmpty())
		emit createDir(ui.uploadPathEdit->text(), text);
}


// �ϴ��ļ��ɹ�
void MiniDFS::fileUploaded()
{
	QMessageBox::information(this, "Information", "File was uploaded successfully.");
}

// �½��ļ��гɹ�
void MiniDFS::dirCreated()
{
	QMessageBox::information(this, "Information", "Directory was created successfully.");
}

/*�����ļ�*/
// �����ļ�
void MiniDFS::on_downloadBtn_clicked()
{
	QString path = ui.downloadPathEdit->text();
	QString name = ui.downloadNameEdit->text();
	QString id = ui.downloadIdEdit->text();
	if (path.isEmpty() || name.isEmpty() || id.isEmpty()) {
		QMessageBox::warning(this, "Warning", "Please select file.");
		return;
	}

	QString filePath = QFileDialog::getSaveFileName(this, "Download File", QDir::homePath());
	if (!filePath.isEmpty()) {
		emit downloadFile(currentItem, filePath);
	}
	else {
		return;
	}
}


// ����chunk
void MiniDFS::on_downloadChunkBtn_clicked()
{
	QString path = ui.downloadPathEdit->text();
	QString name = ui.downloadNameEdit->text();
	QString id = ui.downloadIdEdit->text();
	quint32 offset = ui.offsetSpin->value();
	if (path.isEmpty() || name.isEmpty() || id.isEmpty()) {
		QMessageBox::warning(this, "Warning", "Please select file.");
		return;
	}

	QString filePath = QFileDialog::getSaveFileName(this, "Download File", QDir::homePath());
	if (!filePath.isEmpty()) {
		emit downloadChunk(currentItem, offset, filePath);
	}
	else {
		return;
	}
}

// �ļ����سɹ�
void MiniDFS::fileDownloaded()
{
	QMessageBox::information(this, "Information", "File was downloaded successfully.");
}

// Chunk���سɹ�
void MiniDFS::chunkDownloaded()
{
	QMessageBox::information(this, "Information", "Chunk was downloaded successfully.");
}


/*�ļ��б���ͼ*/
void MiniDFS::on_fileTree_currentItemChanged()
{
	currentItem = ui.fileTree->currentItem();
	bool isFile = (currentItem->text(DIR_COL) != QString("True"));

	if (isFile) {
		ui.uploadPathEdit->setText(currentItem->parent()->text(FILE_COL));
		ui.downloadPathEdit->setText(currentItem->parent()->text(FILE_COL));
		ui.downloadNameEdit->setText(currentItem->text(FILE_COL));
		ui.downloadIdEdit->setText(currentItem->text(ID_COL));

		ui.offsetSpin->setMinimum(0);
		ui.offsetSpin->setMaximum(currentItem->text(CHUNK_COL).toInt()-1);
		ui.offsetSpin->setValue(0);
	}
	else {
		ui.uploadPathEdit->setText(currentItem->text(FILE_COL));
		ui.downloadPathEdit->setText(currentItem->text(FILE_COL));
		ui.downloadNameEdit->clear();
		ui.downloadIdEdit->clear();

		ui.offsetSpin->setMinimum(0);
		ui.offsetSpin->setMaximum(0);
		ui.offsetSpin->setValue(0);
	}
}


void MiniDFS::on_deleteBtn_1_clicked()
{
	
}

void MiniDFS::on_deleteBtn_2_clicked()
{

}

void MiniDFS::on_deleteBtn_3_clicked()
{

}

void MiniDFS::on_deleteBtn_4_clicked()
{

}





