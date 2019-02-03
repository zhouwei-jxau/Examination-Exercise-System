#include "stdafx.h"
#include "AnswerFillInTheBlanks.h"


AnswerFillInTheBlanks::AnswerFillInTheBlanks()
{
	this->setLayout(new QVBoxLayout());
	this->listWidget = new QListWidget();
	this->layout()->addWidget(this->listWidget);
}

void AnswerFillInTheBlanks::setNumberOfBlanks(int numOfBlanks)
{
	this->listWidget->clear();
	for (int i = 0; i < numOfBlanks; i++)
	{
		QWidget* w=new QWidget();
		w->setLayout(new QVBoxLayout());
		w->layout()->addWidget(new QTextEdit());
		w->setFixedHeight(120);
		QListWidgetItem* item = new QListWidgetItem();
		item->setSizeHint(QSize(this->width(), 240));
		this->listWidget->addItem(item);
		this->listWidget->setItemWidget(item, w);
	}
	this->numOfBlanks = numOfBlanks;
}

QVariant AnswerFillInTheBlanks::getAnswer()
{
	QList<QString> list;
	for (int i = 0; i < this->listWidget->count(); i++)
	{
		QTextEdit* textEdit = static_cast<QTextEdit*>(this->listWidget->itemWidget(this->listWidget->item(i))->children().at(1));
		list.append(textEdit->toPlainText());
	}
	return QVariant::fromValue<QList<QString>>(list);
}

int AnswerFillInTheBlanks::getNumberOfBlanks()
{
	return this->numOfBlanks;
}


AnswerFillInTheBlanks::~AnswerFillInTheBlanks()
{
}
