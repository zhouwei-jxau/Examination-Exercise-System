#pragma once
#include <qmainwindow.h>
#include <Login.h>
class CheckVersion :
	public QMainWindow
{
	Q_OBJECT
public:
	CheckVersion();
	~CheckVersion();
private slots:
	void readyRead();
	void requestFinished(QNetworkReply* replay);
private:
	QNetworkAccessManager* httpManager;
	QNetworkRequest request;
	QNetworkReply *reply;
};

