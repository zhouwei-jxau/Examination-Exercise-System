#pragma once
#include <qlistwidget.h>
#include <Exercise.h>
#include <ExerciseListItem.h>
#include <ExerciseSet.h>
#include <CurrentUser.h>
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
	void addExerciseSet(class ExerciseSet exerciseSet);
	bool isUnSubjectItem(QListWidgetItem* item);
	void setShowCheckResult(bool show);
	bool isShowCheckResult();
	void setIconVisiable(bool visiable);
	~ExerciseList();
signals:
	void signalAddToErrorBookClicked();
private slots:
	void slotItemClicked(QListWidgetItem* item);
	void slotAddToErrorBookClicked(QAbstractButton *button);
	void slotGetAddtoErrorBookStatus(QNetworkReply* reply);
private:
	int numOfChoice;
	int numOfJudge;
	int numOfFillInTheBlanks;
	int numOfSAQ;

	QListWidgetItem* itemChoiceFolder;
	QListWidgetItem* itemJudgeFolder;
	QListWidgetItem* itemFillInTheBlanksFolder;
	QListWidgetItem* itemSAQFolder;
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
	bool showCheckResult;

	QButtonGroup* buttonGroup;
	QHash<QPushButton*, int> addToErrorBookButtonIndexInExerciseSet;
};

