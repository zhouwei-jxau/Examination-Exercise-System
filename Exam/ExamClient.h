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
class ExamClient : public QMainWindow
{
	Q_OBJECT
public:
	ExamClient(QWidget *parent = Q_NULLPTR);
private slots:
	void slotCommit();
private:
	QLabel* imageHeadpartrait;
	QLabel* labelUserName;
	QLabel* labelAccount;
	QPushButton* buttonCommit;
	QTextEdit* texteditSubject;

	ExerciseList* listwidgetExercise;
	Answer* answer;
};
