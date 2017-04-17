#include "bmp_proc.h"

bmp_proc::bmp_proc(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	num_key = 0;


}

bmp_proc::~bmp_proc()
{
	
}

void bmp_proc::closeEvent(QCloseEvent * event){
//	bmPlane.clear();
	
}

void bmp_proc::paintEvent(QPaintEvent *event){
//	QPainter painter(this);
/*	QImage *image;
	if (bmPlane != NULL){
		image = new QImage(bmPlane->getX(), bmPlane->getY(), QImage::Format_RGB32);
		for (int i = 0; i < bmPlane->getY(); i++){
			for (int j = 0; j < bmPlane->getX(); j++){
			//	int mid = (bmPlane->getPlane()->at(i).at(j)->R + bmPlane->getPlane()->at(i).at(j)->G + bmPlane->getPlane()->at(i).at(j)->B) / 3;
				image->setPixel(j, i, qRgb(bmPlane->getPlane()->at(i).at(j)->R, bmPlane->getPlane()->at(i).at(j)->G, bmPlane->getPlane()->at(i).at(j)->B));
			}
		}
		painter.drawImage(50, 50, *image);
	}
	
	*/

}

void bmp_proc::open_file(void){

	//ui.fileDialog->open();
	QString str = ui.fileDialog->getOpenFileName(0, "Open Dialog", "", "*.bmp *.jpg");
	std::ifstream in_file;
	in_file.open(str.toStdString(), std::ios_base::binary);
	BitMapClass *bmPlane_inst;
	bmPlane_inst = new BitMapClass(in_file);

	//bmPlane.append(bmPlane_inst);
	bmPlane.insert(num_key, bmPlane_inst);
	MyWidget *myWidget = new MyWidget(&bmPlane, num_key);
	num_key++;
	myWidget->setGeometry(10, 10, bmPlane_inst->getX() + 50, bmPlane_inst->getY() + 50);

	myWidget->show();
	QLabel *graph = new QLabel();
	graph->setMinimumHeight(20);
	graph->setText("graph ");
	ui.vLayout->setSpacing(10);
	ui.vLayout->addWidget(graph);


	//ui.layoutWidget->adjustSize();
	
	
	


/*	QGraphicsScene *gS = new QGraphicsScene();

	for (int i = 0; i < bmPlane.getY(); i++){
		for (int j = 0; j < bmPlane.getX(); j++){
			QPen *qp = new QPen(QColor(bmPlane.getPlane()->at(j).at(i)->R, bmPlane.getPlane()->at(j).at(i)->G, bmPlane.getPlane()->at(j).at(i)->B));
			//QPen *qp = new QPen(Qt::black);

			gS->addEllipse(j, i, 1, 1, *qp);
		}
	}
	
	
	ui.grViewer->setScene(gS);
	ui.grViewer->show();
*/	


}
