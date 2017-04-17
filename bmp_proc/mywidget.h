#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include "ui_mywidget.h"
#include "BitMapClass.h"


class MyWidget : public QWidget
{
	Q_OBJECT



public:
	MyWidget(QMap<int, BitMapClass*>* ref, int it_bitmap, QWidget *parent = 0);
	~MyWidget();
	void paintEvent(QPaintEvent *event) override;
	void closeEvent(QCloseEvent * event) override;

private:
	Ui::MyWidget ui;
//	BitMapClass * inside_bitmap;
	QMap<int, BitMapClass*> *collection;
	int it_bitmap;

};

#endif // MYWIDGET_H
