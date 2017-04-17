#include "qml_cpp_test.h"
#include <QtWidgets/QApplication>
#include <QDeclarativeView>

int main(int argc, char *argv[])
{
	QDeclarativeView *pv;
	QApplication a(argc, argv);
	qml_cpp_test w;


	w.show();
	return a.exec();
}
