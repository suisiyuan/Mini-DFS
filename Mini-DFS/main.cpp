#include "MiniDFS.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MiniDFS w;
	w.setFixedSize(w.size());
	w.show();
	return a.exec();
}
