#pragma once
#include <qmainwindow.h>
#include <CurrentUser.h>
#include <FillInTheBlanksExercise.h>
#include <ExerciseResult.h>

class CheckAnswers :
	public QMainWindow
{
	Q_OBJECT
public:
	CheckAnswers(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
	~CheckAnswers();
private slots:
	void slotUserCommit();
private:
	void Check();
	void GenerateMark();

	int rightOfChoice;
	int rightOfJudge;
	int rightOfFillInTheBlanks;
	int rightOfSAQ;
	int totalOfChoice;
	int totalOfJudge;
	int totalOfFillInTheBlanks;
	int totalOfSAQ;

	QList<double> markOfSingleExercise;
	double totalMark;
};

