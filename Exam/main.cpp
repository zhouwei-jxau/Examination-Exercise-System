#include "stdafx.h"
#include "ExamClient.h"
#include "CheckVersion.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CheckVersion checkVersion;
	checkVersion.show();
	return a.exec();
}
