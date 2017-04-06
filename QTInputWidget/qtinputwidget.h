#ifndef QTINPUTWIDGET_H
#define QTINPUTWIDGET_H

#include <QtWidgets/QWidget>
#include "ui_qtinputwidget.h"

class QTInputWidget : public QWidget
{
	Q_OBJECT

public:
	QTInputWidget(QWidget *parent = 0);
	~QTInputWidget();

private:
	Ui::QTInputWidgetClass ui;
};

#endif // QTINPUTWIDGET_H
