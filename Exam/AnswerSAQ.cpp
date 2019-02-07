#include "stdafx.h"
#include "AnswerSAQ.h"


AnswerSAQ::AnswerSAQ()
{
	this->type = Exercise::ExerciseType::SAQ;
	this->setLayout(new QVBoxLayout());
	this->textedit = new QTextEdit();
	this->layout()->addWidget(this->textedit);
}

QVariant AnswerSAQ::getAnswer()
{
	return QVariant(static_cast<QTextEdit*>(this->children().at(1))->toPlainText());
}

void AnswerSAQ::setEditable(bool enable)
{
	this->textedit->setEnabled(enable);
}

void AnswerSAQ::setAnswer(QString answer)
{
	this->textedit->setText(answer);
}


AnswerSAQ::~AnswerSAQ()
{
}
