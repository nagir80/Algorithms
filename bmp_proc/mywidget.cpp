#include "mywidget.h"

MyWidget::MyWidget(QMap<int, BitMapClass*>* ref, int it_bitmap, QWidget *parent) :collection(ref), it_bitmap(it_bitmap),
	 QWidget(parent)
{

	ui.setupUi(this);
}

MyWidget::~MyWidget()
{
	//delete inside_bitmap;
	

}


void MyWidget::paintEvent(QPaintEvent *event){
	QPainter painter(this);
	QImage *image;
	
	BitMapClass * inside_bitmap = *collection->find(it_bitmap);
	if (inside_bitmap != NULL){
		
		image = new QImage(inside_bitmap->getX(), inside_bitmap->getY(), QImage::Format_RGB32);
		for (int i = 0; i < inside_bitmap->getY(); i++){
			for (int j = 0; j < inside_bitmap->getX(); j++){
				//	int mid = (bmPlane->getPlane()->at(i).at(j)->R + bmPlane->getPlane()->at(i).at(j)->G + bmPlane->getPlane()->at(i).at(j)->B) / 3;
				image->setPixel(j, inside_bitmap->getY()-1-i, qRgb(inside_bitmap->getPlane()->at(i).at(j)->R, inside_bitmap->getPlane()->at(i).at(j)->G, inside_bitmap->getPlane()->at(i).at(j)->B));
			}
		}
		painter.drawImage(20, 20, *image);
	}

}

void MyWidget::closeEvent(QCloseEvent * event){
	
	collection->erase(collection->find(it_bitmap));
}