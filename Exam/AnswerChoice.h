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
	void setAnswer(QVariant answer);
	QVariant getAnswer();
	~AnswerChoice();
private slots:
	void slotRadioButtonChecked(QAbstractButton *button);
private:
	QButtonGroup* group;
	QListWidget* listWidget;
	QList<QRadioButton*> buttons;
	QHash<QRadioButton*, int> options;
};

