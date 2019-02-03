#include "stdafx.h"
#include "ExerciseListItem.h"


ExerciseListItem::ExerciseListItem()
{
}

void ExerciseListItem::setIndexInExerciseSet(int index)
{
	this->indexInExerciseSet = index;
}

int ExerciseListItem::getIndexInExerciseSet()
{
	return this->indexInExerciseSet;
}


ExerciseListItem::~ExerciseListItem()
{
}
