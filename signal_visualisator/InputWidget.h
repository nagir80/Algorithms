#ifndef INPUT_WIDGET_H
#define INPUT_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>

class InputWidget : public QWidget
{
	Q_OBJECT

public:
	InputWidget(QWidget *parent = 0);
	~InputWidget();

	
private:
	QWidget *horizontalLayoutWidget;
	QHBoxLayout *horizontalLayout;
	QPlainTextEdit *plainTextEdit;
	QPlainTextEdit *plainTextEdit_2;
	QPlainTextEdit *plainTextEdit_3;
	QPlainTextEdit *plainTextEdit_4;
};

#endif // SIGNAL_VISUALISATOR_H
