#pragma once
#include <qlistwidget.h>
#include <Exercise.h>
class ExerciseListItem :
	public QListWidgetItem
{
public:
	ExerciseListItem();
	void setIndexInExerciseSet(int index);
	void setStatus(Exercise::ExerciseStatus status);
	Exercise::ExerciseStatus getStatus();
	int getIndexInExerciseSet();
	~ExerciseListItem();
private:
	int indexInExerciseSet;
	QPixmap mapFinished;
	QPixmap mapUnFinished;
	QPixmap mapRight;
	QPixmap mapError;
	QPixmap mapFlag;
	QPixmap mapHalf;
	Exercise::ExerciseStatus status;
};

