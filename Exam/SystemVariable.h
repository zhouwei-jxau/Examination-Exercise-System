#pragma once
class SystemVariable
{
public:
	const static int VERSION = 0;
	const static int SERVERPORT = 8080;
	const static char* const SERVER;
	const static char* const CHECKVERSIONSERVLET;
public:
	SystemVariable();
	~SystemVariable();
};

