#include "qtgraphplane.h"

QTGraphPlane::QTGraphPlane(QWidget *parent)
	: QGraphicsView(parent)
{
	ui.setupUi(this);
	base_scene = new QGraphicsScene();
	QLine linex;
	linex.setLine(-400, 0, 400, 0);
	QLine liney;
	liney.setLine(0, -400, 0, 400);

	base_scene->addLine(linex);
	base_scene->addLine(liney);
	this->setScene(base_scene);
	this->show();

}

QTGraphPlane::~QTGraphPlane()
{

}
