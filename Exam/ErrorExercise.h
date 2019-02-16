#pragma once
#include <Exercise.h>
class ErrorExercise
{
public:
	ErrorExercise();
	void setExercise(Exercise* exercise);
	Exercise* getExercise();
	void setMark(QString mark);
	QString getMark();
	~ErrorExercise();
private:
	Exercise* exercise;
	QString mark;
};

