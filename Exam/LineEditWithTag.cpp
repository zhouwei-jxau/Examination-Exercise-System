#include "stdafx.h"
#include "LineEditWithTag.h"


LineEditWithTag::LineEditWithTag()
{
	this->setLayout(new QHBoxLayout());
	this->layout()->setContentsMargins(0, 0, 0, 0);
	this->label = new QLabel();
	this->layout()->addWidget(this->label);
	this->lineedit = new QLineEdit();
	this->layout()->addWidget(this->lineedit);
}

void LineEditWithTag::setTag(QString& tag)
{
	this->label->setText(tag);
}

void LineEditWithTag::setHintText(QString& text)
{
	this->lineedit->setPlaceholderText(text);
}

void LineEditWithTag::setText(QString text)
{
	this->lineedit->setText(text);
}

QString LineEditWithTag::getText()
{
	return this->lineedit->text();
}


LineEditWithTag::~LineEditWithTag()
{
}
