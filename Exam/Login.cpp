#include "stdafx.h"
#include "Login.h"


Login::Login()
{
	this->editId = new QLineEdit();
	this->editId->setPlaceholderText(QString::fromLocal8Bit("ÇëÊäÈëÑ§ºÅ"));
	this->editPassword = new QLineEdit();
	this->editPassword->setPlaceholderText(QString::fromLocal8Bit("ÇëÊäÈëÃÜÂë"));
	this->editPassword->setEchoMode(QLineEdit::EchoMode::Password);
	this->setFixedSize(QSize(800, 600));

	QGridLayout* layout = new QGridLayout();
	layout->setAlignment(Qt::AlignCenter);
	layout->addWidget(this->editId, 2, 2);
	layout->addWidget(this->editPassword, 3, 2);
	this->setLayout(layout);
}


Login::~Login()
{
}
