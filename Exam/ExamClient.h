#pragma once

#include <QtWidgets/QMainWindow>
#include <CurrentUser.h>
#include <Splitter.h>
#include <Answer.h>
class ExamClient : public QMainWindow
{
	Q_OBJECT
public:
	ExamClient(QWidget *parent = Q_NULLPTR);
private:
	QLabel* imageHeadpartrait;
	QLabel* labelUserName;
	QLabel* labelAccount;
	QPushButton* buttonCommit;
	QTextEdit* texteditSubject;

	QListWidget* listwidgetExercise;
	Answer* answer;
};
