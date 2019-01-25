#include "stdafx.h"
#include "SelectExercise.h"


SelectExercise::SelectExercise(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	this->setWindowTitle(QString::fromLocal8Bit("请选择要开始练习的习题集"));
	this->setFixedSize(QSize(400, 700));
}


SelectExercise::~SelectExercise()
{
}
