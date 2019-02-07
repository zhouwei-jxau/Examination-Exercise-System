#include "stdafx.h"
#include "AnswerJudge.h"


AnswerJudge::AnswerJudge()
{
	this->type = Exercise::ExerciseType::Judge;
	this->group = new QButtonGroup();
	this->radioButtonCorrect = new QRadioButton();
	this->radioButtonCorrect->setText(QString::fromLocal8Bit("��"));
	this->radioButtonError = new QRadioButton();
	this->radioButtonError->setText(QString::fromLocal8Bit("��"));
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
	if (answer == "true")
	{
		this->radioButtonCorrect->setChecked(true);
	}
	else
	{
		this->radioButtonError->setChecked(true);
	}
}


AnswerJudge::~AnswerJudge()
{
}
