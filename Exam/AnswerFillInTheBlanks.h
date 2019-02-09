#pragma once
#include "Answer.h"
class AnswerFillInTheBlanks :
	public Answer
{
	Q_OBJECT
public:
	AnswerFillInTheBlanks();
	void setNumberOfBlanks(int numOfBlanks);
	void setEditable(bool enable);
	void setAnswer(QString answer);
	void setAnswer(QVariant answer);
	QVariant getAnswer();
	int getNumberOfBlanks();
	~AnswerFillInTheBlanks();
private slots:
	void slotTextChanged();
private:
	int numOfBlanks;
	QListWidget* listWidget;
	QList<QTextEdit*> textedits;
};

