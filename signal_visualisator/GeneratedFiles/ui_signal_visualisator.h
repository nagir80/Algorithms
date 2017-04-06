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
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_signal_visualisatorClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QCustomPlot *widget;
    QCustomPlot *widget_2;
    QCustomPlot *widget_3;
    QCustomPlot *widget_4;
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
        signal_visualisatorClass->resize(1117, 873);
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
        widget = new QCustomPlot(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget, 0, 1, 1, 1);

        widget_2 = new QCustomPlot(verticalLayoutWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget_2, 2, 0, 1, 1);

        widget_3 = new QCustomPlot(verticalLayoutWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget_3, 2, 1, 1, 1);

        widget_4 = new QCustomPlot(verticalLayoutWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget_4, 0, 0, 1, 1);


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
        menuBar->setGeometry(QRect(0, 0, 1117, 21));
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
