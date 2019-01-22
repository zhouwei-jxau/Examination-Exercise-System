#pragma once
#include <qmainwindow.h>
class Login :
	public QMainWindow
{
public:
	Login();
	~Login();
private:
	QLabel* textId;
	QLabel* textPassword;
	QLabel* imageHeadpartrait;
	QLabel* linkButtonRegist;
	QLabel* linkButtonFindPassword;
	QCheckBox* checkBoxRemeberPassword;
	QLineEdit* editId;
	QLineEdit* editPassword;
};

