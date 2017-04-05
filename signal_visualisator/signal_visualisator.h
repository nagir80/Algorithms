#ifndef SIGNAL_VISUALISATOR_H
#define SIGNAL_VISUALISATOR_H

#include <QtWidgets/QMainWindow>
#include "ui_signal_visualisator.h"
#include "qmath.h"

class signal_visualisator : public QMainWindow
{
	Q_OBJECT

public:
	signal_visualisator(QWidget *parent = 0);
	~signal_visualisator();

public slots:
	void handleButton();

private:
	Ui::signal_visualisatorClass ui;
};

#endif // SIGNAL_VISUALISATOR_H
