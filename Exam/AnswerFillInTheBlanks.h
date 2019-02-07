#pragma once
#include "Answer.h"
class AnswerFillInTheBlanks :
	public Answer
{
public:
	AnswerFillInTheBlanks();
	void setNumberOfBlanks(int numOfBlanks);
	void setEditable(bool enable);
	void setAnswer(QString answer);
	QVariant getAnswer();
	int getNumberOfBlanks();
	~AnswerFillInTheBlanks();
private:
	int numOfBlanks;
	QListWidget* listWidget;
	QList<QTextEdit*> textedits;
};

