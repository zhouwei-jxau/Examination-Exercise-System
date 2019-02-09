#pragma once
#include "Answer.h"
class AnswerJudge :
	public Answer
{
	Q_OBJECT
public:
	AnswerJudge();
	QVariant getAnswer();
	void setEditable(bool enable);
	void setAnswer(QString answer);
	void setAnswer(QVariant answer);
	~AnswerJudge();
private slots:
	void slotRadioButtonChecked();
private:
	QButtonGroup* group;
	QRadioButton* radioButtonCorrect;
	QRadioButton* radioButtonError;
};

