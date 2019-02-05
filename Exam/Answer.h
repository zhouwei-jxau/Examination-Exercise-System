#pragma once
#include <qframe.h>
#include <Exercise.h>
class Answer :
	public QFrame
{
	Q_OBJECT
public:
	Answer();
	virtual QVariant getAnswer()=0;
	Exercise::ExerciseType getType();
	~Answer();
protected:
	Exercise::ExerciseType type;
signals:
	void signalUserAnswered();
};

