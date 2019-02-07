#include "stdafx.h"
#include "ExerciseResult.h"


ExerciseResult::ExerciseResult(QWidget *parent, Qt::WindowFlags flags)
	:QMainWindow(parent,flags)
{
	this->systemAnswer = NULL;
	this->studentAnswer = NULL;
	this->setWindowTitle(QString::fromLocal8Bit("考试结束"));
	this->setWindowState(Qt::WindowState::WindowMaximized);
	this->setCentralWidget(new QWidget());
	this->centralWidget()->setLayout(new QHBoxLayout());

	QWidget* widgetUserInfo = new QWidget();
	widgetUserInfo->setLayout(new QVBoxLayout());
	widgetUserInfo->setFixedWidth(200);
	widgetUserInfo->setContentsMargins(0, 0, 0, 0)
		;
	widgetUserInfo->layout()->setAlignment(Qt::Alignment::enum_type::AlignHCenter);
	this->labelHeadpartrait = new QLabel();
	this->labelHeadpartrait->setPixmap(QPixmap(QString::fromLocal8Bit(SystemVariable::RESOURCEPATH) + QString::fromLocal8Bit(SystemVariable::THEMEPATH) + QString::fromLocal8Bit(SystemVariable::ICONPTH) + "headpartrait.jpg"));
	this->labelHeadpartrait->setFixedSize(90, 90);
	this->labelUsername = new QLabel();
	this->labelUsername->setFixedHeight(40);
	QFont font = this->labelUsername->font();
	font.setFamily(SystemVariable::FONTFAMILY);
	font.setPointSize(16);
	this->labelUsername->setFont(font);
	this->labelUsername->setText(CurrentUser::getUserName());
	this->labelAccount = new QLabel();
	this->labelAccount->setFixedHeight(40);
	this->labelAccount->setText(CurrentUser::getAccount());
	this->labelAccount->setFont(font);
	this->buttonBackToSelectExercise = new QPushButton();
	this->buttonBackToSelectExercise->setFixedHeight(40);
	this->buttonBackToSelectExercise->setFixedWidth(120);
	this->buttonBackToSelectExercise->setText(QString::fromLocal8Bit("选择习题集"));
	widgetUserInfo->layout()->addWidget(this->labelHeadpartrait);
	widgetUserInfo->layout()->addWidget(this->labelUsername);
	widgetUserInfo->layout()->addWidget(this->labelAccount);
	widgetUserInfo->layout()->addWidget(new QWidget());
	widgetUserInfo->layout()->addWidget(this->buttonBackToSelectExercise);

	QTabWidget* widgetMarkInfo = new QTabWidget();

	QWidget* widgetSummary = new QWidget();
	QPalette palette = widgetSummary->palette();
	palette.setBrush(QPalette::ColorRole::Window, QBrush(QPixmap(SystemVariable::getImagePath() + QString::fromLocal8Bit("background.jpg"))));
	widgetSummary->setPalette(palette);
	widgetSummary->setAutoFillBackground(true);
	widgetSummary->setLayout(new QVBoxLayout());
	widgetSummary->layout()->setContentsMargins(100, 200, 0, 200);
	this->labelTotalMark = new QLabel();
	font = this->labelTotalMark->font();
	font.setPointSize(26);
	this->labelTotalMark->setFont(font);
	this->labelTotalMark->setText(QString::fromLocal8Bit("总分:") + QString::number(CurrentUser::getMark()));
	widgetSummary->layout()->addWidget(this->labelTotalMark);
	if (CurrentUser::getExerciseSet().getNumberOfChoice() > 0)
	{
		this->labelChoiceMark = new QLabel();
		font.setPointSize(16);
		this->labelChoiceMark->setFont(font);
		QString text = QString::fromLocal8Bit("选择题:")+QString::number(CurrentUser::getMarkOfChoice())+
			QString::fromLocal8Bit("\t")+QString::number(CurrentUser::getRightOfChoice())+QString::fromLocal8Bit("/")+QString::number(CurrentUser::getExerciseSet().getNumberOfChoice());
		this->labelChoiceMark->setText(text);
		widgetSummary->layout()->addWidget(this->labelChoiceMark);
	}
	if (CurrentUser::getExerciseSet().getNumberOfJudge() > 0)
	{
		this->labelJudgeMark = new QLabel();
		font.setPointSize(16);
		this->labelJudgeMark->setFont(font);
		QString text = QString::fromLocal8Bit("判断题:") + QString::number(CurrentUser::getMarkOfJudge()) +
			QString::fromLocal8Bit("\t") + QString::number(CurrentUser::getRightOfJudge()) + QString::fromLocal8Bit("/") + QString::number(CurrentUser::getExerciseSet().getNumberOfJudge());
		this->labelJudgeMark->setText(text);
		widgetSummary->layout()->addWidget(this->labelJudgeMark);
	}
	if (CurrentUser::getExerciseSet().getNumberFillInTheBlanks() > 0)
	{
		this->labelFillInTheBlanksMark = new QLabel();
		font.setPointSize(16);
		this->labelFillInTheBlanksMark->setFont(font);
		QString text = QString::fromLocal8Bit("填空题:") + QString::number(CurrentUser::getMarkOfFillInTheBlanks()) +
			QString::fromLocal8Bit("\t") + QString::number(CurrentUser::getRightOfFillInTheBlanks()) + QString::fromLocal8Bit("/") + QString::number(CurrentUser::getExerciseSet().getNumberFillInTheBlanks());
		this->labelFillInTheBlanksMark->setText(text);
		widgetSummary->layout()->addWidget(this->labelFillInTheBlanksMark);
	}
	if (CurrentUser::getExerciseSet().getNumberOfSAQ() > 0)
	{
		this->labelSAQMark = new QLabel();
		font.setPointSize(16);
		this->labelSAQMark->setFont(font);
		QString text = QString::fromLocal8Bit("简答题:") + QString::number(CurrentUser::getMarkOfSAQ()) +
			QString::fromLocal8Bit("\t") + QString::number(CurrentUser::getRightOfSAQ()) + QString::fromLocal8Bit("/") + QString::number(CurrentUser::getExerciseSet().getNumberOfSAQ());
		this->labelSAQMark->setText(text);
		widgetSummary->layout()->addWidget(this->labelSAQMark);
	}
	QWidget* widgetDetails = new QWidget();
	widgetDetails->setLayout(new QVBoxLayout());
	Splitter* splitter=new Splitter();
	splitter->setOrientation(Qt::Orientation::Vertical);
	splitter->setChildrenCollapsible(false);
	listwidgetExercise = new ExerciseList();
	ExerciseSet exerciseSet = CurrentUser::getExerciseSet();
	listwidgetExercise->addExerciseSet(exerciseSet);
	splitter->addWidget(listwidgetExercise);
	QFrame* widgetAnswer = new QFrame();
	widgetAnswer->setFrameShape(QFrame::Shape::Panel);
	QTabWidget* tabwidgetAnswer = new QTabWidget();
	widgetSystemAnswer = new QWidget();
	widgetSystemAnswer->setLayout(new QVBoxLayout());
	widgetStudentAnswer = new QWidget();
	widgetStudentAnswer->setLayout(new QVBoxLayout());
	tabwidgetAnswer->insertTab(0, widgetSystemAnswer, QString::fromLocal8Bit("参考答案"));
	tabwidgetAnswer->insertTab(1, widgetStudentAnswer, QString::fromLocal8Bit("学生答案"));
	widgetAnswer->setLayout(new QVBoxLayout());
	widgetAnswer->setMinimumHeight(200);
	widgetAnswer->layout()->addWidget(tabwidgetAnswer);
	splitter->addWidget(widgetAnswer);
	widgetDetails->layout()->addWidget(splitter);
	widgetMarkInfo->insertTab(0, widgetSummary, QString::fromLocal8Bit("概述"));
	widgetMarkInfo->insertTab(1, widgetDetails, QString::fromLocal8Bit("详细"));

	this->centralWidget()->layout()->addWidget(widgetUserInfo);
	this->centralWidget()->layout()->addWidget(widgetMarkInfo);
	//选中第一题
	if(this->listwidgetExercise->count()>1)
		this->listwidgetExercise->setItemSelected(this->listwidgetExercise->item(1), true);
	qDebug() << CurrentUser::getExerciseSet().getExercise();
	if(exerciseSet.getExercise().size()>0)
		this->setAnswer(exerciseSet.getExercise().at(0));
	connect(this->listwidgetExercise, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slotExerciseSelected(QListWidgetItem*)));
}

void ExerciseResult::setAnswer(Exercise * exercise)
{
	if (exercise->getType() == Exercise::ExerciseType::Choice)
	{
		ChoiceExercise* cExercise = static_cast<ChoiceExercise*>(exercise);
		if (this->systemAnswer != NULL)
		{
			this->widgetSystemAnswer->layout()->removeWidget(this->systemAnswer);
			delete this->systemAnswer;
		}
		if (this->studentAnswer != NULL)
		{
			this->widgetStudentAnswer->layout()->removeWidget(this->studentAnswer);
			delete this->studentAnswer;
		}
		this->systemAnswer = new AnswerChoice();
		static_cast<AnswerChoice*>(this->systemAnswer)->fill(cExercise->getOptions());
		this->widgetSystemAnswer->layout()->addWidget(this->systemAnswer);
		this->studentAnswer = new AnswerChoice();
		static_cast<AnswerChoice*>(this->studentAnswer)->fill(cExercise->getOptions());
		this->widgetStudentAnswer->layout()->addWidget(this->studentAnswer);
		this->systemAnswer->setAnswer(exercise->getAnswer());
	}
	if (exercise->getType() == Exercise::ExerciseType::Judge)
	{
		if (this->systemAnswer != NULL)
		{
			this->widgetSystemAnswer->layout()->removeWidget(this->systemAnswer);
			delete this->systemAnswer;
		}
		if (this->studentAnswer != NULL)
		{
			this->widgetStudentAnswer->layout()->removeWidget(this->studentAnswer);
			delete this->studentAnswer;
		}
		this->systemAnswer = new AnswerJudge();
		this->systemAnswer->setAnswer(exercise->getAnswer());
		this->widgetSystemAnswer->layout()->addWidget(this->systemAnswer);
		this->studentAnswer = new AnswerJudge();
		this->widgetStudentAnswer->layout()->addWidget(this->studentAnswer);
	}

	if (exercise->getType() == Exercise::ExerciseType::FillInTheBlanks)
	{
		FillInTheBlanksExercise* fExercise = static_cast<FillInTheBlanksExercise*>(exercise);
		if (this->systemAnswer != NULL)
		{
			this->widgetSystemAnswer->layout()->removeWidget(this->systemAnswer);
			delete this->systemAnswer;
		}
		if (this->studentAnswer != NULL)
		{
			this->widgetStudentAnswer->layout()->removeWidget(this->studentAnswer);
			delete this->studentAnswer;
		}
		this->systemAnswer = new AnswerFillInTheBlanks();
		static_cast<AnswerFillInTheBlanks*>(this->systemAnswer)->setNumberOfBlanks(fExercise->getNumOfBlanks());
		this->widgetSystemAnswer->layout()->addWidget(this->systemAnswer);
		this->studentAnswer = new AnswerFillInTheBlanks();
		static_cast<AnswerFillInTheBlanks*>(this->studentAnswer)->setNumberOfBlanks(fExercise->getNumOfBlanks());
		this->widgetStudentAnswer->layout()->addWidget(this->studentAnswer);
		this->systemAnswer->setAnswer(exercise->getAnswer());
	}

	if (exercise->getType() == Exercise::ExerciseType::SAQ)
	{
		if (this->systemAnswer != NULL)
		{
			this->widgetSystemAnswer->layout()->removeWidget(this->systemAnswer);
			delete this->systemAnswer;
		}
		if (this->studentAnswer != NULL)
		{
			this->widgetStudentAnswer->layout()->removeWidget(this->studentAnswer);
			delete this->studentAnswer;
		}
		this->systemAnswer = new AnswerSAQ();
		this->widgetSystemAnswer->layout()->addWidget(this->systemAnswer);
		this->studentAnswer = new AnswerSAQ();
		this->widgetStudentAnswer->layout()->addWidget(this->studentAnswer);
		this->systemAnswer->setAnswer(exercise->getAnswer());
	}
}


ExerciseResult::~ExerciseResult()
{
}

void ExerciseResult::slotExerciseSelected(QListWidgetItem * item)
{
	ExerciseListItem* eItem = static_cast<ExerciseListItem*>(item);
	if (this->listwidgetExercise->isUnSubjectItem(item))
		return;
	int  index = eItem->getIndexInExerciseSet();
	this->setAnswer(CurrentUser::getExerciseSet().getExercise().at(index));
}
