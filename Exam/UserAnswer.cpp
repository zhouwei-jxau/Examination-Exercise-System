#include "stdafx.h"
#include "UserAnswer.h"


UserAnswer::UserAnswer()
{
	this->answered = false;
}

QVariant UserAnswer::getAnswer()
{
	return this->answer;
}

void UserAnswer::setAnswer(QVariant answer)
{
	this->answer = answer;
	this->answered = true;
}

Exercise::ExerciseType UserAnswer::getType()
{
	return this->exerciseType;
}

void UserAnswer::setType(Exercise::ExerciseType type)
{
	this->exerciseType = type;
}

bool UserAnswer::isAnswered()
{
	return this->answered;
}


UserAnswer::~UserAnswer()
{
}
