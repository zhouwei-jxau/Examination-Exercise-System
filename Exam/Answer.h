#pragma once
#include <qframe.h>
class Answer :
	public QFrame
{
public:
	Answer();
	virtual QVariant getAnswer()=0;
	~Answer();
};

