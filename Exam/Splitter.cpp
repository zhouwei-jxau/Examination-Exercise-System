#include "stdafx.h"
#include "Splitter.h"


Splitter::Splitter()
{
}


Splitter::~Splitter()
{
}

void Splitter::moveSplitter(int pos, int index)
{
	qDebug() << pos << "\t" << index;
	QSplitter::moveSplitter(pos, index);
}
