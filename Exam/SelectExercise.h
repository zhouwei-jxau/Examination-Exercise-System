#pragma once
#include <qmainwindow.h>
#include "Login.h"
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
	void slotBackToLogin();
private:
	QListWidget* listwidgetExerciseSet;
	QPushButton* buttonSelect;
	QPushButton* buttonBack;
};

