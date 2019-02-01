#include "stdafx.h"
#include "ExamClient.h"

ExamClient::ExamClient(QWidget *parent)
	: QMainWindow(parent)
{
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
	QVBoxLayout* layout = new QVBoxLayout();
	layout->setAlignment(Qt::AlignTop);
	QSplitter* splitter = new QSplitter();
	splitter->setHandleWidth(20);
	splitter->setOrientation(Qt::Vertical);

	QWidget* widgetInfo = new QWidget();
	widgetInfo->setFixedHeight(110);
	QGridLayout* gridLayoutInfo = new QGridLayout();
	widgetInfo->setLayout(gridLayoutInfo);
	gridLayoutInfo->setColumnStretch(3, 100);
	gridLayoutInfo->addWidget(this->imageHeadpartrait, 0, 0,4,1,Qt::AlignLeft|Qt::AlignTop);
	gridLayoutInfo->addWidget(this->labelAccount, 1, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	gridLayoutInfo->addWidget(this->labelUserName, 3, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);

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
	this->answer = new AnswerSAQ();
	this->answer->setMinimumHeight(200);
	splitterAnswer->addWidget(texteditSubject);
	splitterAnswer->addWidget(answer);
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

	this->listwidgetExercise->addChoice(QString::fromLocal8Bit("第一题"));
	this->listwidgetExercise->addJudge(QString::fromLocal8Bit("第一题"));
	this->listwidgetExercise->addFillInTheBlanks(QString::fromLocal8Bit("第一题"));
	this->listwidgetExercise->addSAQ(QString::fromLocal8Bit("第一题"));
}

void ExamClient::slotCommit()
{
	QString answers = this->answer->getAnswer().value<QString>();
	qDebug() << answers;
}
