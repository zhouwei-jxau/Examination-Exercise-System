#pragma once
#include <qmainwindow.h>
#include <CurrentUser.h>
#include <Splitter.h>
#include <ExerciseList.h>
#include <Answer.h>
#include <AnswerChoice.h>
#include <AnswerJudge.h>
#include <AnswerFillInTheBlanks.h>
#include <AnswerSAQ.h>
#include <ExerciseList.h>
#include <ChoiceExercise.h>
#include <JudgeExercise.h>
#include <FillInTheBlanksExercise.h>
#include <SAQExercise.h>
#include <Analysis.h>
#include <SelectExercise.h>
class ExerciseResult :
	public QMainWindow
{
	Q_OBJECT
public:
	ExerciseResult(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
	void setAnswer(Exercise* exercise);
	~ExerciseResult();
private slots:
	void slotExerciseSelected(QListWidgetItem* item);
	void slotBackToExerciseSelect();
private:
	QLabel* labelHeadpartrait;
	QLabel* labelUsername;
	QLabel* labelAccount;
	QPushButton* buttonBackToSelectExercise;
	QLabel* labelTotalMark;
	QLabel* labelChoiceMark;
	QLabel* labelJudgeMark;
	QLabel* labelFillInTheBlanksMark;
	QLabel* labelSAQMark;

	QWidget* widgetSystemAnswer;
	Answer* systemAnswer;
	QWidget* widgetStudentAnswer;
	Answer* studentAnswer;
	Analysis* analysis;
	ExerciseList* listwidgetExercise;
};

