#pragma once
#include <qmainwindow.h>
#include <ExamClient.h>
#include <ChoiceExercise.h>
#include <JudgeExercise.h>
#include <FillInTheBlanksExercise.h>
#include <SAQExercise.h>

class GenerateExercise :
	public QMainWindow
{
	Q_OBJECT
public:
	GenerateExercise(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
	~GenerateExercise();
private slots:
	void readyRead();
	void requestFinished(QNetworkReply* replay);
private:
	QNetworkAccessManager* httpManager;
	QNetworkRequest* request;
	QNetworkReply *reply;
};

