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
	static void setExerciseSet(class ExerciseSet exerciseSet);
	static ExerciseSet& getExerciseSet();
	static void setSingleMarkList(QList<double> list);
	static QList<double>& getSingleMarkList();
	static void setRightOfChoice(int n);
	static int getRightOfChoice();
	static void setRightOfJudge(int n);
	static int getRightOfJudge();
	static void setRightOfFillInTheBlanks(int n);
	static int getRightOfFillInTheBlanks();
	static void setRightOfSAQ(int n);
	static int getRightOfSAQ();
	static void setMark(double mark);
	static double getMark();
	static void setMarkOfChoice(double mark);
	static double getMarkOfChoice();
	static void setMarkOfJudge(double mark);
	static double getMarkOfJudge();
	static void setMarkOfFillInTheBlanks(double mark);
	static double getMarkOfFillInTheBlanks();
	static void setMarkOfSAQ(double mark);
	static double getMarkOfSAQ();
	static void clearWithoutLogOut();
	~CurrentUser();
private:
	static QString account;
	static QString username;
	static class ExerciseSet exerciseSet;
	static QList<double> singleMark;
	static int rightOfChoice;
	static int rightOfJudge;
	static int rightOfFillInTheBlanks;
	static int rightOfSAQ;
	static double markOfChoice;
	static double markOfJudge;
	static double markOfFillInTheBlanks;
	static double markOfSAQ;
	static double mark;
};

