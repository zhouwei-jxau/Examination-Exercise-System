#pragma once
#include <qlabel.h>
class LinkButton :
	public QLabel
{
	Q_OBJECT
public:
	LinkButton();
	void setText(QString text);
	~LinkButton();
signals:
	void clicked();
protected:
	void mousePressEvent(QMouseEvent* event);
	void enterEvent(QEvent* event);
	void leaveEvent(QEvent* event);
private:
	QString text;
};

