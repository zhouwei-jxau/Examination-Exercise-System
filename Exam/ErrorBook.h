#pragma once
#include <qmainwindow.h>
#include <CurrentUser.h>
#include <ExerciseList.h>
#include <Answer.h>
#include <Splitter.h>
#include <ErrorExercise.h>
#include <AnswerChoice.h>
#include <AnswerJudge.h>
#include <AnswerFillInTheBlanks.h>
#include <AnswerSAQ.h>
#include <LineEditWithTag.h>
#include <ExamClient.h>
class ErrorBook :
	public QMainWindow
{
	Q_OBJECT
public:
	ErrorBook();
	~ErrorBook();
signals:
	void signalUserCommit();
protected:
	void setAnswer(Exercise* exercise);
	void setCollection(int collection);
	QVariant getCurrentExerciseAnswer();
private slots:
	void slotExerciseSelected(QListWidgetItem* item);
	void slotExerciseDoubleClicked(QListWidgetItem* item);
	void slotAnswerChanged();
	void slotGetErrorExercise(QNetworkReply* reply);
	void slotGenerate();
private:
	QLabel* imageHeadpartrait;
	QLabel* labelUserName;
	QLabel* labelAccount;
	QLabel* labelTitle;
	QLabel* labelTip;
	QPushButton* buttonGenerate;
	QTextEdit* texteditSubject;
	QTextEdit* texteditMark;
	QWidget* widgetAnswer;

	ExerciseList* listwidgetExercise;
	Answer* answer;
	QList<ErrorExercise*> errorExerciseList;
	QList<ChoiceExercise*> errorChoiceExerciseList;
	QList<JudgeExercise*> errorJudgeExerciseList;
	QList<FillInTheBlanksExercise*> errorFillInTheBlanksExerciseList;
	QList<SAQExercise*> errorSAQExerciseList;

	LineEditWithTag* subject;
	LineEditWithTag* numOfChoice;
	LineEditWithTag* markOfChoice;
	LineEditWithTag* numOfJudge;
	LineEditWithTag* markOfJudge;
	LineEditWithTag* numOfFillInTheBlanks;
	LineEditWithTag* markOfFillInTheBlanks;
	LineEditWithTag* numOfSAQ;
	LineEditWithTag* markOfSAQ;
};

