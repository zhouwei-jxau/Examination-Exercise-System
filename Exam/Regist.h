#pragma once
#include <qmainwindow.h>
#include <LinkButton.h>
class Regist :
	public QMainWindow
{
	Q_OBJECT
public:
	Regist(QWidget *parent=Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
	~Regist();
private slots:
	void slotBackToLogin();
	void slotRegist();
	void requestFinished(QNetworkReply*reply);
private:
	LinkButton* linkButtonBackToLogin;
	QLineEdit* editUsername;
	QLineEdit* editPassword;
	QLineEdit* editRepassword;
	QPushButton* buttonComfirm;
	QLabel* labelTip;

	QNetworkAccessManager* httpManager;
	QNetworkRequest request;
	QNetworkReply* reply;
};

