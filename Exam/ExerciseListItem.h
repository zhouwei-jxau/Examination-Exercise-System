#pragma once
#include <qlistwidget.h>
#include <Exercise.h>
class ExerciseListItem :
	public QListWidgetItem
{
public:
	static QString PATHOFADDTOERRORBOOKICONPATH;
public:
	ExerciseListItem();
	void setIndexInExerciseSet(int index);
	void setStatus(Exercise::ExerciseStatus status);
	void setText(QString text);
	Exercise::ExerciseStatus getStatus();
	int getIndexInExerciseSet();
	void setIconVisiable(bool visiable);
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
	bool visiable;
};

