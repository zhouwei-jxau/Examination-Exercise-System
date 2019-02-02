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
}

QList<Exercise*> ExerciseSet::getExercise()
{
	return this->list;
}


ExerciseSet::~ExerciseSet()
{
}
