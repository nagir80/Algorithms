#include "signal_visualisator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	signal_visualisator w;
	w.show();
	return a.exec();
}
