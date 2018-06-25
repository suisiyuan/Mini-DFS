#include "MiniDFS.h"

MiniDFS::MiniDFS(QWidget *parent): 
	QMainWindow(parent),
	nameServer(new NameServer),
	dataServer_0(new DataServer),
	dataServer_1(new DataServer),
	dataServer_2(new DataServer),
	dataServer_3(new DataServer),
	currentDir(nullptr),
	currentItem(nullptr),
	isFile(false)
{
	ui.setupUi(this);


	QObject::connect(
		this, SIGNAL(itemChanged(bool, QString, QString)),
		this, SLOT(update_uploadPathEdit(bool, QString, QString))
	);
}

/*�ϴ��ļ�*/

// ��ȡ�ļ�
void MiniDFS::on_getFileBtn_clicked()
{
	QString filePath = QFileDialog::getOpenFileName(this, "Upload File", QDir::homePath());
	if (filePath != nullptr)
		ui.uploadFileEdit->setText(filePath);
	else
		ui.uploadFileEdit->clear();
}

// ����ϴ���ť
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
	
}

// �����ϴ�·��
void MiniDFS::update_uploadPathEdit(bool isFile, QString dir, QString name)
{
	ui.uploadPathEdit->setText(dir);
}



/*�ļ��б���ͼ*/
void MiniDFS::on_fileTree_currentItemChanged()
{
	currentItem = ui.fileTree->currentItem();
	isFile = (currentItem->text(DIR_COL) != QString("True"));
	if (isFile)
		currentDir = currentItem->parent();
	else
		currentDir = currentItem;
	emit itemChanged(isFile, currentDir->text(FILE_COL), currentItem->text(FILE_COL));
}

void MiniDFS::on_createDirBtn_clicked()
{
	
}
