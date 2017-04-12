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
	

}
