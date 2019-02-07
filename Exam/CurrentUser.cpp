#include "stdafx.h"
#include "CurrentUser.h"

QString CurrentUser::account = QString("");
QString CurrentUser::username = QString("");
ExerciseSet CurrentUser::exerciseSet=ExerciseSet();
QList<double> CurrentUser::singleMark;
int CurrentUser::rightOfChoice = 0;
int CurrentUser::rightOfJudge = 0;
int CurrentUser::rightOfFillInTheBlanks = 0;
int CurrentUser::rightOfSAQ = 0;
double CurrentUser::mark = 0;
double CurrentUser::markOfChoice=0;
double CurrentUser::markOfJudge = 0;
double CurrentUser::markOfFillInTheBlanks = 0;
double CurrentUser::markOfSAQ = 0;

CurrentUser::CurrentUser()
{
}

void CurrentUser::setUserName(QString username)
{
	CurrentUser::username = username;
}

QString CurrentUser::getUserName()
{
	return CurrentUser::username;
}

void CurrentUser::setAccount(QString account)
{
	CurrentUser::account = account;
}

QString CurrentUser::getAccount()
{
	return CurrentUser::account;
}

void CurrentUser::setExerciseSet(ExerciseSet exerciseSet)
{
	CurrentUser::exerciseSet = exerciseSet;
}

ExerciseSet& CurrentUser::getExerciseSet()
{
	return CurrentUser::exerciseSet;
}

void CurrentUser::setSingleMarkList(QList<double> list)
{
	CurrentUser::singleMark = list;
}

QList<double>& CurrentUser::getSingleMarkList()
{
	return CurrentUser::singleMark;
}

void CurrentUser::setRightOfChoice(int n)
{
	CurrentUser::rightOfChoice = n;
}

int CurrentUser::getRightOfChoice()
{
	return CurrentUser::rightOfChoice;
}

void CurrentUser::setRightOfJudge(int n)
{
	CurrentUser::rightOfJudge = n;
}

int CurrentUser::getRightOfJudge()
{
	return CurrentUser::rightOfJudge;
}

void CurrentUser::setRightOfFillInTheBlanks(int n)
{
	CurrentUser::rightOfFillInTheBlanks = n;
}

int CurrentUser::getRightOfFillInTheBlanks()
{
	return CurrentUser::rightOfFillInTheBlanks;
}

void CurrentUser::setRightOfSAQ(int n)
{
	CurrentUser::rightOfSAQ = n;
}

int CurrentUser::getRightOfSAQ()
{
	return CurrentUser::rightOfSAQ;
}

void CurrentUser::setMark(double mark)
{
	CurrentUser::mark = mark;
}

double CurrentUser::getMark()
{
	return CurrentUser::mark;
}

void CurrentUser::setMarkOfChoice(double mark)
{
	CurrentUser::markOfChoice = mark;
	return;
}

double CurrentUser::getMarkOfChoice()
{
	return CurrentUser::markOfChoice;
}

void CurrentUser::setMarkOfJudge(double mark)
{
	CurrentUser::markOfJudge = mark;
}

double CurrentUser::getMarkOfJudge()
{
	return CurrentUser::markOfJudge;
}

void CurrentUser::setMarkOfFillInTheBlanks(double mark)
{
	CurrentUser::markOfFillInTheBlanks= mark;
}

double CurrentUser::getMarkOfFillInTheBlanks()
{
	return CurrentUser::markOfFillInTheBlanks;
}

void CurrentUser::setMarkOfSAQ(double mark)
{
	CurrentUser::markOfSAQ = mark;
}

double CurrentUser::getMarkOfSAQ()
{
	return CurrentUser::markOfSAQ;
}


CurrentUser::~CurrentUser()
{
}
