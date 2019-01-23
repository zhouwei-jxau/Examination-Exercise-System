#include "stdafx.h"
#include "Regist.h"


Regist::Regist(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	this->setWindowTitle(QString::fromLocal8Bit("�û�ע��"));
	this->setWindowModality(Qt::WindowModality::ApplicationModal);
	this->editUsername = new QLineEdit();
	this->editUsername->setPlaceholderText(QString::fromLocal8Bit("�������û���"));
	this->editPassword = new QLineEdit();
	this->editPassword->setPlaceholderText(QString::fromLocal8Bit("����������"));
	this->editRepassword = new QLineEdit();
	this->editRepassword->setPlaceholderText(QString::fromLocal8Bit("�ظ�����"));
	this->buttonComfirm = new QPushButton();
	this->buttonComfirm->setText(QString::fromLocal8Bit("�ύ"));
	this->labelTip = new QLabel();

	this->setCentralWidget(new QWidget());
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(this->editUsername);
	layout->addWidget(this->editPassword);
	layout->addWidget(this->editRepassword);
	layout->addWidget(this->buttonComfirm);
	layout->addWidget(this->labelTip);
	this->centralWidget()->setLayout(layout);
	this->move(QApplication::desktop()->width() / 2 - this->width() / 2, QApplication::desktop()->height() / 2 - this->height() / 2);
}


Regist::~Regist()
{
}
