#include "stdafx.h"
#include "LinkButton.h"


LinkButton::LinkButton()
{
}


void LinkButton::setText(QString text)
{
	QLabel::setText(text);
	this->text = text;
}

LinkButton::~LinkButton()
{
}

void LinkButton::mousePressEvent(QMouseEvent * event)
{
	emit clicked();
}

void LinkButton::leaveEvent(QEvent * event)
{
	this->setContentsMargins(0, 0, 0, 0);
	this->QLabel::setText(this->text);
}

void LinkButton::enterEvent(QEvent * event)
{
	this->setContentsMargins(0, 2, 0, 0);
	this->QLabel::setText("<u>" + this->text + "</u>");
}
