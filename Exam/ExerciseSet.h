#pragma once
#include <Exercise.h>
#include <UserAnswer.h>
class ExerciseSet
{
public:
	ExerciseSet();
	void setName(QString name);
	QString getName();
	void addExercise(Exercise* exercise);
	void setAnswer(UserAnswer answer,int index);
	QList<Exercise*> getExercise();
	QList<UserAnswer*> getAnswers();
	~ExerciseSet();
private:
	QString name;
	QList<Exercise*> list;
	QList<UserAnswer*> answerList;
};

