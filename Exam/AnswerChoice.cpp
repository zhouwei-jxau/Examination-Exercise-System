#include "stdafx.h"
#include "AnswerChoice.h"


AnswerChoice::AnswerChoice()
{
	this->type = Exercise::ExerciseType::Choice;
	this->group = new QButtonGroup();
	this->listWidget = new QListWidget();
	this->setLayout(new QHBoxLayout());
	this->layout()->addWidget(this->listWidget);

	connect(this->group, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(slotRadioButtonChecked(QAbstractButton*)));
}

void AnswerChoice::fill(QList<QString> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		QWidget* w = new QWidget();
		w->setLayout(new QHBoxLayout());
		QRadioButton* radioButton = new QRadioButton();
		buttons.append(radioButton);
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

void AnswerChoice::setEditable(bool enable)
{
	QList<QRadioButton*> radioButtons = options.keys();
	for (int i = 0; i < radioButtons.size(); i++)
	{
		radioButtons.at(i)->setEnabled(enable);
	}
}

void AnswerChoice::setAnswer(QString answer)
{
	if (answer == "")
		return;
	QList<QRadioButton*> radioButtons = options.keys();
	char ans = *answer.toLocal8Bit().toStdString().c_str();
	buttons.at(ans - 'A')->setChecked(true);
}

void AnswerChoice::setAnswer(QVariant answer)
{
	QString tAnswer = answer.value<QString>();
	if (tAnswer == "")
		return;
	this->setAnswer(tAnswer);
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

void AnswerChoice::slotRadioButtonChecked(QAbstractButton *button)
{
	this->answered = true;
	emit this->signalUserAnswered();
}
