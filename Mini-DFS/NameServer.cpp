#include "NameServer.h"

NameServer::NameServer(QTreeWidget *treeWidget, DataServer *servers[DATASERVER_NUM], QObject *parent) :
	QObject(parent),
	fileTree(treeWidget),
	fileId(0)
{
	for (quint8 i = 0; i < DATASERVER_NUM; i++) {
		dataServers[i] = servers[i];
		QObject::connect(
			this, SIGNAL(addChunk(quint32, quint32, quint32, QByteArray)),
			dataServers[i], SLOT(addChunk(quint32, quint32, quint32, QByteArray)),
			Qt::QueuedConnection
		);
	}
}

NameServer::~NameServer()
{
}


// 接受文件上传
void NameServer::uploadFile(QString filePath, QString uploadPath)
{
	QFile file(filePath);
	QFileInfo fileInfo(filePath);

	qint64 fileSize = file.size();
	quint32 chunkNum = qCeil(fileSize / (double)CHUNK_SIZE);
	
	file.open(QIODevice::ReadOnly);

	for (quint32 i = 0; i < chunkNum; i++) {
		QByteArray chunk = file.read(CHUNK_SIZE);
		emit addChunk(fileId, i, chunkNum, chunk);
	}
	file.close();

	QStringList info;
	QString str0 = fileInfo.fileName();
	QString str1 = QString("False");
	QString str2 = QString::number(fileId++);
	QString str3;
	double size = fileSize;
	if (size < 1024.0) {
		str3 = QString::number(size, 'f', 2) + " B";
	}
	else if ((size /= 1024) && size < 1024.0) {
		str3 = QString::number(size, 'f', 2) + " KB";
	}
	else if ((size /= 1024) && size < 1024.0) {
		str3 = QString::number(size, 'f', 2) + " MB";
	}
	else {
		size /= 1024;
		str3 = QString::number(size, 'f', 2) + " GB";
	}

	QString str4 = QString::number(chunkNum);
	info << str0 << str1 << str2 << str3 << str4;

	QList<QTreeWidgetItem *> dirs = this->fileTree->findItems(uploadPath, Qt::MatchExactly | Qt::MatchRecursive, FILE_COL);
	QTreeWidgetItem *dir = dirs.first();
	dir->insertChild(0, new QTreeWidgetItem(info));
	dir->sortChildren(FILE_COL, Qt::AscendingOrder);

	emit fileUploaded();
}


// 新建文件夹
void NameServer::createDir(QString dirPath, QString dirName)
{
	QStringList info;
	QString str0 = dirPath + dirName + "/";
	QString str1 = QString("True");
	info << str0 << str1;

	QList<QTreeWidgetItem *> dirs = this->fileTree->findItems(dirPath, Qt::MatchExactly | Qt::MatchRecursive, FILE_COL);
	QTreeWidgetItem *dir = dirs.first();
	
	quint32 count = dir->childCount();
	for (quint32 i = 0; (i < count) && itemIsDirectory(dir->child(i)); i++) {
		if (dir->child(i)->text(FILE_COL) == str0) {
			return;
		}
	}

	dir->insertChild(0, new QTreeWidgetItem(info));
	dir->sortChildren(FILE_COL, Qt::AscendingOrder);
	
	emit dirCreated();
}

// 判断一个item是不是文件夹
bool NameServer::itemIsDirectory(QTreeWidgetItem *item)
{
	return (item->text(DIR_COL) == QString("True"));
}