#include "stdafx.h"
#include "ExamClient.h"

ExamClient::ExamClient(QWidget *parent)
	: QMainWindow(parent)
{
	this->currentExerciseIndex = 0;
	this->setWindowTitle(QString::fromLocal8Bit("考试客户端"));
	this->setWindowState(Qt::WindowState::WindowMaximized);
	this->setCentralWidget(new QWidget());
	this->imageHeadpartrait = new QLabel();
	this->imageHeadpartrait->setFixedSize(QSize(90,90));
	this->imageHeadpartrait->setPixmap(QPixmap(SystemVariable::RESOURCEPATH + QString::fromLocal8Bit(SystemVariable::THEMEPATH) + SystemVariable::ICONPTH + QString::fromLocal8Bit("headpartrait.jpg")));
	this->labelUserName = new QLabel();
	QFont font = this->labelUserName->font();
	font.setFamily(SystemVariable::FONTFAMILY);
	font.setPointSize(14);
	this->labelUserName->setFont(font);
	this->labelUserName->setText(CurrentUser::getUserName());
	this->labelAccount = new QLabel();
	font = this->labelAccount->font();
	font.setFamily(SystemVariable::FONTFAMILY);
	font.setPointSize(14);
	this->labelAccount->setFont(font);
	this->labelAccount->setText(CurrentUser::getAccount());
	this->labelTitle = new QLabel();
	font = this->labelTitle->font();
	font.setFamily(SystemVariable::FONTFAMILY);
	font.setPointSize(30);
	font.setBold(true);
	this->labelTitle->setFont(font);
	this->labelTitle->setText(CurrentUser::getExerciseSet().getName());
	this->labelTitle->setContentsMargins(160, 0, 0, 0);
	this->labelTip = new QLabel();
	font = this->labelTip->font();
	font.setFamily(SystemVariable::FONTFAMILY);
	font.setPointSize(14);
	this->labelTip->setFont(font);
	this->labelTip->setText(QString::fromLocal8Bit("当前第") + QString::number(this->currentExerciseIndex + 1) + QString::fromLocal8Bit("题"));
	QVBoxLayout* layout = new QVBoxLayout();
	layout->setAlignment(Qt::AlignTop);
	QSplitter* splitter = new QSplitter();
	splitter->setHandleWidth(20);
	splitter->setOrientation(Qt::Vertical);

	QWidget* widgetInfo = new QWidget();
	widgetInfo->setFixedHeight(110);
	QGridLayout* gridLayoutInfo = new QGridLayout();
	gridLayoutInfo->setColumnStretch(4, 100);
	widgetInfo->setLayout(gridLayoutInfo);
	gridLayoutInfo->addWidget(this->imageHeadpartrait, 0, 0,3,1,Qt::AlignLeft|Qt::AlignTop);
	gridLayoutInfo->addWidget(this->labelAccount, 0, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	gridLayoutInfo->addWidget(this->labelUserName, 1, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	gridLayoutInfo->addWidget(this->labelTip, 2, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	gridLayoutInfo->addWidget(this->labelTitle, 0, 4, 3, 1, Qt::AlignLeft | Qt::AlignVCenter);

	QSplitter* splitterMain = new Splitter();
	splitterMain->setOrientation(Qt::Horizontal);
	QWidget* subjectWidget = new QWidget();
	subjectWidget->setLayout(new QVBoxLayout());
	subjectWidget->layout()->setContentsMargins(0, 0, 0, 0);
	subjectWidget->layout()->setSpacing(0);
	this->listwidgetExercise = new ExerciseList();
	this->listwidgetExercise->setMinimumWidth(200);
	this->buttonCommit = new QPushButton();
	this->buttonCommit->setFixedHeight(40);
	this->buttonCommit->setText(QString::fromLocal8Bit("提交"));
	subjectWidget->layout()->addWidget(this->listwidgetExercise);
	subjectWidget->layout()->addWidget(this->buttonCommit);

	QSplitter* splitterAnswer = new QSplitter();
	splitterAnswer->setOrientation(Qt::Vertical);
	splitterAnswer->setChildrenCollapsible(false);

	splitterMain->addWidget(subjectWidget);
	splitterMain->addWidget(splitterAnswer);
	splitterMain->setChildrenCollapsible(false);
	splitterMain->setStretchFactor(0, 1);
	splitterMain->setStretchFactor(1, 4);

	this->texteditSubject = new QTextEdit();
	font = this->texteditSubject->font();
	font.setFamily(SystemVariable::FONTFAMILY);
	font.setPointSize(14);
	this->texteditSubject->setReadOnly(true);
	this->texteditSubject->setFont(font);
	this->widgetAnswer = new QWidget();
	this->widgetAnswer->setLayout(new QVBoxLayout());
	this->widgetAnswer->layout()->setContentsMargins(0, 0, 0, 0);
	this->widgetAnswer->setMinimumHeight(210);
	this->answer = NULL;
	splitterAnswer->addWidget(texteditSubject);
	splitterAnswer->addWidget(this->widgetAnswer);
	splitterAnswer->setStretchFactor(0, 5);
	splitterAnswer->setStretchFactor(1, 1);

	splitter->addWidget(widgetInfo);
	splitter->addWidget(splitterMain);
	QSplitterHandle* handle = splitter->handle(1);
	if (handle)
	{
		QPalette palette=handle->palette();
		palette.setColor(QPalette::Background, Qt::gray);
		handle->setPalette(palette);
		handle->setFixedHeight(1);
		handle->setDisabled(true);
	}
	layout->addWidget(splitter);
	this->centralWidget()->setLayout(layout);

	connect(this->buttonCommit, SIGNAL(clicked()), this, SLOT(slotCommit()));
	//填充数据
	for (int i = 0; i < CurrentUser::getExerciseSet().getExercise().size(); i++)
	{
		if (i == 0)
		{
			this->texteditSubject->setText(CurrentUser::getExerciseSet().getExercise().at(0)->getSubject());
			this->setAnswer(CurrentUser::getExerciseSet().getExercise().at(0));
		}
		this->listwidgetExercise->addExercise(CurrentUser::getExerciseSet().getExercise().at(i),i);
	}
	connect(this->listwidgetExercise, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slotExerciseSelected(QListWidgetItem*)));
}

void ExamClient::slotCommit()
{
	int unAnswered = 0;
	for (int i = 0; i < CurrentUser::getExerciseSet().getExercise().size();i++)
	{
		if(CurrentUser::getExerciseSet().getAnswers().at(i)->isAnswered()==false)
			unAnswered++;
	}
	if (unAnswered > 0)
	{
		QMessageBox messageBox;
		if (messageBox.question(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("您还有") + QString::number(unAnswered) + QString::fromLocal8Bit("题未完成，确定要提交吗?")) == QMessageBox::Yes)
		{
			CheckAnswers* checkAnswer = new CheckAnswers();
			connect(this, SIGNAL(signalUserCommit()), checkAnswer, SLOT(slotUserCommit()));
			checkAnswer->show();
			emit this->signalUserCommit();
			this->close();
			return;
		}
		else
		{
			return;
		}
	}
	QMessageBox messageBox;
	if (messageBox.question(this, QString::fromLocal8Bit("提示"),
		QString::fromLocal8Bit("提交后不可再次作答，确定要提交吗?")) == QMessageBox::Yes)
	{
		CheckAnswers* checkAnswer = new CheckAnswers();
		connect(this, SIGNAL(signalUserCommit()), checkAnswer, SLOT(slotUserCommit()));
		checkAnswer->show();
		emit this->signalUserCommit();
		this->close();
		return;
	}
}

void ExamClient::setAnswer(Exercise* exercise)
{
	if (exercise->getType() == Exercise::ExerciseType::Choice)
	{
		ChoiceExercise* cExercise = static_cast<ChoiceExercise*>(exercise);
		if (this->answer != NULL)
		{
			this->widgetAnswer->layout()->removeWidget(this->answer);
			delete this->answer;
		}
		this->answer = new AnswerChoice();
		static_cast<AnswerChoice*>(this->answer)->fill(cExercise->getOptions());
		this->widgetAnswer->layout()->addWidget(this->answer);
	}
	if (exercise->getType() == Exercise::ExerciseType::Judge)
	{
		if (this->answer != NULL)
		{
			this->widgetAnswer->layout()->removeWidget(this->answer);
			delete this->answer;
		}
		this->answer = new AnswerJudge();
		this->widgetAnswer->layout()->addWidget(this->answer);
	}
	if (exercise->getType() == Exercise::ExerciseType::FillInTheBlanks)
	{
		FillInTheBlanksExercise* fExercise = static_cast<FillInTheBlanksExercise*>(exercise);
		if (this->answer != NULL)
		{
			this->widgetAnswer->layout()->removeWidget(this->answer);
			delete this->answer;
		}
		this->answer = new AnswerFillInTheBlanks();
		static_cast<AnswerFillInTheBlanks*>(this->answer)->setNumberOfBlanks(fExercise->getNumOfBlanks());
		this->widgetAnswer->layout()->addWidget(this->answer);
	}
	if (exercise->getType() == Exercise::ExerciseType::SAQ)
	{
		if (this->answer != NULL)
		{
			this->widgetAnswer->layout()->removeWidget(this->answer);
			delete this->answer;
		}
		this->answer = new AnswerSAQ();
		this->widgetAnswer->layout()->addWidget(this->answer);
	}
	connect(this->answer, SIGNAL(signalUserAnswered()), this, SLOT(slotAnswerChanged()));
}

QVariant ExamClient::getCurrentExerciseAnswer()
{
	QVariant answer=this->answer->getAnswer();
	return answer;
}

void ExamClient::slotExerciseSelected(QListWidgetItem * item)
{
	ExerciseListItem* eItem = static_cast<ExerciseListItem*>(item);
	if (this->listwidgetExercise->isUnSubjectItem(item))
		return;
	int  index = eItem->getIndexInExerciseSet();
	this->currentExerciseIndex = index;
	this->texteditSubject->setText(CurrentUser::getExerciseSet().getExercise().at(index)->getSubject());
	this->setAnswer(CurrentUser::getExerciseSet().getExercise().at(index));
	if (CurrentUser::getExerciseSet().getAnswers().at(index)->isAnswered())
	{
		this->answer->setAnswer(CurrentUser::getExerciseSet().getAnswers().at(index)->getAnswer());
	}
	this->labelTip->setText(QString::fromLocal8Bit("当前第") + QString::number(this->currentExerciseIndex + 1) + QString::fromLocal8Bit("题"));
}

void ExamClient::slotAnswerChanged()
{
	UserAnswer userAnswer;
	userAnswer.setAnswer(this->answer->getAnswer());
	userAnswer.setType(this->answer->getType());
	if(this->answer->isAnswered())
		CurrentUser::getExerciseSet().setAnswer(userAnswer,this->currentExerciseIndex);
}
