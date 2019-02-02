#pragma once
#include <qobject.h>
#include <ExerciseSet.h>
class CurrentUser :
	public QObject
{
public:
	CurrentUser();
	static void setUserName(QString username);
	static QString getUserName();
	static void setAccount(QString account);
	static QString getAccount();
	static void setExerciseSet(ExerciseSet exerciseSet);
	static ExerciseSet& getExerciseSet();
	~CurrentUser();
private:
	static QString account;
	static QString username;
	static ExerciseSet exerciseSet;
};

