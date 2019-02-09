#include "stdafx.h"
#include "Answer.h"


Answer::Answer()
{
	this->setFrameShape(QFrame::Shape::Panel);
	this->answered = false;
}

bool Answer::isAnswered()
{
	return this->answered;
}

Exercise::ExerciseType Answer::getType()
{
	return this->type;
}

Answer::~Answer()
{
}
