#include "stdafx.h"
#include "SelectExercise.h"


SelectExercise::SelectExercise(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	this->setWindowTitle(QString::fromLocal8Bit("请选择要开始练习的习题集"));
	this->setFixedSize(QSize(400, 700));
	this->listwidgetExerciseSet = new QListWidget();
	this->listwidgetExerciseSet->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->buttonBack = new QPushButton();
	this->buttonBack->setFixedHeight(40);
	this->buttonBack->setText(QString::fromLocal8Bit("返回登录"));
	this->buttonSelect = new QPushButton();
	this->buttonSelect->setFixedHeight(40);
	this->buttonSelect->setText(QString::fromLocal8Bit("确认选择"));
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(listwidgetExerciseSet);
	QWidget* widgetButton = new QWidget();
	QHBoxLayout* layoutButton = new QHBoxLayout();
	layoutButton->addWidget(this->buttonBack);
	layoutButton->addWidget(this->buttonSelect);
	widgetButton->setLayout(layoutButton);
	layout->addWidget(widgetButton);
	this->setCentralWidget(new QWidget());
	this->centralWidget()->setLayout(layout);

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
	connect(this->buttonBack, SIGNAL(clicked()), this, SLOT(slotBackToLogin()));
	connect(this->buttonSelect, SIGNAL(clicked()), this, SLOT(slotSelectedExerciseSet()));
}


SelectExercise::~SelectExercise()
{
}

void SelectExercise::slotSelectedExerciseSet()
{
	ExamClient* client=new ExamClient();
	client-> show();
	this->close();
}

void SelectExercise::slotBackToLogin()
{
	//修改配置文件，解除自动登录
	QDir dir(QString::fromLocal8Bit(SystemVariable::CONFIGPATH));
	if (!dir.exists())
	{
		dir.mkdir(dir.path());
	}
	QString path = dir.currentPath() + dir.path() + "/" + SystemVariable::USERFILENAME;
	QFile file(path);
	if (file.exists())
	{
		file.open(QFile::ReadWrite);
		QString data = file.readAll();
		data.resize(data.length() - 1);
		data.append("0");
		file.resize(0);
		file.write(data.toLocal8Bit());
		file.close();
	}
	Login* login = new Login();
	login->show();
	this->close();
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
	if (exerciseSet.size() > 0)
	{
		this->listwidgetExerciseSet->item(0)->setSelected(true);
	}
	reply->deleteLater();
}
