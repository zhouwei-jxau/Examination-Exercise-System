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
	const static char* const CONFIGPATH;
	const static char* const USERFILENAME;
public:
	SystemVariable();
	~SystemVariable();
};

