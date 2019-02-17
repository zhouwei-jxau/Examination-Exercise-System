#include "stdafx.h"
#include "ErrorBook.h"

ErrorBook::ErrorBook()
{
	this->setWindowTitle(CurrentUser::getUserName()+QString::fromLocal8Bit("�Ĵ��Ȿ"));
	this->setWindowState(Qt::WindowState::WindowMaximized);
	this->setAttribute(Qt::WA_DeleteOnClose, true);
	this->setCentralWidget(new QWidget());
	this->imageHeadpartrait = new QLabel();
	this->imageHeadpartrait->setFixedSize(QSize(90, 90));
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
	this->labelTip = new QLabel();
	this->labelTip->setFont(font);
	this->labelTip->setText(QString::fromLocal8Bit("��ǰ�ղ�0��"));
	this->labelTitle = new QLabel();
	font = this->labelTitle->font();
	font.setFamily(SystemVariable::FONTFAMILY);
	font.setPointSize(30);
	font.setBold(true);
	this->labelTitle->setFont(font);
	this->labelTitle->setText(CurrentUser::getExerciseSet().getName());
	this->labelTitle->setContentsMargins(160, 0, 0, 0);
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
	gridLayoutInfo->addWidget(this->imageHeadpartrait, 0, 0, 3, 1, Qt::AlignLeft | Qt::AlignTop);
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
	this->buttonGenerate = new QPushButton();
	this->buttonGenerate->setFixedHeight(40);
	this->buttonGenerate->setText(QString::fromLocal8Bit("��������"));
	connect(this->buttonGenerate, SIGNAL(clicked()), this, SLOT(slotGenerate()));
	subjectWidget->layout()->addWidget(this->listwidgetExercise);
	subjectWidget->layout()->addWidget(this->buttonGenerate);

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
	QWidget* widgetMark = new QWidget();
	widgetMark->setLayout(new QVBoxLayout());
	this->texteditMark = new QTextEdit();
	this->texteditMark->setFont(font);
	widgetMark->layout()->addWidget(this->texteditMark);
	this->buttonSaveMark = new QPushButton(QString::fromLocal8Bit("����"));
	connect(this->buttonSaveMark, SIGNAL(clicked()), this, SLOT(slotSaveMark()));
	widgetMark->layout()->addWidget(this->buttonSaveMark);
	QTabWidget* tableWidget = new QTabWidget();
	tableWidget->setContentsMargins(0, 0, 0, 0);
	//
	QWidget* generateSetting = new QWidget();
	generateSetting->setLayout(new QVBoxLayout());
	generateSetting->layout()->setSpacing(20);
	generateSetting->layout()->setAlignment(Qt::AlignTop);
	generateSetting->layout()->setContentsMargins(0, 40, 0, 0);
	this->subject = new LineEditWithTag();
	this->subject->setTag(QString::fromLocal8Bit("����"));
	this->subject->setHintText(QString::fromLocal8Bit("������ϰ�⼯����"));
	generateSetting->layout()->addWidget(this->subject);
	QWidget* widget = new QWidget();
	widget->setLayout(new QHBoxLayout());
	widget->layout()->setContentsMargins(0, 0, 0, 0);
	this->numOfChoice = new LineEditWithTag();
	this->numOfChoice->setTag(QString::fromLocal8Bit("ѡ��������"));
	this->numOfChoice->setHintText(QString::fromLocal8Bit("������ѡ��������"));
	this->markOfChoice = new LineEditWithTag();
	this->markOfChoice->setTag(QString::fromLocal8Bit("ѡ�������"));
	this->markOfChoice->setHintText(QString::fromLocal8Bit("������ѡ�������"));
	widget->layout()->addWidget(this->numOfChoice);
	widget->layout()->addWidget(this->markOfChoice);
	generateSetting->layout()->addWidget(widget);
	widget = new QWidget();
	widget->setLayout(new QHBoxLayout());
	widget->layout()->setContentsMargins(0, 0, 0, 0);
	this->numOfJudge = new LineEditWithTag();
	this->numOfJudge->setTag(QString::fromLocal8Bit("�ж�������"));
	this->numOfJudge->setHintText(QString::fromLocal8Bit("�������ж�������"));
	this->markOfJudge = new LineEditWithTag();
	this->markOfJudge->setTag(QString::fromLocal8Bit("�ж������"));
	this->markOfJudge->setHintText(QString::fromLocal8Bit("�������ж������"));
	widget->layout()->addWidget(this->numOfJudge);
	widget->layout()->addWidget(this->markOfJudge);
	generateSetting->layout()->addWidget(widget);
	widget = new QWidget();
	widget->setLayout(new QHBoxLayout());
	widget->layout()->setContentsMargins(0, 0, 0, 0);
	this->numOfFillInTheBlanks = new LineEditWithTag();
	this->numOfFillInTheBlanks->setTag(QString::fromLocal8Bit("���������"));
	this->numOfFillInTheBlanks->setHintText(QString::fromLocal8Bit("���������������"));
	this->markOfFillInTheBlanks = new LineEditWithTag();
	this->markOfFillInTheBlanks->setTag(QString::fromLocal8Bit("��������"));
	this->markOfFillInTheBlanks->setHintText(QString::fromLocal8Bit("��������������"));
	widget->layout()->addWidget(this->numOfFillInTheBlanks);
	widget->layout()->addWidget(this->markOfFillInTheBlanks);
	generateSetting->layout()->addWidget(widget);
	widget = new QWidget();
	widget->setLayout(new QHBoxLayout());
	widget->layout()->setContentsMargins(0, 0, 0, 0);
	this->numOfSAQ = new LineEditWithTag();
	this->numOfSAQ->setTag(QString::fromLocal8Bit("���������"));
	this->numOfSAQ->setHintText(QString::fromLocal8Bit("��������������"));
	this->markOfSAQ = new LineEditWithTag();
	this->markOfSAQ->setTag(QString::fromLocal8Bit("��������"));
	this->markOfSAQ->setHintText(QString::fromLocal8Bit("�������������"));
	widget->layout()->addWidget(this->numOfSAQ);
	widget->layout()->addWidget(this->markOfSAQ);
	generateSetting->layout()->addWidget(widget);
	//
	tableWidget->insertTab(0, this->texteditSubject, QString::fromLocal8Bit("��Ŀ"));
	tableWidget->insertTab(1, widgetMark, QString::fromLocal8Bit("�ʼ�"));
	tableWidget->insertTab(2, generateSetting, QString::fromLocal8Bit("��������"));

	this->widgetAnswer = new QWidget();
	this->widgetAnswer->setLayout(new QVBoxLayout());
	this->widgetAnswer->layout()->setContentsMargins(0, 0, 0, 0);
	this->widgetAnswer->setMinimumHeight(210);
	this->answer = NULL;
	splitterAnswer->addWidget(tableWidget);
	splitterAnswer->addWidget(this->widgetAnswer);
	splitterAnswer->setStretchFactor(0, 5);
	splitterAnswer->setStretchFactor(1, 1);

	splitter->addWidget(widgetInfo);
	splitter->addWidget(splitterMain);
	QSplitterHandle* handle = splitter->handle(1);
	if (handle)
	{
		QPalette palette = handle->palette();
		palette.setColor(QPalette::Background, Qt::gray);
		handle->setPalette(palette);
		handle->setFixedHeight(1);
		handle->setDisabled(true);
	}
	layout->addWidget(splitter);
	this->centralWidget()->setLayout(layout);
	connect(this->listwidgetExercise, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slotExerciseSelected(QListWidgetItem*)));
	//��ȡ��ǰ���⼯
	QNetworkAccessManager* httpManager = new QNetworkAccessManager(this);
	QObject::connect(httpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotGetErrorExercise(QNetworkReply*)));
	QString url = QString("http://") + SystemVariable::SERVER + ":" + QString::number(SystemVariable::SERVERPORT) + "/" + SystemVariable::GETERROREXERCISESERVLET;
	QNetworkRequest request;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded;charset=utf-8");
	QString param = QString::fromLocal8Bit("account=") + CurrentUser::getAccount();
	httpManager->post(request, param.toLocal8Bit());
}


ErrorBook::~ErrorBook()
{
	for (int i = 0; i < this->errorExerciseList.size(); i++)
	{
		delete this->errorExerciseList.at(i);
	}
}

void ErrorBook::setAnswer(Exercise * exercise)
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
}

void ErrorBook::setCollection(int collection)
{
	this->labelTip->setText(QString::fromLocal8Bit("��ǰ�ղ�") + QString::number(collection) + QString::fromLocal8Bit("��"));
}

QVariant ErrorBook::getCurrentExerciseAnswer()
{
	return QVariant();
}

void ErrorBook::slotExerciseSelected(QListWidgetItem * item)
{
	if (this->listwidgetExercise->isUnSubjectItem(item))
		return;
	this->texteditSubject->setText(item->text().trimmed());
	this->texteditMark->setText(this->errorExerciseList.at(static_cast<ExerciseListItem*>(item)->getIndexInExerciseSet())->getMark());
	this->setAnswer(this->errorExerciseList.at(static_cast<ExerciseListItem*>(item)->getIndexInExerciseSet())->getExercise());
	this->answer->setAnswer(this->errorExerciseList.at(static_cast<ExerciseListItem*>(item)->getIndexInExerciseSet())->getExercise()->getAnswer());
	this->answer->setEditable(false);
}

void ErrorBook::slotExerciseDoubleClicked(QListWidgetItem * item)
{
}

void ErrorBook::slotAnswerChanged()
{
}

void ErrorBook::slotGetErrorExercise(QNetworkReply * reply)
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
		messageBox.about(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�޷����ӵ���������������������!"));
		return;
	}
	QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
	QJsonArray jsonData = jsonDoc.object().value("data").toArray();
	int responseCode = jsonDoc.object().value("responseCode").toInt();
	if (responseCode)
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�޷����ӵ���������������������!"));
		return;
	}
	else
	{
		for (int i = 0; i < data.size(); i++)
		{
			QJsonObject object = jsonData.at(i).toObject().value("exercise").toObject();
			QString type = object.value("type").toString();
			if (type == "Choice")
			{
				ErrorExercise* errorExercise = new ErrorExercise();
				ChoiceExercise* exercise = new ChoiceExercise();
				exercise->setSubject(object.value("subject").toString());
				exercise->setExerciseNo(object.value("no").toInt());
				exercise->setAnswer(object.value("answer").toString());
				QList<QString> options = object.value("options").toString().split("\n");
				for (int i = 0; i < options.size(); i++) {
					if(options[i]!=NULL||(options[i]!=""))
						exercise->addOption(options[i]);
				}
				exercise->setType(Exercise::ExerciseType::Choice);
				this->errorChoiceExerciseList.append(exercise);
				errorExercise->setExercise(exercise);
				errorExercise->setMark(jsonData.at(i).toObject().value("mark").toString());
				this->errorExerciseList.append(errorExercise);
			}
			if (type == "Judge")
			{
				ErrorExercise* errorExercise = new ErrorExercise();
				JudgeExercise* exercise = new JudgeExercise();
				exercise->setSubject(object.value("subject").toString());
				exercise->setExerciseNo(object.value("no").toInt());
				exercise->setAnswer(object.value("answer").toString());
				exercise->setType(Exercise::ExerciseType::Judge);
				this->errorJudgeExerciseList.append(exercise);
				errorExercise->setExercise(exercise);
				errorExercise->setMark(jsonData.at(i).toObject().value("mark").toString());
				this->errorExerciseList.append(errorExercise);
			}

			if (type == "FillInTheBlanks")
			{
				ErrorExercise* errorExercise = new ErrorExercise();
				FillInTheBlanksExercise* exercise = new FillInTheBlanksExercise();
				exercise->setSubject(object.value("subject").toString());
				exercise->setExerciseNo(object.value("no").toInt());
				exercise->setAnswer(object.value("answer").toString());
				exercise->setNumberOfBlanks(object.value("numOfBlanks").toInt());
				exercise->setType(Exercise::ExerciseType::FillInTheBlanks);
				this->errorFillInTheBlanksExerciseList.append(exercise);
				errorExercise->setExercise(exercise);
				errorExercise->setMark(jsonData.at(i).toObject().value("mark").toString());
				this->errorExerciseList.append(errorExercise);
			}

			if (type == "SAQ")
			{
				ErrorExercise* errorExercise = new ErrorExercise();
				SAQExercise* exercise = new SAQExercise();
				exercise->setSubject(object.value("subject").toString());
				exercise->setExerciseNo(object.value("no").toInt());
				exercise->setAnswer(object.value("answer").toString());
				exercise->setType(Exercise::ExerciseType::FillInTheBlanks);
				this->errorSAQExerciseList.append(exercise);
				errorExercise->setExercise(exercise);
				errorExercise->setMark(jsonData.at(i).toObject().value("mark").toString());
				this->errorExerciseList.append(errorExercise);
			}
		}
	}

	//�������
	for(int i=0;i<this->errorExerciseList.size();i++)
	{
		this->listwidgetExercise->addExercise(this->errorExerciseList.at(i)->getExercise(),i);
	}
	this->listwidgetExercise->setIconVisiable(false);
	//��������
	this->setCollection(this->errorExerciseList.size());
}

void ErrorBook::slotGetSaveStatus(QNetworkReply * reply)
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
		messageBox.about(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�޷����ӵ���������������������!"));
		return;
	}
	QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
	int responseCode = jsonDoc.object().value("responseCode").toInt();
	if (responseCode)
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ʧ�ܣ�������������!"));
		return;
	}
	else
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ɹ�"));
		return;
	}
	
}

void ErrorBook::slotGenerate()
{
	QString subject=this->subject->getText();
	int numOfChoice=this->numOfChoice->getText().toInt();
	double markOfChoice=this->markOfChoice->getText().toDouble();
	int numOfJudge=this->numOfJudge->getText().toInt();
	double markOfJudge=this->markOfJudge->getText().toDouble();
	int numOfFillInTheBlanks=this->numOfFillInTheBlanks->getText().toInt();
	double markOfFillInTheBlanks=this->markOfFillInTheBlanks->getText().toDouble();
	int numOfSAQ=this->numOfSAQ->getText().toInt();
	double markOfSAQ=this->markOfSAQ->getText().toDouble();

	CurrentUser::getExerciseSet().clear();
	CurrentUser::getExerciseSet().setName(subject);
	CurrentUser::getExerciseSet().setMarkOfChoice(markOfChoice);
	CurrentUser::getExerciseSet().setMarkOfJudge(markOfJudge);
	CurrentUser::getExerciseSet().setMarkOfFillInTheBlanks(markOfFillInTheBlanks);
	CurrentUser::getExerciseSet().setMarkOfSAQ(markOfSAQ);
	CurrentUser::getExerciseSet().setNumberOfChoice(numOfChoice);
	CurrentUser::getExerciseSet().setNumberOfJudge(numOfJudge);
	CurrentUser::getExerciseSet().setNumberOfFillInTheBlanks(numOfFillInTheBlanks);
	CurrentUser::getExerciseSet().setNumberOfSAQ(numOfSAQ);

	//����ѡ����
	int count = 0;
	while (count < numOfChoice&&this->errorChoiceExerciseList.size()>0)
	{
		qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime())+count);
		int r = qrand() % errorChoiceExerciseList.size();
		CurrentUser::getExerciseSet().addExercise(errorChoiceExerciseList.takeAt(r));
		count++;
	}
	//�����ж���
	count = 0;
	while (count < numOfJudge&&this->errorJudgeExerciseList.size()>0)
	{
		qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()) + count);
		int r = qrand() % errorJudgeExerciseList.size();
		CurrentUser::getExerciseSet().addExercise(errorJudgeExerciseList.takeAt(r));
		count++;
	}

	//���������
	count = 0;
	while (count < numOfFillInTheBlanks&&this->errorFillInTheBlanksExerciseList.size()>0)
	{
		qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()) + count);
		int r = qrand() % errorFillInTheBlanksExerciseList.size();
		CurrentUser::getExerciseSet().addExercise(errorFillInTheBlanksExerciseList.takeAt(r));
		count++;
	}

	//��������
	count = 0;
	while (count < numOfSAQ&&this->errorSAQExerciseList.size()>0)
	{
		qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()) + count);
		int r = qrand() % errorSAQExerciseList.size();
		CurrentUser::getExerciseSet().addExercise(errorSAQExerciseList.takeAt(r));
		count++;
	}

	//��ת������ҳ
	ExamClient* client = new ExamClient();
	client->show();
	this->close();
}

void ErrorBook::slotSaveMark()
{
	QNetworkAccessManager* httpManager = new QNetworkAccessManager(this);
	QObject::connect(httpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotGetSaveStatus(QNetworkReply*)));
	QString url = QString("http://") + SystemVariable::SERVER + ":" + QString::number(SystemVariable::SERVERPORT) + "/" + SystemVariable::EDITERROREXERCISEMARKSERVLET;
	QNetworkRequest request;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded;charset=utf-8");
	QString param = QString::fromLocal8Bit("account=") + CurrentUser::getAccount()
		+QString::fromLocal8Bit("&exercise_no=")+QString::number(this->errorExerciseList.at(static_cast<ExerciseListItem*>(this->listwidgetExercise->currentItem())->getIndexInExerciseSet())->getExercise()->getExerciseNo())
		+QString::fromLocal8Bit("&exercise_type=")+QString::number(this->errorExerciseList.at(static_cast<ExerciseListItem*>(this->listwidgetExercise->currentItem())->getIndexInExerciseSet())->getExercise()->getType())
		+QString::fromLocal8Bit("&exercise_mark=")+this->texteditMark->toPlainText();
	QTextCodec* utf8 = QTextCodec::codecForName("utf-8");
	httpManager->post(request,utf8->fromUnicode(param));
}
