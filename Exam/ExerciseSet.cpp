#include "stdafx.h"
#include "ExerciseSet.h"


ExerciseSet::ExerciseSet()
{

}

ExerciseSet::ExerciseSet(const ExerciseSet & es)
{
	this->name = es.name;
	this->markOfChoice = es.markOfChoice;
	this->markOfJudge = es.markOfJudge;
	this->markOfFillInTheBlanks = es.markOfFillInTheBlanks;
	this->markOfSAQ = es.markOfSAQ;
	this->numOfChoice = es.numOfChoice;
	this->numOfJudge = es.numOfJudge;
	this->numOfFillInTheBlanks = es.numOfFillInTheBlanks;
	this->numOfSAQ = es.numOfSAQ;
	for (int i = 0; i < es.list.size(); i++)
	{
		Exercise* exercise;
		if (es.list.at(i)->getType() == Exercise::ExerciseType::Choice)
		{
			exercise = new ChoiceExercise(*static_cast<ChoiceExercise*>(es.list.at(i)));
		}
		if (es.list.at(i)->getType() == Exercise::ExerciseType::Judge)
		{
			exercise = new JudgeExercise(*static_cast<JudgeExercise*>(es.list.at(i)));
		}
		if (es.list.at(i)->getType() == Exercise::ExerciseType::FillInTheBlanks)
		{
			exercise = new FillInTheBlanksExercise(*static_cast<FillInTheBlanksExercise*>(es.list.at(i)));
		}
		if (es.list.at(i)->getType() == Exercise::ExerciseType::SAQ)
		{
			exercise = new SAQExercise(*static_cast<SAQExercise*>(es.list.at(i)));
		}
		this->list.append(exercise);
	}

	for (int i = 0; i < es.answerList.size(); i++)
	{
		UserAnswer* userAnswer = new UserAnswer(*es.answerList.at(i));
		this->answerList.append(userAnswer);
	}
}

void ExerciseSet::setName(QString name)
{
	this->name = name;
}

QString ExerciseSet::getName()
{
	return this->name;
}

void ExerciseSet::setMarkOfChoice(double mark)
{
	this->markOfChoice = mark;
}

int ExerciseSet::getMarkOfChoice()
{
	return this->markOfChoice;
}

void ExerciseSet::setMarkOfJudge(double mark)
{
	this->markOfJudge = mark;
}

int ExerciseSet::getMarkOfJudge()
{
	return this->markOfJudge;
}

void ExerciseSet::setMarkOfFillInTheBlanks(double mark)
{
	this->markOfFillInTheBlanks = mark;
}

int ExerciseSet::getMarkOfFillInTheBlanks()
{
	return this->markOfFillInTheBlanks;
}

void ExerciseSet::setMarkOfSAQ(double mark)
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

int ExerciseSet::indexOf(Exercise* exercise)
{
	for (int i = 0; i < this->list.size(); i++)
	{
		if (exercise->getType() == list.at(i)->getType())
		{
			if (exercise->getExerciseNo() == list.at(i)->getExerciseNo())
			{
				return i;
			}
		}
	}
	return -1;
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
		delete this->answerList.at(i);
	}
}
