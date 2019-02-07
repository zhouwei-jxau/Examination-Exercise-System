#pragma once
#include "Answer.h"
class AnswerSAQ :
	public Answer
{
public:
	AnswerSAQ();
	QVariant getAnswer();
	void setEditable(bool enable);
	void setAnswer(QString answer);
	~AnswerSAQ();
private:
	QTextEdit* textedit;
};

