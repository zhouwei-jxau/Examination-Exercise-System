#pragma once
#include "Answer.h"
class AnswerFillInTheBlanks :
	public Answer
{
public:
	AnswerFillInTheBlanks();
	void setNumberOfBlanks(int numOfBlanks);
	QVariant getAnswer();
	int getNumberOfBlanks();
	~AnswerFillInTheBlanks();
private:
	int numOfBlanks;
	QListWidget* listWidget;
};

