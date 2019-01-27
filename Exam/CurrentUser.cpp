#include "stdafx.h"
#include "CurrentUser.h"

QString CurrentUser::account = QString("");
QString CurrentUser::username = QString("");
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


CurrentUser::~CurrentUser()
{
}
