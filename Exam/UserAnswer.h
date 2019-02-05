#pragma once
#include<Exercise.h>
class UserAnswer
{
public:
	UserAnswer();
	QVariant getAnswer();
	void setAnswer(QVariant answer);
	Exercise::ExerciseType getType();
	void setType(Exercise::ExerciseType type);
	bool isAnswered();
	~UserAnswer();
private:
	Exercise::ExerciseType exerciseType;
	QVariant answer;
	bool answered;
};

