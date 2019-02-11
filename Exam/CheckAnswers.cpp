#include "stdafx.h"
#include "CheckAnswers.h"


CheckAnswers::CheckAnswers(QWidget *parent, Qt::WindowFlags flags)
{
	this->rightOfChoice = 0;
	this->rightOfJudge = 0;
	this->rightOfFillInTheBlanks = 0;
	this->rightOfSAQ = 0;
	this->totalOfChoice = 0;
	this->totalOfJudge = 0;
	this->totalOfFillInTheBlanks = 0;
	this->totalOfSAQ = 0;
	this->markOfChoice = 0;
	this->markOfJudge = 0;
	this->markOfFillInTheBlanks = 0;
	this->markOfSAQ = 0;


	QMainWindow(parent, flags);
	QWidget* centerWidget = new QWidget();
	centerWidget->setLayout(new QVBoxLayout());
	centerWidget->layout()->setAlignment(Qt::AlignCenter);
	QLabel* label = new QLabel();
	QFont font = label->font();
	font.setPixelSize(24);
	label->setFont(font);
	label->setText(QString::fromLocal8Bit("ÕýÔÚºËËã´ð°¸..."));
	centerWidget->layout()->addWidget(label);
	this->setCentralWidget(centerWidget);
	this->setFixedWidth(800);
	this->setFixedHeight(100);
	this->move(QApplication::desktop()->width() / 2 - this->width() / 2, QApplication::desktop()->height() / 2 - this->height() / 2);
	this->setWindowFlags(Qt::WindowFlags::enum_type::FramelessWindowHint);
}


CheckAnswers::~CheckAnswers()
{
}

void CheckAnswers::slotUserCommit()
{
	this->Check();
	this->GenerateMark();
	CurrentUser::setRightOfChoice(this->rightOfChoice);
	CurrentUser::setRightOfJudge(this->rightOfJudge);
	CurrentUser::setRightOfFillInTheBlanks(this->rightOfFillInTheBlanks);
	CurrentUser::setRightOfSAQ(this->rightOfSAQ);
	CurrentUser::setSingleMarkList(this->markOfSingleExercise);
	CurrentUser::setMark(this->totalMark);
	CurrentUser::setMarkOfChoice(this->markOfChoice);
	CurrentUser::setMarkOfJudge(this->markOfJudge);
	CurrentUser::setMarkOfFillInTheBlanks(this->markOfFillInTheBlanks);
	CurrentUser::setMarkOfSAQ(this->markOfSAQ);
	ExerciseResult* result = new ExerciseResult();
	result->show();
	this->close();
}

void CheckAnswers::Check()
{
	for (int i = 0; i < CurrentUser::getExerciseSet().getExercise().size(); i++)
	{
		double mark = 0;
		Exercise* exercise = CurrentUser::getExerciseSet().getExercise().at(i);
		UserAnswer* answer = CurrentUser::getExerciseSet().getAnswers().at(i);
		if (exercise->getType() == Exercise::ExerciseType::Choice)
		{
			this->totalOfChoice++;
			if (exercise->getAnswer() == answer->getAnswer().toString())
			{
				mark = static_cast<double>(CurrentUser::getExerciseSet().getMarkOfChoice()) / CurrentUser::getExerciseSet().getNumberOfChoice();
				this->rightOfChoice++;
				this->markOfChoice += mark;
				answer->right = true;
			}
		}

		if (exercise->getType() == Exercise::ExerciseType::Judge)
		{
			this->totalOfJudge++;
			bool isCorrect = false;
			if (exercise->getAnswer() == "true")
			{
				isCorrect = true;
			}
			if (isCorrect == answer->getAnswer().toBool())
			{
				mark = static_cast<double>(CurrentUser::getExerciseSet().getMarkOfJudge()) / CurrentUser::getExerciseSet().getNumberOfJudge();
				this->rightOfJudge++;
				this->markOfJudge += mark;
				answer->right = true;
			}
		}

		if (exercise->getType() == Exercise::ExerciseType::FillInTheBlanks)
		{
			int numOfRightFillInTheBlanks = 0;
			this->totalOfFillInTheBlanks++;
			QList<QString> userAnswers = answer->getAnswer().value<QList<QString>>();
			QList<QString> rightAnswers = exercise->getAnswer().split("\n");
			for (int j = 0; j < userAnswers.size(); j++)
			{
				if (rightAnswers.contains(userAnswers.at(j)))
				{
					this->rightOfFillInTheBlanks++;
					numOfRightFillInTheBlanks++;
				}
			}

			mark=(static_cast<double>(numOfRightFillInTheBlanks)/static_cast<FillInTheBlanksExercise*>(exercise)->getNumOfBlanks())*
				static_cast<double>(CurrentUser::getExerciseSet().getMarkOfFillInTheBlanks()) / CurrentUser::getExerciseSet().getNumberFillInTheBlanks();
			this->markOfFillInTheBlanks += mark;
			if (mark > 0)
			{
				answer->right = true;
				if (numOfRightFillInTheBlanks < static_cast<FillInTheBlanksExercise*>(exercise)->getNumOfBlanks())
				{
					answer->half = true;
				}
			}
		}

		if (exercise->getType() == Exercise::ExerciseType::SAQ)
		{
			this->totalOfSAQ++;
			QString userAnswer = answer->getAnswer().value<QString>();
			QString rightAnswer = exercise->getAnswer();
			if (userAnswer == rightAnswer)
			{
				this->rightOfSAQ++;
				mark = static_cast<double>(CurrentUser::getExerciseSet().getMarkOfSAQ()) / CurrentUser::getExerciseSet().getNumberOfSAQ();
				this->markOfSAQ += mark;
				answer->right = true;
			}
		}

		this->markOfSingleExercise.append(mark);
	}
}

void CheckAnswers::GenerateMark()
{
	this->totalMark = 0;
	for (int i = 0; i < this->markOfSingleExercise.size(); i++)
	{
		this->totalMark += this->markOfSingleExercise.at(i);
	}
}
