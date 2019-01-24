#include "stdafx.h"
#include "Regist.h"


Regist::Regist(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	this->setFixedSize(QSize(300, 400));
	this->setWindowTitle(QString::fromLocal8Bit("�û�ע��"));
	this->setWindowModality(Qt::WindowModality::ApplicationModal);
	this->linkButtonBackToLogin = new LinkButton();
	this->linkButtonBackToLogin->setText(QString::fromLocal8Bit("���ص�¼"));
	this->linkButtonBackToLogin->setFixedHeight(30);
	this->editUsername = new QLineEdit();
	this->editUsername->setPlaceholderText(QString::fromLocal8Bit("�������û���"));
	this->editUsername->setFixedHeight(32);
	this->editPassword = new QLineEdit();
	this->editPassword->setPlaceholderText(QString::fromLocal8Bit("����������"));
	this->editPassword->setEchoMode(QLineEdit::EchoMode::Password);
	this->editPassword->setFixedHeight(32);
	this->editRepassword = new QLineEdit();
	this->editRepassword->setPlaceholderText(QString::fromLocal8Bit("�ظ�����"));
	this->editRepassword->setEchoMode(QLineEdit::EchoMode::Password);
	this->editRepassword->setFixedHeight(32);
	this->buttonComfirm = new QPushButton();
	this->buttonComfirm->setText(QString::fromLocal8Bit("�ύ"));
	this->buttonComfirm->setFixedHeight(42);
	this->labelTip = new QLabel();
	QPalette palette = this->labelTip->palette();
	palette.setColor(QPalette::ColorRole::Foreground, Qt::red);
	this->labelTip->setPalette(palette);
	this->labelTip->setAlignment(Qt::AlignTop);

	this->setCentralWidget(new QWidget());
	QVBoxLayout* layout = new QVBoxLayout();
	layout->setSpacing(20);
	layout->addWidget(this->linkButtonBackToLogin);
	layout->addWidget(this->editUsername);
	layout->addWidget(this->editPassword);
	layout->addWidget(this->editRepassword);
	layout->addWidget(this->buttonComfirm);
	layout->addWidget(this->labelTip);
	this->centralWidget()->setLayout(layout);
	this->move(QApplication::desktop()->width() / 2 - this->width() / 2, QApplication::desktop()->height() / 2 - this->height() / 2);

	connect(this->linkButtonBackToLogin, SIGNAL(clicked()), this, SLOT(slotBackToLogin()));
	connect(this->buttonComfirm, SIGNAL(clicked()), this, SLOT(slotRegist()));
}


Regist::~Regist()
{
}

void Regist::slotRegist()
{
	if (this->editUsername->text().length() == 0)
	{
		this->labelTip->setText(QString::fromLocal8Bit("�������û���"));
		return;
	}
	if (this->editPassword->text().length() == 0)
	{
		this->labelTip->setText(QString::fromLocal8Bit("����������"));
		return;
	}
	if (this->editPassword->text() != this->editRepassword->text())
	{
		this->labelTip->setText(QString::fromLocal8Bit("���벻һ��"));
		return;
	}

	httpManager = new QNetworkAccessManager(this);
	QObject::connect(httpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
	QString url = QString("http://") + SystemVariable::SERVER + ":" + QString::number(SystemVariable::SERVERPORT) + "/" + SystemVariable::REGISTSERVLET;
	request.setUrl(url);
	reply = httpManager->post(request,("username="+this->editUsername->text()+"&password="+this->editPassword->text()).toLocal8Bit());
}

void Regist::requestFinished(QNetworkReply*reply)
{
	QByteArray data=reply->readAll();
	QString msg = QString(data);

}

void Regist::slotBackToLogin()
{
	this->close();
}
