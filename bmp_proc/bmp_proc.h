#ifndef BMP_PROC_H
#define BMP_PROC_H

#include <QtWidgets/QMainWindow>
#include "ui_bmp_proc.h"
#include "BitMapClass.h"

class bmp_proc : public QMainWindow
{
	Q_OBJECT

public:
	std::vector<BitMapClass*> bitMap_collection;
	bmp_proc(QWidget *parent = 0);
	~bmp_proc();

public slots:
void open_file(void);

private:
	Ui::bmp_procClass ui;
};

#endif // BMP_PROC_H
