#pragma once
#include "Answer.h"
class AnswerChoice :
	public Answer
{
public:
	AnswerChoice();
	void fill(QList<QString> list);
	QVariant getAnswer();
	~AnswerChoice();
private:
	QButtonGroup* group;
	QListWidget* listWidget;
	QHash<QRadioButton*, int> options;
};

