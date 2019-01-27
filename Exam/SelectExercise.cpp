#include "stdafx.h"
#include "SelectExercise.h"


SelectExercise::SelectExercise(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	this->setWindowTitle(QString::fromLocal8Bit("��ѡ��Ҫ��ʼ��ϰ��ϰ�⼯"));
	this->setFixedSize(QSize(400, 700));
	this->listwidgetExerciseSet = new QListWidget();
	this->listwidgetExerciseSet->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->buttonBack = new QPushButton();
	this->buttonBack->setFixedHeight(40);
	this->buttonBack->setText(QString::fromLocal8Bit("���ص�¼"));
	this->buttonSelect = new QPushButton();
	this->buttonSelect->setFixedHeight(40);
	this->buttonSelect->setText(QString::fromLocal8Bit("ȷ��ѡ��"));
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
}


SelectExercise::~SelectExercise()
{
}

void SelectExercise::slotBackToLogin()
{
	//�޸������ļ�������Զ���¼
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
		font.setFamily(QString::fromLocal8Bit("΢���ź�"));
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
