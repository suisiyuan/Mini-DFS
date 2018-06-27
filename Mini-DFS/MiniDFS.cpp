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

	qDebug() << "Create Name Server Thread";
	nameThread = new QThread(this);
	nameServer = new NameServer(ui.fileTree, widgets);
	nameServer->moveToThread(nameThread);


	// �����ź����
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

		// ɾ�����ݷ�����
		QObject::connect(
			this, SIGNAL(deleteServer(quint8)),
			nameServer, SIGNAL(deleteServer(quint8)),
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

		// ��������
		QObject::connect(
			nameServer, SIGNAL(serverCorrupted()),
			this, SLOT(serverCorrupted()),
			Qt::QueuedConnection
		);
	}
	

	// ����Name Server Thread
	nameThread->start();
	qDebug() << "Start Name Server Thread";

}

MiniDFS::~MiniDFS()
{
	nameThread->terminate();
	if (nameThread != nullptr)
		delete nameThread;
	if (nameServer != nullptr)
		delete nameServer;
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
	ui.deleteBtn_1->setEnabled(true);
	ui.deleteBtn_2->setEnabled(true);
	ui.deleteBtn_3->setEnabled(true);
	ui.deleteBtn_4->setEnabled(true);
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

// �������ļ���
void MiniDFS::serverCorrupted()
{
	QMessageBox::critical(this, "Critical", "Server data has been corrupted, please recover it!");
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
	ui.deleteBtn_1->setEnabled(false);
	ui.recoverBtn_1->setEnabled(true);
	emit deleteServer(0);
}

void MiniDFS::on_deleteBtn_2_clicked()
{
	ui.deleteBtn_2->setEnabled(false);
	ui.recoverBtn_2->setEnabled(true);
	emit deleteServer(1);
}

void MiniDFS::on_deleteBtn_3_clicked()
{
	ui.deleteBtn_3->setEnabled(false);
	ui.recoverBtn_3->setEnabled(true);
	emit deleteServer(2);
}

void MiniDFS::on_deleteBtn_4_clicked()
{
	ui.deleteBtn_4->setEnabled(false);
	ui.recoverBtn_4->setEnabled(true);
	emit deleteServer(3);
}

void MiniDFS::on_RecoverBtn_1_clicked()
{
	ui.deleteBtn_1->setEnabled(true);
	ui.recoverBtn_1->setEnabled(false);
	emit recoverServer(0);
}

void MiniDFS::on_RecoverBtn_2_clicked()
{
	ui.deleteBtn_2->setEnabled(true);
	ui.recoverBtn_2->setEnabled(false);
	emit recoverServer(1);
}

void MiniDFS::on_RecoverBtn_3_clicked()
{
	ui.deleteBtn_3->setEnabled(true);
	ui.recoverBtn_3->setEnabled(false);
	emit recoverServer(2);
}

void MiniDFS::on_RecoverBtn_4_clicked()
{
	ui.deleteBtn_4->setEnabled(true);
	ui.recoverBtn_4->setEnabled(false);
	emit recoverServer(3);
}




