#include "stdafx.h"
#include "SelectExercise.h"


SelectExercise::SelectExercise(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	this->setWindowTitle(QString::fromLocal8Bit("��ѡ��Ҫ��ʼ��ϰ��ϰ�⼯"));
	this->setFixedSize(QSize(400, 700));
}


SelectExercise::~SelectExercise()
{
}
