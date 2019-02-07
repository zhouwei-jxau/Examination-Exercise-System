#pragma once
#include "Answer.h"
class AnswerJudge :
	public Answer
{
public:
	AnswerJudge();
	QVariant getAnswer();
	void setEditable(bool enable);
	void setAnswer(QString answer);
	~AnswerJudge();
private:
	QButtonGroup* group;
	QRadioButton* radioButtonCorrect;
	QRadioButton* radioButtonError;
};

