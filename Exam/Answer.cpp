#include "stdafx.h"
#include "Answer.h"


Answer::Answer()
{
	this->setFrameShape(QFrame::Shape::Panel);
}

Exercise::ExerciseType Answer::getType()
{
	return this->type;
}

Answer::~Answer()
{
}
