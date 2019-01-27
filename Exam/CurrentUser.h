#pragma once
#include <qobject.h>
class CurrentUser :
	public QObject
{
public:
	CurrentUser();
	static void setUserName(QString username);
	static QString getUserName();
	static void setAccount(QString account);
	static QString getAccount();
	~CurrentUser();
private:
	static QString account;
	static QString username;
};

