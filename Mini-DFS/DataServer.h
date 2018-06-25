#pragma once

#include <QThread>

class DataServer : public QThread
{
public:
	DataServer(QObject *parent = nullptr);
	~DataServer();
};

