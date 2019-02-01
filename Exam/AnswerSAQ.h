#pragma once
#include "Answer.h"
class AnswerSAQ :
	public Answer
{
public:
	AnswerSAQ();
	QVariant getAnswer();
	~AnswerSAQ();
};

