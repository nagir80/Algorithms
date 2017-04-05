/********************************************************************************
** Form generated from reading UI file 'signal_visualisator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNAL_VISUALISATOR_H
#define UI_SIGNAL_VISUALISATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qtgraphplane.h";

QT_BEGIN_NAMESPACE

class Ui_signal_visualisatorClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_4;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *signal_visualisatorClass)
    {
        if (signal_visualisatorClass->objectName().isEmpty())
            signal_visualisatorClass->setObjectName(QStringLiteral("signal_visualisatorClass"));
        signal_visualisatorClass->resize(1112, 858);
        centralWidget = new QWidget(signal_visualisatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 1091, 798));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
//        graphicsView = new QGraphicsView(verticalLayoutWidget);
		graphicsView = new QTGraphPlane(verticalLayoutWidget);
	

        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

		graphicsView_3 = new QTGraphPlane(verticalLayoutWidget);
		
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));

        gridLayout->addWidget(graphicsView_3, 2, 0, 1, 1);

		graphicsView_2 = new QTGraphPlane(verticalLayoutWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));

        gridLayout->addWidget(graphicsView_2, 0, 1, 1, 1);

		graphicsView_4 = new QTGraphPlane(verticalLayoutWidget);
        graphicsView_4->setObjectName(QStringLiteral("graphicsView_4"));

        gridLayout->addWidget(graphicsView_4, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        textEdit_2 = new QTextEdit(verticalLayoutWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout_2->addWidget(textEdit_2, 0, 1, 1, 1);

        textEdit_3 = new QTextEdit(verticalLayoutWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));

        gridLayout_2->addWidget(textEdit_3, 0, 2, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 2);
        gridLayout_2->setColumnStretch(0, 3);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);

        verticalLayout->addLayout(gridLayout_2);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 1);
        signal_visualisatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(signal_visualisatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1112, 21));
        signal_visualisatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(signal_visualisatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        signal_visualisatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(signal_visualisatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        signal_visualisatorClass->setStatusBar(statusBar);

		
        retranslateUi(signal_visualisatorClass);

        QMetaObject::connectSlotsByName(signal_visualisatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *signal_visualisatorClass)
    {
        signal_visualisatorClass->setWindowTitle(QApplication::translate("signal_visualisatorClass", "signal_visualisator", 0));
        pushButton->setText(QApplication::translate("signal_visualisatorClass", "\320\241\320\242\320\220\320\240\320\242", 0));
    } // retranslateUi

};

namespace Ui {
    class signal_visualisatorClass: public Ui_signal_visualisatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNAL_VISUALISATOR_H
