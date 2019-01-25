#include "stdafx.h"
#include "CheckVersion.h"
#include "qmessagebox.h"

CheckVersion::CheckVersion()
{
	QWidget* centerWidget = new QWidget();
	centerWidget->setLayout(new QVBoxLayout());
	centerWidget->layout()->setAlignment(Qt::AlignCenter);
	QLabel* label = new QLabel();
	QFont font = label->font();
	font.setPixelSize(24);
	label->setFont(font);
	label->setText(QString::fromLocal8Bit("�������ӵ�������..."));
	centerWidget->layout()->addWidget(label);
	this->setCentralWidget(centerWidget);
 	this->setFixedWidth(800);
	this->setFixedHeight(100);
	this->move(QApplication::desktop()->width() / 2-this->width()/2, QApplication::desktop()->height() / 2-this->height()/2);
	this->setWindowFlags(Qt::WindowFlags::enum_type::FramelessWindowHint| Qt::WindowFlags::enum_type::Tool);
	httpManager = new QNetworkAccessManager(this);
	QObject::connect(httpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
	QString url = QString("http://") + SystemVariable::SERVER + ":" + QString::number(SystemVariable::SERVERPORT) + "/" + SystemVariable::CHECKVERSIONSERVLET;
	request.setUrl(url);
	reply=httpManager->get(request);
}


CheckVersion::~CheckVersion()
{
}

void CheckVersion::requestFinished(QNetworkReply * replay)
{
	QByteArray data = reply->readAll();
	int latestVersion = QString::fromLocal8Bit(data).toInt();
	if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200)
	{
		if (latestVersion == SystemVariable::VERSION)
		{
			Login *login=new Login();
			login->show();
			this->close();
		}
		else
		{
			QMessageBox messageBox;
			messageBox.about(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����µ����°汾"));
			QApplication::quit();
		}
	}
	else
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�޷����ӵ�������!�����������ӡ�"));
		QApplication::quit();
	}
}

void CheckVersion::readyRead()
{
}
