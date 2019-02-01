#pragma once
#include <qlistwidget.h>
class ExerciseList :
	public QListWidget
{
	Q_OBJECT
public:
	ExerciseList();
	void addChoice(QString subject);
	void addJudge(QString subject);
	void addFillInTheBlanks(QString subject);
	void addSAQ(QString subject);
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
};

