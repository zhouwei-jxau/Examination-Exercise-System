#include "stdafx.h"
#include "ChoiceExercise.h"


ChoiceExercise::ChoiceExercise()
{
}

void ChoiceExercise::addOption(QString option)
{
	this->options.append(option);
}

QString ChoiceExercise::getOption(int index)
{
	return options.at(index);
}

int ChoiceExercise::getNumberOfOptions()
{
	return this->options.size();
}


ChoiceExercise::~ChoiceExercise()
{
}
