#include "signal_visualisator.h"
//#include "ui_add_graph.h"
#include "qtinputwidget.h"



signal_visualisator::signal_visualisator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(handleButton()));
}

signal_visualisator::~signal_visualisator()
{

}

void signal_visualisator::handleButton(){
	QVector<double> x1(101), y1(101);
	QVector<double> x2(101), y2(101);
	
	//QString edit1 = ui.textEdit->toPlainText();

	//ui.textEdit_2->setText(edit1);
	
	

	
	QHBoxLayout *lay = new QHBoxLayout(ui.widget_5);
	QTextEdit *te = new QTextEdit();
	QTextEdit *te2 = new QTextEdit();
	QTextEdit *te3 = new QTextEdit();
	QTextEdit *te4 = new QTextEdit();

	lay->addWidget(te);
	lay->addWidget(te2);
	lay->addWidget(te3);
	lay->addWidget(te4);



	
	
//	ui.gridLayout_2->update();

	/*
	static int u = 0;
	for (int i = 0; i<101; ++i)
	{
		x1[i] = i / 50.0 - 1; // x goes from -1 to 1
//		y1[i] = 0.05*u + x1[i] * x1[i]; // let's plot a quadratic function
		y1[i] = sin(0.05*u + 10*x1[i]); // let's plot a quadratic function

		x2[i] = i / 50.0 - 1; // x goes from -1 to 1
//		y2[i] = -(0.05*u + x2[i] * x2[i]); // let's plot a quadratic function
		y2[i] = -sin((0.05*u + 10*x2[i])); // let's plot a quadratic function


	}
	
	ui.widget->addGraph();
	ui.widget->graph(u)->addData(x1, y1);
	ui.widget->replot();
	ui.widget->xAxis->setLabel("x");
	ui.widget->yAxis->setLabel("y");
	// set axes ranges, so we see all data:
	ui.widget->xAxis->setRange(-1, 1);
	ui.widget->yAxis->setRange(-1, 1);
	ui.widget->replot();

	ui.widget_2->addGraph();
	ui.widget_2->graph(u)->addData(x2, y2);
	ui.widget_2->replot();
	ui.widget_2->xAxis->setLabel("x");
	ui.widget_2->yAxis->setLabel("y");
	// set axes ranges, so we see all data:
	ui.widget_2->xAxis->setRange(-1, 1);
	ui.widget_2->yAxis->setRange(-1, 1);
	ui.widget_2->replot();

	ui.widget_3->addGraph();

	ui.widget_3->graph(u)->addData(x2, y1);
	ui.widget_3->replot();
	ui.widget_3->xAxis->setLabel("x");
	ui.widget_3->yAxis->setLabel("y");
	// set axes ranges, so we see all data:
	ui.widget_3->xAxis->setRange(-1, 1);
	ui.widget_3->yAxis->setRange(-1, 1);
	ui.widget_3->replot();
	u++;
	*/
}