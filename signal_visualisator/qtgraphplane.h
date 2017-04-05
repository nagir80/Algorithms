#ifndef QTGRAPHPLANE_H
#define QTGRAPHPLANE_H

#include <QGraphicsView>
#include "ui_qtgraphplane.h"
#include "muParser.h"


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
	mu::Parser prs;
};

#endif // QTGRAPHPLANE_H


/*
mu::Parser *hlp_parser = new mu::Parser();
for (int i = 0; i < this->in.size(); i++) {
hlp_parser->DefineVar(in_name[i], &this->in[i].second);
}
std::wstring *ws_hlp = new std::wstring(formula.begin(), formula.end());
hlp_parser->SetExpr(*ws_hlp);
add_field->second = *hlp_parser;



//	parser.push_back(*hlp_parser);
delete hlp_parser;

*/