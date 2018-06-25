#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniDFS.h"

class MiniDFS : public QMainWindow
{
	Q_OBJECT

public:
	MiniDFS(QWidget *parent = Q_NULLPTR);

private:
	Ui::MiniDFSClass ui;
};
