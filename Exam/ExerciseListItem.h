#pragma once
#include <qlistwidget.h>
class ExerciseListItem :
	public QListWidgetItem
{
public:
	ExerciseListItem();
	void setIndexInExerciseSet(int index);
	int getIndexInExerciseSet();
	~ExerciseListItem();
private:
	int indexInExerciseSet;
};

