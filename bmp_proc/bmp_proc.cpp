#include "bmp_proc.h"

bmp_proc::bmp_proc(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


}

bmp_proc::~bmp_proc()
{

}

void bmp_proc::open_file(void){

	//ui.fileDialog->open();
	
	QString str = ui.fileDialog->getOpenFileName(0, "Open Dialog", "", "*.bmp *.jpg");
	std::ifstream in_file;
	in_file.open(str.toStdString(), std::ios_base::binary);

	BitMapClass bmPlane(in_file);

	QGraphicsScene *gS = new QGraphicsScene();

	for (int i = 0; i < bmPlane.getY(); i++){
		for (int j = 0; j < bmPlane.getX(); j++){
			QPen *qp = new QPen(QColor(bmPlane.getPlane()->at(j).at(i)->R, bmPlane.getPlane()->at(j).at(i)->G, bmPlane.getPlane()->at(j).at(i)->B));
			//QPen *qp = new QPen(Qt::black);

			gS->addEllipse(j, i, 1, 1, *qp);
		}
	}
	
	
	ui.grViewer->setScene(gS);
	ui.grViewer->show();
	


}
