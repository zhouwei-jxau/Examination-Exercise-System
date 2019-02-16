#include "stdafx.h"
#include "ExerciseListItem.h"

QString ExerciseListItem::PATHOFADDTOERRORBOOKICONPATH = QString::fromLocal8Bit("addToErrorBook.png");
ExerciseListItem::ExerciseListItem()
{
	this->mapFinished = QPixmap(SystemVariable::getIconPath() + QString::fromLocal8Bit("finished.png"));
	this->mapUnFinished = QPixmap(SystemVariable::getIconPath() + QString::fromLocal8Bit("unfinished.png"));
	this->mapRight = QPixmap(SystemVariable::getIconPath() + QString::fromLocal8Bit("right.png"));
	this->mapError = QPixmap(SystemVariable::getIconPath() + QString::fromLocal8Bit("error.png"));
	this->mapFlag = QPixmap(SystemVariable::getIconPath() + QString::fromLocal8Bit("flag.png"));
	this->mapHalf = QPixmap(SystemVariable::getIconPath() + QString::fromLocal8Bit("half.png"));
	this->setStatus(Exercise::ExerciseStatus::UnFinished);
}

void ExerciseListItem::setIndexInExerciseSet(int index)
{
	this->indexInExerciseSet = index;
}

void ExerciseListItem::setStatus(Exercise::ExerciseStatus status)
{
	this->status = status;
	if (status == Exercise::ExerciseStatus::Finished)
	{
		this->setIcon(QIcon(this->mapFinished));
	}
	if (status == Exercise::ExerciseStatus::UnFinished)
	{
		this->setIcon(QIcon(this->mapUnFinished));
	}
	if (status == Exercise::ExerciseStatus::Right)
	{
		this->setIcon(QIcon(this->mapRight));
	}
	if (status == Exercise::ExerciseStatus::Error)
	{
		this->setIcon(QIcon(this->mapError));
	}
	if (status == Exercise::ExerciseStatus::Flag)
	{
		this->setIcon(QIcon(this->mapFlag));
	}
	if (status == Exercise::ExerciseStatus::Half)
	{
		this->setIcon(QIcon(this->mapHalf));
	}
}

void ExerciseListItem::setText(QString text)
{
	this->QListWidgetItem::setText("    " + text);
}

Exercise::ExerciseStatus ExerciseListItem::getStatus()
{
	return this->status;
}

int ExerciseListItem::getIndexInExerciseSet()
{
	return this->indexInExerciseSet;
}


ExerciseListItem::~ExerciseListItem()
{
}
