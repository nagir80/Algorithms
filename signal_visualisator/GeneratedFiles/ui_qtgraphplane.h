/********************************************************************************
** Form generated from reading UI file 'qtgraphplane.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGRAPHPLANE_H
#define UI_QTGRAPHPLANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_QTGraphPlane
{
public:

    void setupUi(QGraphicsView *QTGraphPlane)
    {
        if (QTGraphPlane->objectName().isEmpty())
            QTGraphPlane->setObjectName(QStringLiteral("QTGraphPlane"));
        QTGraphPlane->resize(400, 300);

        retranslateUi(QTGraphPlane);

        QMetaObject::connectSlotsByName(QTGraphPlane);
    } // setupUi

    void retranslateUi(QGraphicsView *QTGraphPlane)
    {
        QTGraphPlane->setWindowTitle(QApplication::translate("QTGraphPlane", "QTGraphPlane", 0));
    } // retranslateUi

};

namespace Ui {
    class QTGraphPlane: public Ui_QTGraphPlane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGRAPHPLANE_H
