/********************************************************************************
** Form generated from reading UI file 'bmp_proc.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BMP_PROC_H
#define UI_BMP_PROC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QTWidgets/QVBoxLayout>
#include <QImage>
#include <QPainter>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QLabel>

#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bmp_procClass
{
public:
	QAction *actionOpen;
	QAction *actionExit;
	QWidget *centralWidget;
	QMenuBar *menuBar;
	QMenu *menuSadsda;
	QVBoxLayout *vLayout;
	QWidget *layoutWidget;
	QToolBar *mainToolBar;
	QStatusBar *statusBar;
	QScrollArea *scrollArea;
	QFileDialog *fileDialog;
	QGraphicsView *grViewer;
	QImage  image;
	QPainter *painter;

	void setupUi(QMainWindow *bmp_procClass)
	{
		if (bmp_procClass->objectName().isEmpty())
			bmp_procClass->setObjectName(QStringLiteral("bmp_procClass"));
		bmp_procClass->resize(600, 400);
		actionOpen = new QAction(bmp_procClass);
		actionOpen->setObjectName(QStringLiteral("actionOpen"));
		actionExit = new QAction(bmp_procClass);
		actionExit->setObjectName(QStringLiteral("actionExit"));
		centralWidget = new QWidget(bmp_procClass);
		centralWidget->setObjectName(QStringLiteral("centralWidget"));
		bmp_procClass->setCentralWidget(centralWidget);
/////////////////////////////////////////////////////////////////////
//		QLabel *label1 = new QLabel("Label1");
//		QLabel *label2 = new QLabel("Label2");
//		QLabel *label3 = new QLabel("Label3");
//		QLabel *label4 = new QLabel("Label1");
//		QLabel *label5 = new QLabel("Label2");
//		QLabel *label6 = new QLabel("Label3");
		scrollArea = new QScrollArea(centralWidget);
		scrollArea->setAlignment(Qt::AlignBottom);

		layoutWidget = new QWidget();
		
		vLayout = new QVBoxLayout();
		vLayout->setMargin(5);
		vLayout->setSpacing(5);
		
		layoutWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
		layoutWidget->setLayout(vLayout);

		scrollArea->setGeometry(100, 50, 400, 100);
		scrollArea->setWidget(layoutWidget);

/*		vLayout->addWidget(label1);
		vLayout->addWidget(label2);
		vLayout->addWidget(label3);
		vLayout->addWidget(label4);
		vLayout->addWidget(label5);
		vLayout->addWidget(label6);

		layoutWidget->adjustSize();
	*/	
////////////////////////////////////////////////////////////////////
		menuBar = new QMenuBar(bmp_procClass);
		menuBar->setObjectName(QStringLiteral("menuBar"));
		menuBar->setGeometry(QRect(0, 0, 600, 21));
		menuSadsda = new QMenu(menuBar);
		menuSadsda->setObjectName(QStringLiteral("menuSadsda"));
		bmp_procClass->setMenuBar(menuBar);
		mainToolBar = new QToolBar(bmp_procClass);
		mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
		bmp_procClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
		statusBar = new QStatusBar(bmp_procClass);
		statusBar->setObjectName(QStringLiteral("statusBar"));
		bmp_procClass->setStatusBar(statusBar);

		menuBar->addAction(menuSadsda->menuAction());
		menuSadsda->addAction(actionOpen);
		menuSadsda->addSeparator();
		menuSadsda->addAction(actionExit);

		fileDialog = new QFileDialog(0, "File Open", 0, "*.bmp *.jpg");


//		grViewer = new QGraphicsView(bmp_procClass);
//		grViewer->setAlignment(Qt::AlignCenter);
//		grViewer->setGeometry(10, 40, bmp_procClass->width() - 20, bmp_procClass->height() - 80);

		
		
		retranslateUi(bmp_procClass);

		QObject::connect(actionOpen, SIGNAL(triggered()), bmp_procClass, SLOT(open_file()));
		QObject::connect(actionExit, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));

        QMetaObject::connectSlotsByName(bmp_procClass);
    } // setupUi

    void retranslateUi(QMainWindow *bmp_procClass)
    {
        bmp_procClass->setWindowTitle(QApplication::translate("bmp_procClass", "bmp_proc", 0));
        actionOpen->setText(QApplication::translate("bmp_procClass", "Open...", 0));
        actionExit->setText(QApplication::translate("bmp_procClass", "Exit", 0));
        menuSadsda->setTitle(QApplication::translate("bmp_procClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class bmp_procClass: public Ui_bmp_procClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BMP_PROC_H
