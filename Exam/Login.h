#pragma once
#include <qmainwindow.h>
#include "LinkButton.h"
#include "Regist.h"
class Login :
	public QMainWindow
{
	Q_OBJECT
public:
	Login();
	Login(QWidget *parent, Qt::WindowFlags flags = Qt::WindowFlags());
	~Login();
private slots:
	void slotRegist();
private:
	QLabel* imageHeadpartrait;
	LinkButton* linkButtonRegist;
	LinkButton* linkButtonFindPassword;
	QCheckBox* checkBoxRemeberPassword;
	QLineEdit* editId;
	QLineEdit* editPassword;
	QPushButton* buttonLogin;
};

