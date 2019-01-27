#pragma once
#include <qmainwindow.h>
#include "Login.h"
#include "ExamClient.h"
class SelectExercise :
	public QMainWindow
{
	Q_OBJECT
public:
	SelectExercise(QWidget *parent=Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
	~SelectExercise();
protected:
private slots:
	void slotRequestFinished(QNetworkReply* reply);
	void slotSelectedExerciseSet();
	void slotBackToLogin();
private:
	QListWidget* listwidgetExerciseSet;
	QPushButton* buttonSelect;
	QPushButton* buttonBack;
};

