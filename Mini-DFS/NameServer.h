#pragma once

#include <QThread>


class NameServer : public QThread
{
	Q_OBJECT

public:
	NameServer(QObject *parent = nullptr);
	~NameServer();
};

