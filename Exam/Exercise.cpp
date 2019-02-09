#include "stdafx.h"
#include "Exercise.h"


Exercise::Exercise()
{
}

void Exercise::setSubject(QString subject)
{
	this->subject = subject;
}

QString Exercise::getSubject()
{
	return this->subject;
}

void Exercise::setAnswer(QString answer)
{
	this->answer = answer;
}

QString Exercise::getAnswer()
{
	return this->answer;
}

void Exercise::setType(ExerciseType type)
{
	this->type = type;
}

Exercise::ExerciseType Exercise::getType()
{
	return this->type;
}

void Exercise::setExerciseNo(int no)
{
	this->no = no;
}


int Exercise::getExerciseNo()
{
	return this->no;
}

Exercise::~Exercise()
{
}
