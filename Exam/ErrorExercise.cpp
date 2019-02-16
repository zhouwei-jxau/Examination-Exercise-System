#include "stdafx.h"
#include "ErrorExercise.h"


ErrorExercise::ErrorExercise()
{
}

void ErrorExercise::setExercise(Exercise * exercise)
{
	this->exercise = exercise;
}

Exercise * ErrorExercise::getExercise()
{
	return this->exercise;
}

void ErrorExercise::setMark(QString mark)
{
	this->mark = mark;
}

QString ErrorExercise::getMark()
{
	return this->mark;
}


ErrorExercise::~ErrorExercise()
{
}
