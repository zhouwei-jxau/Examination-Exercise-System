#pragma once
#include <Exercise.h>
#include <UserAnswer.h>
class ExerciseSet
{
public:
	ExerciseSet();
	void setName(QString name);
	QString getName();
	void setMarkOfChoice(int mark);
	int getMarkOfChoice();
	void setMarkOfJudge(int mark);
	int getMarkOfJudge();
	void setMarkOfFillInTheBlanks(int mark);
	int getMarkOfFillInTheBlanks();
	void setMarkOfSAQ(int mark);
	int getMarkOfSAQ();
	void setNumberOfChoice(int number);
	int getNumberOfChoice();
	void setNumberOfJudge(int number);
	int getNumberOfJudge();
	void setNumberOfFillInTheBlanks(int number);
	int getNumberFillInTheBlanks();
	void setNumberOfSAQ(int number);
	int getNumberOfSAQ();
	void addExercise(Exercise* exercise);
	void setAnswer(UserAnswer answer,int index);
	QList<Exercise*> getExercise();
	QList<UserAnswer*> getAnswers();
	~ExerciseSet();
private:
	QString name;
	int markOfChoice;
	int markOfJudge;
	int markOfFillInTheBlanks;
	int markOfSAQ;
	int numOfChoice;
	int numOfJudge;
	int numOfFillInTheBlanks;
	int numOfSAQ;
	QList<Exercise*> list;
	QList<UserAnswer*> answerList;
};

