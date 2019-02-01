#include "stdafx.h"
#include "AnswerSAQ.h"


AnswerSAQ::AnswerSAQ()
{
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
