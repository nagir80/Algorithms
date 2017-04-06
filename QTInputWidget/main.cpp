#include "qtinputwidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTInputWidget w;
	w.show();
	return a.exec();
}
