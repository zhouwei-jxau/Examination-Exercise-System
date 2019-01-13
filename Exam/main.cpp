#include "stdafx.h"
#include "ExamClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ExamClient w;
	w.show();
	return a.exec();
}
