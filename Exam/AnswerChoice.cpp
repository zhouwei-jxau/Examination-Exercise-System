#include "stdafx.h"
#include "AnswerChoice.h"


AnswerChoice::AnswerChoice()
{
	this->group = new QButtonGroup();
	this->listWidget = new QListWidget();
	this->setLayout(new QHBoxLayout());
	this->layout()->addWidget(this->listWidget);
}

void AnswerChoice::fill(QList<QString> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		QWidget* w = new QWidget();
		w->setLayout(new QHBoxLayout());
		QRadioButton* radioButton = new QRadioButton();
		options.insert(radioButton, 'A' + i);
		radioButton->setFixedWidth(20);
		this->group->addButton(radioButton);
		QLabel* label = new QLabel();
		label->setText(list.at(i));
		w->layout()->addWidget(radioButton);
		w->layout()->addWidget(label);
		QListWidgetItem* item=new QListWidgetItem();
		item->setSizeHint(QSize(this->width(), 42));
		this->listWidget->addItem(item);
		this->listWidget->setItemWidget(item, w);
	}
}

QVariant AnswerChoice::getAnswer()
{
	QRadioButton* button=(QRadioButton*)this->group->checkedButton();
	QVariant var;
	var = QVariant::fromValue<QString>(QString((char)this->options.value(button)));
	return var;
}


AnswerChoice::~AnswerChoice()
{
	this->group->deleteLater();
}
