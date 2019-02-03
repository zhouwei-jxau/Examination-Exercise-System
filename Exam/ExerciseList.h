#pragma once
#include <qlistwidget.h>
#include <Exercise.h>
#include <ExerciseListItem.h>
class ExerciseList :
	public QListWidget
{
	Q_OBJECT
public:
	ExerciseList();
	void addExercise(Exercise* exercise,int index=-1);
	void addChoice(QString subject,int index=-1);
	void addJudge(QString subject, int index = -1);
	void addFillInTheBlanks(QString subject, int index = -1);
	void addSAQ(QString subject, int index = -1);
	bool isUnSubjectItem(QListWidgetItem* item);
	~ExerciseList();
private slots:
	void slotItemClicked(QListWidgetItem* item);
private:
	int numOfChoice;
	int numOfJudge;
	int numOfFillInTheBlanks;
	int numOfSAQ;

	QListWidgetItem* itemChoiceFolder;
	QListWidgetItem* itemJudgeFolder;
	QListWidgetItem* itemFillInTheBlanks;
	QListWidgetItem* itemSAQ;
	QWidget* widgetChoiceFolder;
	QWidget* widgetJudgeFolder;
	QWidget* widgetFillInTheBlanksFolder;
	QWidget* widgetSAQFolder;

	bool isChoiceFold;
	bool isJudgeFold;
	bool isFillInTheBlanksFold;
	bool isSAQFold;

	QString pathOfFold;
	QString pathOfUnFold;

	QList<QListWidgetItem*> unSubjectItems;
};

