#pragma once
#include "Answer.h"
class AnswerSAQ :
	public Answer
{
	Q_OBJECT
public:
	AnswerSAQ();
	QVariant getAnswer();
	void setEditable(bool enable);
	void setAnswer(QString answer);
	void setAnswer(QVariant answer);
	~AnswerSAQ();
private slots:
	void slotTextChanged();
private:
	QTextEdit* textedit;
};

