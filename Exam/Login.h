#pragma once
#include <qmainwindow.h>
class Login :
	public QMainWindow
{
public:
	Login();
	Login(QWidget *parent, Qt::WindowFlags flags = Qt::WindowFlags());
	~Login();
private:
	QLabel* imageHeadpartrait;
	QLabel* linkButtonRegist;
	QLabel* linkButtonFindPassword;
	QCheckBox* checkBoxRemeberPassword;
	QLineEdit* editId;
	QLineEdit* editPassword;
	QPushButton* buttonLogin;
};

