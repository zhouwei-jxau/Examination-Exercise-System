#pragma once
#include<Exercise.h>
class UserAnswer
{
public:
	friend class CheckAnswers;
	UserAnswer();
	QVariant getAnswer();
	void setAnswer(QVariant answer);
	Exercise::ExerciseType getType();
	void setType(Exercise::ExerciseType type);
	bool isAnswered();
	bool isMarked();
	bool isRight();
	bool isHalf();
	void setMarked(bool flag);
	~UserAnswer();
private:
	Exercise::ExerciseType exerciseType;
	QVariant answer;
	bool answered;
	bool flag;
	bool right;
	bool half;
};

