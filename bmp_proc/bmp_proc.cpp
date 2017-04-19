#include "bmp_proc.h"


bmp_proc::bmp_proc(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	num_key = 0;
	setWindowFlags(Qt::Window  | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

}

bmp_proc::~bmp_proc()
{
	
}

void bmp_proc::closeEvent(QCloseEvent * event){

	
}

void bmp_proc::paintEvent(QPaintEvent *event){

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
	graph->setMinimumHeight(50);
	
	graph->setFont(QFont("Times", 20, QFont::Bold));
	graph->setText("Graph ");
	ui.vLayout->addWidget(graph);
	
	ui.layoutWidget->adjustSize();
	

}
