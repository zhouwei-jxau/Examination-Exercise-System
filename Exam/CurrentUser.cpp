#include "stdafx.h"
#include "CurrentUser.h"

QString CurrentUser::account = QString("");
QString CurrentUser::username = QString("");
ExerciseSet CurrentUser::exerciseSet=ExerciseSet();
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


CurrentUser::~CurrentUser()
{
}
