#include "stdafx.h"
#include "UserAnswer.h"


UserAnswer::UserAnswer()
{
	this->answered = false;
	this->flag = false;
	this->right = false;
	this->half = false;
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

bool UserAnswer::isMarked()
{
	return this->flag;
}

bool UserAnswer::isRight()
{
	return this->right;
}

bool UserAnswer::isHalf()
{
	return this->half;
}

void UserAnswer::setMarked(bool flag)
{
	this->flag = flag;
}


UserAnswer::~UserAnswer()
{
}
