#pragma once
#include "Answer.h"
class AnswerChoice :
	public Answer
{
	Q_OBJECT
public:
	AnswerChoice();
	void fill(QList<QString> list);
	void setEditable(bool enable);
	void setAnswer(QString answer);
	QVariant getAnswer();
	~AnswerChoice();
private slots:
	void slotRadioButtonChecked(QAbstractButton *button);
private:
	QButtonGroup* group;
	QListWidget* listWidget;
	QHash<QRadioButton*, int> options;
};

