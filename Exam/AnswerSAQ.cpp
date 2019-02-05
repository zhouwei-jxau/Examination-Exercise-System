#include "stdafx.h"
#include "AnswerSAQ.h"


AnswerSAQ::AnswerSAQ()
{
	this->type = Exercise::ExerciseType::SAQ;
	this->setLayout(new QVBoxLayout());
	this->layout()->addWidget(new QTextEdit());
}

QVariant AnswerSAQ::getAnswer()
{
	return QVariant(static_cast<QTextEdit*>(this->children().at(1))->toPlainText());
}


AnswerSAQ::~AnswerSAQ()
{
}
