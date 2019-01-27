#pragma once
#include <qsplitter.h>
class Splitter :
	public QSplitter
{
public:
	Splitter();
	~Splitter();
protected:
	void moveSplitter(int pos, int index);
};

