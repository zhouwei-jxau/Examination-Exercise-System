#pragma once

#include <QtWidgets/QMainWindow>
#include <CurrentUser.h>
#include <Splitter.h>
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
#include <CheckAnswers.h>

class ExamClient : public QMainWindow
{
	Q_OBJECT
public:
	ExamClient(QWidget *parent = Q_NULLPTR);
signals:
	void signalUserCommit();
protected:
	void setAnswer(Exercise* exercise);
	QVariant getCurrentExerciseAnswer();
private slots:
	void slotCommit();
	void slotExerciseSelected(QListWidgetItem* item);
	void slotAnswerChanged();
private:
	QLabel* imageHeadpartrait;
	QLabel* labelUserName;
	QLabel* labelAccount;
	QPushButton* buttonCommit;
	QTextEdit* texteditSubject;
	QWidget* widgetAnswer;

	ExerciseList* listwidgetExercise;
	Answer* answer;

	int currentExerciseIndex;
};
