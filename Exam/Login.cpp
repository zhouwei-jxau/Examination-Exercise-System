#include "stdafx.h"
#include "Login.h"


Login::Login()
{
	this->imageHeadpartrait = new QLabel();
	this->imageHeadpartrait->setPixmap(QPixmap("Resources\\default\\icon\\headpartrait.jpg"));
	this->imageHeadpartrait->setFixedSize(QSize(90, 90));
	this->checkBoxRemeberPassword = new QCheckBox();
	this->checkBoxRemeberPassword->setText(QString::fromLocal8Bit("¼Ç×¡ÃÜÂë"));
	this->linkButtonRegist = new QLabel();
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
	this->setFixedSize(QSize(400, 240));
	this->setWindowTitle(QString::fromLocal8Bit("¿¼ÊÔÁ·Ï°¿Í»§¶Ë"));
	this->setCentralWidget(new QWidget());
	QGridLayout* layout = new QGridLayout();
	layout->setSpacing(8);
	layout->setContentsMargins(20, 30,10, 40);
	layout->addWidget(this->imageHeadpartrait, 0, 0, 3, 1, Qt::AlignTop);
	layout->addWidget(this->editId, 0, 1,1,3, Qt::Alignment::enum_type::AlignTop);
	layout->addWidget(this->linkButtonRegist, 0, 2,1,1, Qt::AlignLeft | Qt::AlignBottom);
	layout->addWidget(this->editPassword, 1, 1,1,3, Qt::Alignment::enum_type::AlignBottom);
	layout->addWidget(this->checkBoxRemeberPassword, 2, 1,1,1, Qt::AlignVCenter | Qt::AlignLeft);
	layout->addWidget(this->buttonLogin, 3, 1, 2, 1, Qt::AlignLeft);
	this->centralWidget()->setLayout(layout);

}

Login::Login(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	Login();
}


Login::~Login()
{
}
