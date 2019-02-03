#pragma once
#include "Exercise.h"
class ChoiceExercise :
	public Exercise
{
public:
	ChoiceExercise();
	void addOption(QString option);
	QString getOption(int index);
	QList<QString> getOptions();
	int getNumberOfOptions();
	~ChoiceExercise();
private:
	QList<QString> options;
};

