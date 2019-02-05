#include "stdafx.h"
#include "ExerciseSet.h"


ExerciseSet::ExerciseSet()
{
}

void ExerciseSet::setName(QString name)
{
	this->name = name;
}

QString ExerciseSet::getName()
{
	return this->name;
}

void ExerciseSet::addExercise(Exercise * exercise)
{
	this->list.append(exercise);
	this->answerList.append(new UserAnswer());
}

void ExerciseSet::setAnswer(UserAnswer answer,int index)
{
	this->answerList.at(index)->setAnswer(answer.getAnswer());
	this->answerList.at(index)->setType(answer.getType());
}

QList<Exercise*> ExerciseSet::getExercise()
{
	return this->list;
}

QList<UserAnswer*> ExerciseSet::getAnswers()
{
	return this->answerList;
}


ExerciseSet::~ExerciseSet()
{
	for (int i = 0; i < this->list.size(); i++)
	{
		delete this->list.at(i);
		delete this->answerList.at(0);
	}
}
