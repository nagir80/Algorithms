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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

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

        retranslateUi(bmp_procClass);

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
