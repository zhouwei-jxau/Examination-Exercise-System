#include "stdafx.h"
#include "Login.h"


Login::Login()
{
	this->imageHeadpartrait = new QLabel();
	this->imageHeadpartrait->setPixmap(QPixmap("Resources\\default\\icon\\headpartrait.jpg"));
	this->imageHeadpartrait->setFixedSize(QSize(90, 90));
	this->checkBoxRemeberPassword = new QCheckBox();
	this->checkBoxRemeberPassword->setText(QString::fromLocal8Bit("¼Ç×¡ÃÜÂë"));
	this->linkButtonRegist = new LinkButton();
	this->linkButtonRegist->setText(QString::fromLocal8Bit("×¢²áÕËºÅ"));
	this->linkButtonRegist->setFixedHeight(30);
	this->editId = new QLineEdit();
	this->editId->setPlaceholderText(QString::fromLocal8Bit("ÇëÊäÈëÑ§ºÅ"));
	this->editId->setFixedSize(QSize(200, 30));
	this->editPassword = new QLineEdit();
	this->editPassword->setPlaceholderText(QString::fromLocal8Bit("ÇëÊäÈëÃÜÂë"));
	this->editPassword->setEchoMode(QLineEdit::EchoMode::Password);
	this->editPassword->setFixedSize(QSize(200, 30));
	this->buttonLogin = new QPushButton();
	this->buttonLogin->setFixedSize(QSize(200, 40));
	this->buttonLogin->setText(QString::fromLocal8Bit("µÇÂ¼"));
	this->setFixedSize(QSize(400, 260));
	this->labelTip = new QLabel();
	QPalette palette = this->labelTip->palette();
	palette.setColor(QPalette::Foreground, QColor(255, 0, 0));
	this->labelTip->setPalette(palette);
	this->setWindowTitle(QString::fromLocal8Bit("¿¼ÊÔÁ·Ï°¿Í»§¶Ë"));
	this->setCentralWidget(new QWidget());
	QGridLayout* layout = new QGridLayout();
	layout->setSpacing(8);
	layout->setContentsMargins(20, 40,10, 10);
	layout->addWidget(this->imageHeadpartrait, 0, 0, 3, 1, Qt::AlignTop);
	layout->addWidget(this->editId, 0, 1,1,3, Qt::Alignment::enum_type::AlignTop);
	layout->addWidget(this->linkButtonRegist, 0, 2,1,1, Qt::AlignLeft | Qt::AlignBottom);
	layout->addWidget(this->editPassword, 1, 1,1,3, Qt::Alignment::enum_type::AlignBottom);
	layout->addWidget(this->checkBoxRemeberPassword, 2, 1,1,1, Qt::AlignVCenter | Qt::AlignLeft);
	layout->addWidget(this->buttonLogin, 3, 1, 2, 1, Qt::AlignLeft|Qt::AlignTop);
	layout->addWidget(this->labelTip, 4, 1, 1, 1, Qt::AlignLeft|Qt::AlignTop);
	this->centralWidget()->setLayout(layout);
	connect(this->linkButtonRegist, SIGNAL(clicked()), this, SLOT(slotRegist()));
	connect(this->buttonLogin, SIGNAL(clicked()), this, SLOT(slotLogin()));
}

Login::Login(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	Login();
}


Login::~Login()
{
}

void Login::slotLogin()
{
	httpManager = new QNetworkAccessManager(this);
	QObject::connect(httpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
	QString url = QString("http://") + SystemVariable::SERVER + ":" + QString::number(SystemVariable::SERVERPORT) + "/" + SystemVariable::LOGINSERVLET;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded");
	QCryptographicHash md5(QCryptographicHash::Md5);
	md5.addData(this->editPassword->text().toLocal8Bit());
	reply = httpManager->post(request, ("account=" + this->editId->text() + "&password=" + md5.result().toHex()).toLocal8Bit());
}

void Login::requestFinished(QNetworkReply*reply)
{
	QByteArray data = reply->readAll();
	QJsonObject json = QJsonDocument::fromJson(data).object();
	int responseCode = json.value("responseCode").toInt();
	if (responseCode == 0)
	{
		SelectExercise* selectExercise = new SelectExercise();
		selectExercise->show();
		this->close();
	}
	else
	{
		this->labelTip->setText(QString::fromLocal8Bit("µÇÂ¼Ê§°Ü:")+json.value("msg").toString());
	}
}

void Login::slotRegist()
{
	Regist* regist = new Regist(this);
	regist->show();
}
