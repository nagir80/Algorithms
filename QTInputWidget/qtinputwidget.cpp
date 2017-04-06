#include "qtinputwidget.h"

QTInputWidget::QTInputWidget(QWidget *parent)
	: QWidget(parent)
{
	if (parent == 0)
		ui.setupUi(this);
	else
		ui.setupUi(parent);
}

QTInputWidget::~QTInputWidget()
{

}
