#pragma once
#include <qmainwindow.h>
class Regist :
	public QMainWindow
{
	Q_OBJECT
public:
	Regist(QWidget *parent=Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
	~Regist();
private:
	QLineEdit* editUsername;
	QLineEdit* editPassword;
	QLineEdit* editRepassword;
	QPushButton* buttonComfirm;
	QLabel* labelTip;
};

