#pragma once
#include "Answer.h"
class AnswerChoice :
	public Answer
{
	Q_OBJECT
public:
	AnswerChoice();
	void fill(QList<QString> list);
	QVariant getAnswer();
	~AnswerChoice();
private slots:
	void slotRadioButtonChecked(QAbstractButton *button);
private:
	QButtonGroup* group;
	QListWidget* listWidget;
	QHash<QRadioButton*, int> options;
};

