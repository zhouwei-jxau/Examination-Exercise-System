#include "stdafx.h"
#include "AnswerJudge.h"


AnswerJudge::AnswerJudge()
{
	this->type = Exercise::ExerciseType::Judge;
	this->group = new QButtonGroup();
	this->radioButtonCorrect = new QRadioButton();
	connect(this->radioButtonCorrect, SIGNAL(clicked()), this, SLOT(slotRadioButtonChecked()));
	this->radioButtonCorrect->setText(QString::fromLocal8Bit("ÊÇ"));
	this->radioButtonError = new QRadioButton();
	connect(this->radioButtonError, SIGNAL(clicked()), this, SLOT(slotRadioButtonChecked()));
	this->radioButtonError->setText(QString::fromLocal8Bit("·ñ"));
	this->setLayout(new QHBoxLayout());
	this->layout()->addWidget(this->radioButtonCorrect);
	this->layout()->addWidget(this->radioButtonError);
	this->layout()->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

QVariant AnswerJudge::getAnswer()
{
	bool isCorrect = false;
	if (this->radioButtonCorrect->isChecked())
	{
		isCorrect = true;
	}
	return QVariant(isCorrect);
}

void AnswerJudge::setEditable(bool enable)
{
	radioButtonCorrect->setEnabled(enable);
	radioButtonError->setEnabled(enable);
}

void AnswerJudge::setAnswer(QString answer)
{
	if (answer == "")
		return;
	if (answer == "true")
	{
		this->radioButtonCorrect->setChecked(true);
	}
	else
	{
		this->radioButtonError->setChecked(true);
	}
}

void AnswerJudge::setAnswer(QVariant answer)
{
	QString tAnswer = answer.value<QString>();
	if (tAnswer == "")
		return;
	this->setAnswer(tAnswer);
}


AnswerJudge::~AnswerJudge()
{
}

void AnswerJudge::slotRadioButtonChecked()
{
	this->answered = true;
	emit this->signalUserAnswered();
}
