#include "stdafx.h"
#include "SelectExercise.h"


SelectExercise::SelectExercise(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	this->setWindowTitle(QString::fromLocal8Bit("请选择要开始练习的习题集"));
	this->setFixedSize(QSize(400, 700));

	this->listwidgetExerciseSet = new QListWidget();
	QNetworkAccessManager* http = new QNetworkAccessManager(this);
	QNetworkRequest request;
	QString url = QString("http://")
		+ SystemVariable::SERVER
		+ QString::fromLocal8Bit(":")
		+ QString::number(SystemVariable::SERVERPORT)
		+ QString::fromLocal8Bit("/")
		+ SystemVariable::GETEXERCISESET;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded");
	http->get(request);
	connect(http, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotRequestFinished(QNetworkReply*)));
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(listwidgetExerciseSet);
	this->setCentralWidget(new QWidget());
	this->centralWidget()->setLayout(layout);
}


SelectExercise::~SelectExercise()
{
}

void SelectExercise::slotRequestFinished(QNetworkReply * reply)
{
	QByteArray data;
	QByteArray buffer;
	while ((buffer=reply->readLine()).length()>0)
	{
		data.append(buffer);
	}

	QJsonObject json = QJsonDocument::fromJson(data).object();
	QList<QVariant> exerciseSet=json.value("data").toVariant().toList();
	for (int i = 0; i < exerciseSet.size(); i++)
	{
		QListWidgetItem *item = new QListWidgetItem();
		QFont font = item->font();
		font.setFamily(QString::fromLocal8Bit("微软雅黑"));
		font.setPointSize(16);
		item->setFont(font);
		item->setSizeHint(QSize(this->listwidgetExerciseSet->width(), 42));
		item->setText(exerciseSet.at(i).toString());
		this->listwidgetExerciseSet->addItem(item);
	}
}
