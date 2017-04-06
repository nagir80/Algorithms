#include "signal_visualisator.h"

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
	
//	QGraphicsScene *hlp = ui.graphicsView->scene();
//	hlp->addText("0");
//	for (int i = -180; i < 180; i++){
//		
//		int y = -100*sin(2*i*3.14159 / 180);
//		
//		hlp->addRect(i, y,2, 2);
//		auto it = hlp->items();
//		
//	}

	
	
//	ui.graphicsView->setScene(hlp);
//	ui.graphicsView->show();
}