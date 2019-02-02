#pragma once
#include <Exercise.h>
class ExerciseSet
{
public:
	ExerciseSet();
	void setName(QString name);
	QString getName();
	void addExercise(Exercise* exercise);
	QList<Exercise*> getExercise();
	~ExerciseSet();
private:
	QString name;
	QList<Exercise*> list;
};

