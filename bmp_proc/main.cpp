#include "bmp_proc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	bmp_proc w;
	


	w.show();
	return a.exec();
}
