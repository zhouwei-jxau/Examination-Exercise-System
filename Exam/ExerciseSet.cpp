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

void ExerciseSet::setMarkOfChoice(int mark)
{
	this->markOfChoice = mark;
}

int ExerciseSet::getMarkOfChoice()
{
	return this->markOfChoice;
}

void ExerciseSet::setMarkOfJudge(int mark)
{
	this->markOfJudge = mark;
}

int ExerciseSet::getMarkOfJudge()
{
	return this->markOfJudge;
}

void ExerciseSet::setMarkOfFillInTheBlanks(int mark)
{
	this->markOfFillInTheBlanks = mark;
}

int ExerciseSet::getMarkOfFillInTheBlanks()
{
	return this->markOfFillInTheBlanks;
}

void ExerciseSet::setMarkOfSAQ(int mark)
{
	this->markOfSAQ = mark;
}

int ExerciseSet::getMarkOfSAQ()
{
	return this->markOfSAQ;
}

void ExerciseSet::setNumberOfChoice(int number)
{
	this->numOfChoice = number;
}

int ExerciseSet::getNumberOfChoice()
{
	return this->numOfChoice;
}

void ExerciseSet::setNumberOfJudge(int number)
{
	this->numOfJudge = number;
}

int ExerciseSet::getNumberOfJudge()
{
	return this->numOfJudge;
}

void ExerciseSet::setNumberOfFillInTheBlanks(int number)
{
	this->numOfFillInTheBlanks = number;
}

int ExerciseSet::getNumberFillInTheBlanks()
{
	return this->numOfFillInTheBlanks;
}

void ExerciseSet::setNumberOfSAQ(int number)
{
	this->numOfSAQ = number;
}

int ExerciseSet::getNumberOfSAQ()
{
	return this->numOfSAQ;
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
