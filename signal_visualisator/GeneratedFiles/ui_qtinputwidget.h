/********************************************************************************
** Form generated from reading UI file 'qtinputwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTINPUTWIDGET_H
#define UI_QTINPUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTInputWidgetClass
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;

    void setupUi(QWidget *QTInputWidgetClass)
    {
        if (QTInputWidgetClass->objectName().isEmpty())
            QTInputWidgetClass->setObjectName(QStringLiteral("QTInputWidgetClass"));
        QTInputWidgetClass->resize(600, 400);
        horizontalLayoutWidget = new QWidget(QTInputWidgetClass);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 110, 471, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(horizontalLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        plainTextEdit_2 = new QPlainTextEdit(horizontalLayoutWidget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));

        horizontalLayout->addWidget(plainTextEdit_2);


        retranslateUi(QTInputWidgetClass);

        QMetaObject::connectSlotsByName(QTInputWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *QTInputWidgetClass)
    {
        QTInputWidgetClass->setWindowTitle(QApplication::translate("QTInputWidgetClass", "QTInputWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class QTInputWidgetClass: public Ui_QTInputWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTINPUTWIDGET_H
