#pragma once
#include <qwidget.h>
class Analysis :
	public QWidget
{
public:
	Analysis();
	void setAnalysis(QString text);
	QString getAnslysis(QString text);
	~Analysis();
private:
	QTextEdit* textedit;
};

