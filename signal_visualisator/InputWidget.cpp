#include "InputWidget.h"

InputWidget::InputWidget(QWidget *parent = 0){

	horizontalLayoutWidget = new QWidget(parent);
	horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
	horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
	horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
	horizontalLayout->setContentsMargins(0, 0, 0, 0);
	plainTextEdit = new QPlainTextEdit(horizontalLayoutWidget);
	plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

	horizontalLayout->addWidget(plainTextEdit);

	plainTextEdit_2 = new QPlainTextEdit(horizontalLayoutWidget);
	plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));

	horizontalLayout->addWidget(plainTextEdit_2);

	plainTextEdit_3 = new QPlainTextEdit(horizontalLayoutWidget);
	plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));

	horizontalLayout->addWidget(plainTextEdit_3);

	plainTextEdit_4 = new QPlainTextEdit(horizontalLayoutWidget);
	plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));

	horizontalLayout->addWidget(plainTextEdit_4);

}