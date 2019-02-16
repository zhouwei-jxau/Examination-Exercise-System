#include "stdafx.h"
#include "ExerciseList.h"
#include "SystemVariable.h"

ExerciseList::ExerciseList()
{
	this->showCheckResult = false;
	this->pathOfUnFold = QString::fromLocal8Bit(SystemVariable::RESOURCEPATH) + SystemVariable::THEMEPATH + SystemVariable::ICONPTH + "unfold.png";
	this->pathOfFold = QString::fromLocal8Bit(SystemVariable::RESOURCEPATH) + SystemVariable::THEMEPATH + SystemVariable::ICONPTH + "fold.png";
	this->isChoiceFold = false;
	this->isJudgeFold = false;
	this->isFillInTheBlanksFold = false;
	this->isSAQFold = false;
	this->numOfChoice = 0;
	this->numOfJudge = 0;
	this->numOfFillInTheBlanks = 0;
	this->numOfSAQ = 0;
	QLabel* label = NULL;
	this->widgetChoiceFolder = new QWidget();
	this->widgetChoiceFolder->setLayout(new QHBoxLayout());
	this->widgetChoiceFolder->layout()->setContentsMargins(0, 0, 0, 0);
	label = new QLabel();
	label->setFixedWidth(32);
	label->setPixmap(QPixmap(this->pathOfUnFold));
	this->widgetChoiceFolder->layout()->addWidget(label);
	label = new QLabel();
	QFont font = label->font();
	font.setFamily(SystemVariable::FONTFAMILY);
	font.setPixelSize(18);
	label->setFont(font);
	label->setText(QString::fromLocal8Bit("选择题"));
	this->widgetChoiceFolder->layout()->addWidget(label);
	this->widgetJudgeFolder = new QWidget();
	this->widgetJudgeFolder->setLayout(new QHBoxLayout());
	this->widgetJudgeFolder->layout()->setContentsMargins(0, 0, 0, 0);
	label = new QLabel();
	label->setFixedWidth(32);
	label->setPixmap(QPixmap(this->pathOfUnFold));
	this->widgetJudgeFolder->layout()->addWidget(label);
	label = new QLabel();
	label->setFont(font);
	label->setText(QString::fromLocal8Bit("判断题"));
	this->widgetJudgeFolder->layout()->addWidget(label);
	this->widgetFillInTheBlanksFolder = new QWidget();
	this->widgetFillInTheBlanksFolder->setLayout(new QHBoxLayout());
	this->widgetFillInTheBlanksFolder->layout()->setContentsMargins(0, 0, 0, 0);
	label = new QLabel();
	label->setFixedWidth(32);
	label->setPixmap(QPixmap(this->pathOfUnFold));
	this->widgetFillInTheBlanksFolder->layout()->addWidget(label);
	label = new QLabel();
	label->setFont(font);
	label->setText(QString::fromLocal8Bit("填空题"));
	this->widgetFillInTheBlanksFolder->layout()->addWidget(label);
	this->widgetSAQFolder = new QWidget();
	this->widgetSAQFolder->setLayout(new QHBoxLayout());
	this->widgetSAQFolder->layout()->setContentsMargins(0, 0, 0, 0);
	label = new QLabel();
	label->setFixedWidth(32);
	label->setPixmap(QPixmap(this->pathOfUnFold));
	this->widgetSAQFolder->layout()->addWidget(label);
	label = new QLabel();
	label->setFont(font);
	label->setText(QString::fromLocal8Bit("简答题"));
	this->widgetSAQFolder->layout()->addWidget(label);
	QListWidgetItem* item = new QListWidgetItem();
	this->unSubjectItems.append(item);
	item->setSizeHint(QSize(-1, 32));
	this->addItem(item);
	this->setItemWidget(item, this->widgetChoiceFolder);
	this->itemChoiceFolder = item;
	item = new QListWidgetItem();
	this->unSubjectItems.append(item);
	item->setSizeHint(QSize(-1, 32));
	this->addItem(item);
	this->setItemWidget(item, this->widgetJudgeFolder);
	this->itemJudgeFolder = item;
	item = new QListWidgetItem();
	this->unSubjectItems.append(item);
	item->setSizeHint(QSize(-1, 32));
	this->addItem(item);
	this->setItemWidget(item, this->widgetFillInTheBlanksFolder);
	this->itemFillInTheBlanksFolder = item;
	item = new QListWidgetItem();	
	this->unSubjectItems.append(item);
	item->setSizeHint(QSize(-1, 32));
	this->addItem(item);
	this->setItemWidget(item, this->widgetSAQFolder);
	this->itemSAQFolder = item;
	this->buttonGroup = new QButtonGroup(this);
	connect(this, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slotItemClicked(QListWidgetItem*)));
	connect(this->buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(slotAddToErrorBookClicked(QAbstractButton *)));
}


void ExerciseList::addExercise(Exercise * exercise,int index)
{
	if (exercise->getType() == Exercise::ExerciseType::Choice)
	{
		this->addChoice(exercise->getSubject(),index);
	}
	if (exercise->getType() == Exercise::ExerciseType::Judge)
	{
		this->addJudge(exercise->getSubject(),index);
	}
	if (exercise->getType() == Exercise::ExerciseType::FillInTheBlanks)
	{
		this->addFillInTheBlanks(exercise->getSubject(),index);
	}
	if (exercise->getType() == Exercise::ExerciseType::SAQ)
	{
		this->addSAQ(exercise->getSubject(),index);
	}
}

void ExerciseList::addChoice(QString subject,int index)
{
	ExerciseListItem* item = new ExerciseListItem();
	item->setIndexInExerciseSet(index);
	item->setText(QString::number(this->numOfChoice + 1) + "." + subject);
	QWidget* widget = new QWidget();
	QPushButton* addToErrorBook = new QPushButton();
	addToErrorBook->setIcon(QIcon(SystemVariable::getIconPath() + ExerciseListItem::PATHOFADDTOERRORBOOKICONPATH));
	addToErrorBook->setIconSize(QSize(14, 14));
	addToErrorBook->setFlat(true);
	addToErrorBook->setFixedSize(QSize(16, 16));
	addToErrorBook->setToolTip(QString::fromLocal8Bit("添加到错题本"));
	buttonGroup->addButton(addToErrorBook);
	this->addToErrorBookButtonIndexInExerciseSet.insert(addToErrorBook, index);
	widget->setLayout(new QHBoxLayout());
	widget->layout()->setContentsMargins(0, 0, 0, 0);
	widget->layout()->setAlignment(Qt::AlignLeft);
	widget->layout()->addWidget(addToErrorBook);
	this->insertItem(this->row(this->itemJudgeFolder),item);
	this->setItemWidget(item,widget);
	this->numOfChoice++;
	if (this->isShowCheckResult())
	{
		if (CurrentUser::getExerciseSet().getAnswers().at(index)->isMarked() == false)
		{
			if (CurrentUser::getExerciseSet().getAnswers().at(index)->isAnswered())
			{
				if (CurrentUser::getExerciseSet().getAnswers().at(index)->isRight())
				{
					if (CurrentUser::getExerciseSet().getAnswers().at(index)->isHalf())
					{
						item->setStatus(Exercise::ExerciseStatus::Half);
					}
					else
					{
						item->setStatus(Exercise::ExerciseStatus::Right);
					}
				}
			}
			else
			{
				item->setStatus(Exercise::ExerciseStatus::Error);
			}
		}
		else
		{
			item->setStatus(Exercise::ExerciseStatus::Flag);
		}
	}
	if (this->numOfChoice == 0)
	{
		this->itemChoiceFolder->setHidden(true);
	}
	else
	{
		this->itemChoiceFolder->setHidden(false);
	}
	if (this->numOfFillInTheBlanks == 0)
	{
		this->itemFillInTheBlanksFolder->setHidden(true);
	}
	else
	{
		this->itemFillInTheBlanksFolder->setHidden(false);
	}
	if (this->numOfJudge == 0)
	{
		this->itemJudgeFolder->setHidden(true);
	}
	else
	{
		this->itemJudgeFolder->setHidden(false);
	}
	if (this->numOfSAQ == 0)
	{
		this->itemSAQFolder->setHidden(true);
	}
	else
	{
		this->itemSAQFolder->setHidden(false);
	}
}

void ExerciseList::addJudge(QString subject,int index)
{
	ExerciseListItem* item = new ExerciseListItem();
	item->setIndexInExerciseSet(index);
	item->setText(QString::number(this->numOfJudge + 1) + "." + subject);
	QWidget* widget = new QWidget();
	QPushButton* addToErrorBook = new QPushButton();
	addToErrorBook->setIcon(QIcon(SystemVariable::getIconPath() + ExerciseListItem::PATHOFADDTOERRORBOOKICONPATH));
	addToErrorBook->setIconSize(QSize(14, 14));
	addToErrorBook->setFlat(true);
	addToErrorBook->setFixedSize(QSize(16, 16));
	addToErrorBook->setToolTip(QString::fromLocal8Bit("添加到错题本"));
	buttonGroup->addButton(addToErrorBook);
	this->addToErrorBookButtonIndexInExerciseSet.insert(addToErrorBook, index);	widget->setLayout(new QHBoxLayout());
	widget->layout()->setContentsMargins(0, 0, 0, 0);
	widget->layout()->setAlignment(Qt::AlignLeft);
	widget->layout()->addWidget(addToErrorBook);
	this->insertItem(this->row(this->itemFillInTheBlanksFolder), item);
	this->setItemWidget(item, widget);
	this->numOfJudge++;
	if (this->isShowCheckResult())
	{
		if (CurrentUser::getExerciseSet().getAnswers().at(index)->isMarked() == false)
		{
			if (CurrentUser::getExerciseSet().getAnswers().at(index)->isAnswered())
			{
				if (CurrentUser::getExerciseSet().getAnswers().at(index)->isRight())
				{
					if (CurrentUser::getExerciseSet().getAnswers().at(index)->isHalf())
					{
						item->setStatus(Exercise::ExerciseStatus::Half);
					}
					else
					{
						item->setStatus(Exercise::ExerciseStatus::Right);
					}
				}
			}
			else
			{
				item->setStatus(Exercise::ExerciseStatus::Error);
			}
		}
		else
		{
			item->setStatus(Exercise::ExerciseStatus::Flag);
		}
	}
	if (this->numOfChoice == 0)
	{
		this->itemChoiceFolder->setHidden(true);
	}
	else
	{
		this->itemChoiceFolder->setHidden(false);
	}
	if (this->numOfFillInTheBlanks == 0)
	{
		this->itemFillInTheBlanksFolder->setHidden(true);
	}
	else
	{
		this->itemFillInTheBlanksFolder->setHidden(false);
	}
	if (this->numOfJudge == 0)
	{
		this->itemJudgeFolder->setHidden(true);
	}
	else
	{
		this->itemJudgeFolder->setHidden(false);
	}
	if (this->numOfSAQ == 0)
	{
		this->itemSAQFolder->setHidden(true);
	}
	else
	{
		this->itemSAQFolder->setHidden(false);
	}
}

void ExerciseList::addFillInTheBlanks(QString subject,int index)
{
	ExerciseListItem* item = new ExerciseListItem();
	item->setIndexInExerciseSet(index);
	item->setText(QString::number(this->numOfFillInTheBlanks + 1) + "." + subject);
	QWidget* widget = new QWidget();
	QPushButton* addToErrorBook = new QPushButton();
	addToErrorBook->setIcon(QIcon(SystemVariable::getIconPath() + ExerciseListItem::PATHOFADDTOERRORBOOKICONPATH));
	addToErrorBook->setIconSize(QSize(14, 14));
	addToErrorBook->setFlat(true);
	addToErrorBook->setFixedSize(QSize(16, 16));
	addToErrorBook->setToolTip(QString::fromLocal8Bit("添加到错题本"));
	buttonGroup->addButton(addToErrorBook);
	this->addToErrorBookButtonIndexInExerciseSet.insert(addToErrorBook, index);	widget->setLayout(new QHBoxLayout());
	widget->layout()->setContentsMargins(0, 0, 0, 0);
	widget->layout()->setAlignment(Qt::AlignLeft);
	widget->layout()->addWidget(addToErrorBook);
	this->insertItem(this->row(this->itemSAQFolder), item);
	this->setItemWidget(item, widget);
	this->numOfFillInTheBlanks++;
	if (this->isShowCheckResult())
	{
		if (CurrentUser::getExerciseSet().getAnswers().at(index)->isMarked() == false)
		{
			if (CurrentUser::getExerciseSet().getAnswers().at(index)->isAnswered())
			{
				if (CurrentUser::getExerciseSet().getAnswers().at(index)->isRight())
				{
					if (CurrentUser::getExerciseSet().getAnswers().at(index)->isHalf())
					{
						item->setStatus(Exercise::ExerciseStatus::Half);
					}
					else
					{
						item->setStatus(Exercise::ExerciseStatus::Right);
					}
				}
			}
			else
			{
				item->setStatus(Exercise::ExerciseStatus::Error);
			}
		}
		else
		{
			item->setStatus(Exercise::ExerciseStatus::Flag);
		}
	}
	if (this->numOfChoice == 0)
	{
		this->itemChoiceFolder->setHidden(true);
	}
	else
	{
		this->itemChoiceFolder->setHidden(false);
	}
	if (this->numOfFillInTheBlanks == 0)
	{
		this->itemFillInTheBlanksFolder->setHidden(true);
	}
	else
	{
		this->itemFillInTheBlanksFolder->setHidden(false);
	}
	if (this->numOfJudge == 0)
	{
		this->itemJudgeFolder->setHidden(true);
	}
	else
	{
		this->itemJudgeFolder->setHidden(false);
	}
	if (this->numOfSAQ == 0)
	{
		this->itemSAQFolder->setHidden(true);
	}
	else
	{
		this->itemSAQFolder->setHidden(false);
	}
}

void ExerciseList::addSAQ(QString subject,int index)
{
	ExerciseListItem* item = new ExerciseListItem();
	item->setIndexInExerciseSet(index);
	item->setText(QString::number(this->numOfSAQ + 1) + "." + subject);
	QWidget* widget = new QWidget();
	QPushButton* addToErrorBook = new QPushButton();
	addToErrorBook->setIcon(QIcon(SystemVariable::getIconPath() + ExerciseListItem::PATHOFADDTOERRORBOOKICONPATH));
	addToErrorBook->setIconSize(QSize(14, 14));
	addToErrorBook->setFlat(true);
	addToErrorBook->setFixedSize(QSize(16, 16));
	addToErrorBook->setToolTip(QString::fromLocal8Bit("添加到错题本"));
	buttonGroup->addButton(addToErrorBook);
	this->addToErrorBookButtonIndexInExerciseSet.insert(addToErrorBook, index);	widget->setLayout(new QHBoxLayout());
	widget->layout()->setContentsMargins(0, 0, 0, 0);
	widget->layout()->setAlignment(Qt::AlignLeft);
	widget->layout()->addWidget(addToErrorBook);
	this->addItem(item);
	this->setItemWidget(item, widget);	this->numOfSAQ++;

	if (this->isShowCheckResult())
	{
		if (CurrentUser::getExerciseSet().getAnswers().at(index)->isMarked() == false)
		{
			if (CurrentUser::getExerciseSet().getAnswers().at(index)->isAnswered())
			{
				if (CurrentUser::getExerciseSet().getAnswers().at(index)->isRight())
				{
					if (CurrentUser::getExerciseSet().getAnswers().at(index)->isHalf())
					{
						item->setStatus(Exercise::ExerciseStatus::Half);
					}
					else
					{
						item->setStatus(Exercise::ExerciseStatus::Right);
					}
				}
			}
			else
			{
				item->setStatus(Exercise::ExerciseStatus::Error);
			}
		}
		else
		{
			item->setStatus(Exercise::ExerciseStatus::Flag);
		}
	}
	if (this->numOfChoice == 0)
	{
		this->itemChoiceFolder->setHidden(true);
	}
	else
	{
		this->itemChoiceFolder->setHidden(false);
	}
	if (this->numOfFillInTheBlanks == 0)
	{
		this->itemFillInTheBlanksFolder->setHidden(true);
	}
	else
	{
		this->itemFillInTheBlanksFolder->setHidden(false);
	}
	if (this->numOfJudge == 0)
	{
		this->itemJudgeFolder->setHidden(true);
	}
	else
	{
		this->itemJudgeFolder->setHidden(false);
	}
	if (this->numOfSAQ == 0)
	{
		this->itemSAQFolder->setHidden(true);
	}
	else
	{
		this->itemSAQFolder->setHidden(false);
	}
}

void ExerciseList::addExerciseSet(ExerciseSet exerciseSet)
{
	for (int i = 0; i < exerciseSet.getExercise().size(); i++)
	{
		this->addExercise(exerciseSet.getExercise().at(i),i);
	}
}

bool ExerciseList::isUnSubjectItem(QListWidgetItem * item)
{
	for (int i = 0; i < this->unSubjectItems.size(); i++)
	{
		if (item == this->unSubjectItems.at(i))
		{
			return true;
		}
	}
	return false;
}

void ExerciseList::setShowCheckResult(bool show)
{
	this->showCheckResult = show;
}

bool ExerciseList::isShowCheckResult()
{
	return this->showCheckResult;
}

ExerciseList::~ExerciseList()
{
}

void ExerciseList::slotAddToErrorBookClicked(QAbstractButton *button)
{
	QNetworkAccessManager* httpManager = new QNetworkAccessManager(this);
	QObject::connect(httpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotGetAddtoErrorBookStatus(QNetworkReply*)));
	QString url = QString("http://") + SystemVariable::SERVER + ":" + QString::number(SystemVariable::SERVERPORT) + "/" + SystemVariable::ADDTOERRORBOOKSERVLET;
	QNetworkRequest request;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded;charset=utf-8");
	QString param = QString::fromLocal8Bit("exercise_no=")
		+ QString::number(CurrentUser::getExerciseSet().getExercise().at(this->addToErrorBookButtonIndexInExerciseSet.value(static_cast<QPushButton*>(button)))->getExerciseNo())
		+ QString::fromLocal8Bit("&exercise_type=")
		+ QString::number(CurrentUser::getExerciseSet().getExercise().at(this->addToErrorBookButtonIndexInExerciseSet.value(static_cast<QPushButton*>(button)))->getType())
		+ QString::fromLocal8Bit("&account=") + CurrentUser::getAccount();
	httpManager->post(request,param.toLocal8Bit());
	emit signalAddToErrorBookClicked();
}

void ExerciseList::slotGetAddtoErrorBookStatus(QNetworkReply * reply)
{
	QByteArray data;
	QByteArray buffer;
	while ((buffer = reply->readLine()).length() > 0)
	{
		data.append(buffer);
	}
	if (reply->attribute(QNetworkRequest::Attribute::HttpStatusCodeAttribute).toInt() != 200)
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加失败，请检查网络连接!"));
		return;
	}
	QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
	QJsonObject json = jsonDoc.object();
	int responseCode = json.value("responseCode").toInt();
	if (responseCode)
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加成功"));
	}
	else
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加成功"));
	}
}

void ExerciseList::slotItemClicked(QListWidgetItem * item)
{
	if (this->itemWidget(item) == this->widgetChoiceFolder)
	{
		if (this->isChoiceFold)
		{
			static_cast<QLabel*>(this->widgetChoiceFolder->children().at(1))->setPixmap(QPixmap(this->pathOfUnFold));
			int start = 1;
			int end = this->row(this->itemJudgeFolder);
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(false);
			}
		}
		else
		{
			static_cast<QLabel*>(this->widgetChoiceFolder->children().at(1))->setPixmap(QPixmap(this->pathOfFold));
			int start = 1;
			int end = this->row(this->itemJudgeFolder);
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(true);
			}
		}
		this->isChoiceFold = !this->isChoiceFold;
	}

	if (this->itemWidget(item) == this->widgetJudgeFolder)
	{
		if (this->isJudgeFold)
		{
			static_cast<QLabel*>(this->widgetJudgeFolder->children().at(1))->setPixmap(QPixmap(this->pathOfUnFold));
			int start = this->row(this->itemJudgeFolder)+1;
			int end = this->row(this->itemFillInTheBlanksFolder);
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(false);
			}
		}
		else
		{
			static_cast<QLabel*>(this->widgetJudgeFolder->children().at(1))->setPixmap(QPixmap(this->pathOfFold));
			int start = this->row(this->itemJudgeFolder) + 1;
			int end = this->row(this->itemFillInTheBlanksFolder);
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(true);
			}
		}
		this->isJudgeFold = !this->isJudgeFold;
	}

	if (this->itemWidget(item) == this->widgetFillInTheBlanksFolder)
	{
		if (this->isFillInTheBlanksFold)
		{
			static_cast<QLabel*>(this->widgetFillInTheBlanksFolder->children().at(1))->setPixmap(QPixmap(this->pathOfUnFold));
			int start = this->row(this->itemFillInTheBlanksFolder) + 1;
			int end = this->row(this->itemSAQFolder);
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(false);
			}
		}
		else
		{
			static_cast<QLabel*>(this->widgetFillInTheBlanksFolder->children().at(1))->setPixmap(QPixmap(this->pathOfFold));
			int start = this->row(this->itemFillInTheBlanksFolder) + 1;
			int end = this->row(this->itemSAQFolder);
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(true);
			}
		}
		this->isFillInTheBlanksFold = !this->isFillInTheBlanksFold;
	}

	if (this->itemWidget(item) == this->widgetSAQFolder)
	{
		if (this->isSAQFold)
		{
			static_cast<QLabel*>(this->widgetSAQFolder->children().at(1))->setPixmap(QPixmap(this->pathOfUnFold));
			int start = this->row(this->itemSAQFolder) + 1;
			int end = this->count();
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(false);
			}
		}
		else
		{
			static_cast<QLabel*>(this->widgetSAQFolder->children().at(1))->setPixmap(QPixmap(this->pathOfFold));
			int start = this->row(this->itemSAQFolder) + 1;
			int end = this->count();
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(true);
			}
		}
		this->isSAQFold = !this->isSAQFold;
	}
}
