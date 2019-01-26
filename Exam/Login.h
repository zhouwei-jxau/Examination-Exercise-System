#pragma once
#include <qmainwindow.h>
#include "LinkButton.h"
#include "Regist.h"
#include "SelectExercise.h"
class Login :
	public QMainWindow
{
	Q_OBJECT
public:
	Login();
	Login(QWidget *parent, Qt::WindowFlags flags = Qt::WindowFlags());
	~Login();
private slots:
	void slotRegist();
	void slotLogin();
	void requestFinished(QNetworkReply*reply);
private:
	QLabel* imageHeadpartrait;
	LinkButton* linkButtonRegist;
	LinkButton* linkButtonFindPassword;
	QCheckBox* checkBoxRemeberPassword;
	QCheckBox* checkBoxAutoLogin;
	QLineEdit* editId;
	QLineEdit* editPassword;
	QPushButton* buttonLogin;
	QLabel* labelTip;

	QNetworkAccessManager* httpManager;
	QNetworkRequest request;
	QNetworkReply* reply;
};

