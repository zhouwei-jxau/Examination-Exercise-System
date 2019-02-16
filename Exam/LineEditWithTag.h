#pragma once
#include <qwidget.h>
class LineEditWithTag :
	public QWidget
{
public:
	LineEditWithTag();
	void setTag(QString& tag);
	void setHintText(QString& text);
	void setText(QString text);
	QString getText();
	~LineEditWithTag();
private:
	QLineEdit* lineedit;
	QLabel* label;
};

