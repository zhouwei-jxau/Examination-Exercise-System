#pragma once
#include "Answer.h"
class AnswerJudge :
	public Answer
{
public:
	AnswerJudge();
	QVariant getAnswer();
	~AnswerJudge();
private:
	QButtonGroup* group;
	QRadioButton* radioButtonCorrect;
	QRadioButton* radioButtonError;
};

