#pragma once
#include <qframe.h>
#include <Exercise.h>
class Answer :
	public QFrame
{
	Q_OBJECT
public:
	Answer();
	bool isAnswered();
	virtual QVariant getAnswer()=0;
	virtual void setEditable(bool enble)=0;
	virtual void setAnswer(QString answer) = 0;
	virtual void setAnswer(QVariant answer) = 0;
	Exercise::ExerciseType getType();
	~Answer();
protected:
	Exercise::ExerciseType type;
	bool answered;
signals:
	void signalUserAnswered();
private:
};

