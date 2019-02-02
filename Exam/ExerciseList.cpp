#include "stdafx.h"
#include "ExerciseList.h"
#include "SystemVariable.h"

ExerciseList::ExerciseList()
{
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
	label = new QLabel();
	label->setFixedWidth(32);
	label->setPixmap(QPixmap(this->pathOfUnFold));
	this->widgetChoiceFolder->layout()->addWidget(label);
	label = new QLabel();
	label->setText(QString::fromLocal8Bit("选择题"));
	this->widgetChoiceFolder->layout()->addWidget(label);
	this->widgetJudgeFolder = new QWidget();
	this->widgetJudgeFolder->setLayout(new QHBoxLayout());
	label = new QLabel();
	label->setFixedWidth(32);
	label->setPixmap(QPixmap(this->pathOfUnFold));
	this->widgetJudgeFolder->layout()->addWidget(label);
	label = new QLabel();
	label->setText(QString::fromLocal8Bit("判断题"));
	this->widgetJudgeFolder->layout()->addWidget(label);
	this->widgetFillInTheBlanksFolder = new QWidget();
	this->widgetFillInTheBlanksFolder->setLayout(new QHBoxLayout());
	label = new QLabel();
	label->setFixedWidth(32);
	label->setPixmap(QPixmap(this->pathOfUnFold));
	this->widgetFillInTheBlanksFolder->layout()->addWidget(label);
	label = new QLabel();
	label->setText(QString::fromLocal8Bit("填空题"));
	this->widgetFillInTheBlanksFolder->layout()->addWidget(label);
	this->widgetSAQFolder = new QWidget();
	this->widgetSAQFolder->setLayout(new QHBoxLayout());
	label = new QLabel();
	label->setFixedWidth(32);
	label->setPixmap(QPixmap(this->pathOfUnFold));
	this->widgetSAQFolder->layout()->addWidget(label);
	label = new QLabel();
	label->setText(QString::fromLocal8Bit("简答题"));
	this->widgetSAQFolder->layout()->addWidget(label);
	QListWidgetItem* item = new QListWidgetItem();
	item->setSizeHint(QSize(-1, 32));
	this->addItem(item);
	this->setItemWidget(item, this->widgetChoiceFolder);
	this->itemChoiceFolder = item;
	item = new QListWidgetItem();
	item->setSizeHint(QSize(-1, 32));
	this->addItem(item);
	this->setItemWidget(item, this->widgetJudgeFolder);
	this->itemJudgeFolder = item;
	item = new QListWidgetItem();
	item->setSizeHint(QSize(-1, 32));
	this->addItem(item);
	this->setItemWidget(item, this->widgetFillInTheBlanksFolder);
	this->itemFillInTheBlanks = item;
	item = new QListWidgetItem();
	item->setSizeHint(QSize(-1, 32));
	this->addItem(item);
	this->setItemWidget(item, this->widgetSAQFolder);
	this->itemSAQ = item;

	connect(this, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slotItemClicked(QListWidgetItem*)));
}


void ExerciseList::addExercise(Exercise * exercise)
{
	if (exercise->getType() == Exercise::ExerciseType::Choice)
	{
		this->addChoice(exercise->getSubject());
	}
	if (exercise->getType() == Exercise::ExerciseType::Judge)
	{
		this->addJudge(exercise->getSubject());
	}
	if (exercise->getType() == Exercise::ExerciseType::FillInTheBlanks)
	{
		this->addFillInTheBlanks(exercise->getSubject());
	}
	if (exercise->getType() == Exercise::ExerciseType::SAQ)
	{
		this->addSAQ(exercise->getSubject());
	}
}

void ExerciseList::addChoice(QString subject)
{
	this->insertItem(this->row(this->itemJudgeFolder), "      "+QString::number(this->numOfChoice + 1) + "." + subject);
	this->numOfChoice++;
}

void ExerciseList::addJudge(QString subject)
{
	this->insertItem(this->row(this->itemFillInTheBlanks), "      "+QString::number(this->numOfJudge + 1) + "." + subject);
	this->numOfJudge++;
}

void ExerciseList::addFillInTheBlanks(QString subject)
{
	this->insertItem(this->row(this->itemSAQ), "      "+QString::number(this->numOfFillInTheBlanks + 1) + "." + subject);
	this->numOfFillInTheBlanks++;
}

void ExerciseList::addSAQ(QString subject)
{
	this->addItem("      "+QString::number(this->numOfSAQ + 1) + "." + subject);
	this->numOfSAQ++;
}

ExerciseList::~ExerciseList()
{
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
			int end = this->row(this->itemFillInTheBlanks);
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(false);
			}
		}
		else
		{
			static_cast<QLabel*>(this->widgetJudgeFolder->children().at(1))->setPixmap(QPixmap(this->pathOfFold));
			int start = this->row(this->itemJudgeFolder) + 1;
			int end = this->row(this->itemFillInTheBlanks);
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
			int start = this->row(this->itemFillInTheBlanks) + 1;
			int end = this->row(this->itemSAQ);
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(false);
			}
		}
		else
		{
			static_cast<QLabel*>(this->widgetFillInTheBlanksFolder->children().at(1))->setPixmap(QPixmap(this->pathOfFold));
			int start = this->row(this->itemFillInTheBlanks) + 1;
			int end = this->row(this->itemSAQ);
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
			int start = this->row(this->itemSAQ) + 1;
			int end = this->count();
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(false);
			}
		}
		else
		{
			static_cast<QLabel*>(this->widgetSAQFolder->children().at(1))->setPixmap(QPixmap(this->pathOfFold));
			int start = this->row(this->itemSAQ) + 1;
			int end = this->count();
			for (int i = start; i < end; i++)
			{
				this->item(i)->setHidden(true);
			}
		}
		this->isSAQFold = !this->isSAQFold;
	}
}
