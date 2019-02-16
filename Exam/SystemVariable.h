#pragma once
class SystemVariable
{
public:
	const static int VERSION = 1;
	const static int SERVERPORT = 8080;
	const static char* const SERVER;
	const static char* const CHECKVERSIONSERVLET;
	const static char* const REGISTSERVLET;
	const static char* const LOGINSERVLET;
	const static char* const GETEXERCISESET;
	const static char* const GETEXERCISESERVLET;
	const static char* const ADDTOERRORBOOKSERVLET;
	const static char* const GETERROREXERCISESERVLET;
	const static char* const CONFIGPATH;
	const static char* const USERFILENAME;
	const static char* const RESOURCEPATH;
	const static char* const THEMEPATH;
	const static char* const ICONPTH;
	const static char* const IMAGEPATH;
	const static char* const FONTFAMILY;
public:
	SystemVariable();
	static QString getImagePath();
	static QString getIconPath();
	~SystemVariable();
};

