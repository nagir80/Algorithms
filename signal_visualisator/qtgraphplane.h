#ifndef QTGRAPHPLANE_H
#define QTGRAPHPLANE_H

#include <QGraphicsView>
#include "ui_qtgraphplane.h"


class QTGraphPlane : public QGraphicsView
{
	Q_OBJECT

public:
	QTGraphPlane(QWidget *parent = 0);
	~QTGraphPlane();

private:
	Ui::QTGraphPlane ui;
	QGraphicsScene *base_scene;
	//std::vector<std::vector<qreal> > data_lines;
	QVector<QVector<qreal> > data_lines;
};

#endif // QTGRAPHPLANE_H