#pragma once
#include <Exercise.h>
#include <UserAnswer.h>
#include <ChoiceExercise.h>
#include <JudgeExercise.h>
#include <FillInTheBlanksExercise.h>
#include <SAQExercise.h>
class ExerciseSet
{
public:
	ExerciseSet();
	ExerciseSet(const ExerciseSet& es);
	void setName(QString name);
	QString getName();
	void setMarkOfChoice(double mark);
	int getMarkOfChoice();
	void setMarkOfJudge(double mark);
	int getMarkOfJudge();
	void setMarkOfFillInTheBlanks(double mark);
	int getMarkOfFillInTheBlanks();
	void setMarkOfSAQ(double mark);
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
	double markOfChoice;
	double markOfJudge;
	double markOfFillInTheBlanks;
	double markOfSAQ;
	int numOfChoice;
	int numOfJudge;
	int numOfFillInTheBlanks;
	int numOfSAQ;
	QList<Exercise*> list;
	QList<UserAnswer*> answerList;
};

