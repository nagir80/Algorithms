/********************************************************************************
** Form generated from reading UI file 'qml_cpp_test.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QML_CPP_TEST_H
#define UI_QML_CPP_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QDeclarativeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QQuickView>
QT_BEGIN_NAMESPACE

class Ui_qml_cpp_testClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;
	QDeclarativeView* pv;
	QVBoxLayout* pvbx;
	QQuickView* view;

    void setupUi(QMainWindow *qml_cpp_testClass)
    {
        

	
		

		

		
		if (qml_cpp_testClass->objectName().isEmpty())
            qml_cpp_testClass->setObjectName(QStringLiteral("qml_cpp_testClass"));
        qml_cpp_testClass->resize(600, 400);
 
		
		menuBar = new QMenuBar(qml_cpp_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        qml_cpp_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qml_cpp_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qml_cpp_testClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(qml_cpp_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qml_cpp_testClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qml_cpp_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qml_cpp_testClass->setStatusBar(statusBar);

        retranslateUi(qml_cpp_testClass);

        QMetaObject::connectSlotsByName(qml_cpp_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *qml_cpp_testClass)
    {
        qml_cpp_testClass->setWindowTitle(QApplication::translate("qml_cpp_testClass", "qml_cpp_test", 0));
    } // retranslateUi

};

namespace Ui {
    class qml_cpp_testClass: public Ui_qml_cpp_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QML_CPP_TEST_H
