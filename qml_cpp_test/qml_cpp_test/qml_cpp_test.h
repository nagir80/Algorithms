#ifndef QML_CPP_TEST_H
#define QML_CPP_TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_qml_cpp_test.h"

class qml_cpp_test : public QMainWindow
{
	Q_OBJECT

public:
	qml_cpp_test(QWidget *parent = 0);
	~qml_cpp_test();

private:
	Ui::qml_cpp_testClass ui;
};

#endif // QML_CPP_TEST_H
