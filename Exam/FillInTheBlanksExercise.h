#pragma once
#include "Exercise.h"
class FillInTheBlanksExercise :
	public Exercise
{
public:
	FillInTheBlanksExercise();
	void setNumberOfBlanks(int num);
	int getNumOfBlanks();
	~FillInTheBlanksExercise();
private:
	int numOfBlanks;
};

