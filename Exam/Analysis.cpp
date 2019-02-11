#include "stdafx.h"
#include "Analysis.h"


Analysis::Analysis()
{
	this->textedit = new QTextEdit();
	this->textedit->setEnabled(false);
	this->setLayout(new QVBoxLayout());
	this->layout()->addWidget(this->textedit);
}

void Analysis::setAnalysis(QString text)
{
	this->textedit->setText(text);
}

QString Analysis::getAnslysis(QString text)
{
	return this->textedit->toHtml();
}


Analysis::~Analysis()
{
}
