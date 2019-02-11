#include "stdafx.h"
#include "SystemVariable.h"

const char* const SystemVariable::SERVER = "134.175.244.141";
const char* const SystemVariable::CHECKVERSIONSERVLET = "Exam_Exercise_System/CheckVersionServlet";
const char* const SystemVariable::REGISTSERVLET = "Exam_Exercise_System/RegistServlet";
const char* const SystemVariable::LOGINSERVLET = "Exam_Exercise_System/LoginServlet";
const char* const SystemVariable::GETEXERCISESET = "Exam_Exercise_System/GetExerciseSet";
const char* const SystemVariable::GETEXERCISESERVLET = "Exam_Exercise_System/GetExerciseServlet";
const char* const SystemVariable::CONFIGPATH = "/config/";
const char* const SystemVariable::USERFILENAME = "user";
const char* const SystemVariable::RESOURCEPATH = "Resources/";
const char* const SystemVariable::THEMEPATH = "default/";
const char* const SystemVariable::ICONPTH = "icon/";
const char* const SystemVariable::FONTFAMILY = "Î¢ÈíÑÅºÚ";
const char* const SystemVariable::IMAGEPATH = "image/";

SystemVariable::SystemVariable()
{

}

QString SystemVariable::getImagePath()
{
	return QString::fromLocal8Bit(SystemVariable::RESOURCEPATH)+QString::fromLocal8Bit(SystemVariable::THEMEPATH)+QString::fromLocal8Bit(SystemVariable::IMAGEPATH);
}

QString SystemVariable::getIconPath()
{
	return QString::fromLocal8Bit(SystemVariable::RESOURCEPATH) + QString::fromLocal8Bit(SystemVariable::THEMEPATH) + QString::fromLocal8Bit(SystemVariable::ICONPTH);;
}


SystemVariable::~SystemVariable()
{
}
