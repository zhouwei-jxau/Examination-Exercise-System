#include "stdafx.h"
#include "GenerateExercise.h"


GenerateExercise::GenerateExercise(QWidget *parent, Qt::WindowFlags flags )
{
	QMainWindow(parent, flags);
	QWidget* centerWidget = new QWidget();
	centerWidget->setLayout(new QVBoxLayout());
	centerWidget->layout()->setAlignment(Qt::AlignCenter);
	QLabel* label = new QLabel();
	QFont font = label->font();
	font.setPixelSize(24);
	label->setFont(font);
	label->setText(QString::fromLocal8Bit("正在生成试题..."));
	centerWidget->layout()->addWidget(label);
	this->setCentralWidget(centerWidget);
	this->setFixedWidth(800);
	this->setFixedHeight(100);
	this->move(QApplication::desktop()->width() / 2 - this->width() / 2, QApplication::desktop()->height() / 2 - this->height() / 2);
	this->setWindowFlags(Qt::WindowFlags::enum_type::FramelessWindowHint);
	httpManager = new QNetworkAccessManager(this);
	QObject::connect(httpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
	QString url = QString("http://") + SystemVariable::SERVER + ":" + QString::number(SystemVariable::SERVERPORT) + "/" + SystemVariable::GETEXERCISESERVLET;
	request = new QNetworkRequest();
	request->setUrl(url);
	request->setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded;charset=utf-8");
	QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
	QString exerciseName = QString::fromLocal8Bit("exercise_name=")+CurrentUser::getExerciseSet().getName();
	reply = httpManager->post(*request,utf8->fromUnicode(exerciseName));
}


GenerateExercise::~GenerateExercise()
{
	delete this->request;
}

void GenerateExercise::requestFinished(QNetworkReply * replay)
{
	QByteArray data;
	QByteArray buffer;
	while ((buffer = reply->readLine()).length() > 0)
	{
		data.append(buffer);
	}
	if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200)
	{
		//接收服务器数据
		QJsonObject json = QJsonDocument::fromJson(data).object();
		if (json.value("responseCode").toInt() == 0)
		{
			QJsonObject exerciseSet = json.value("data").toObject();
			CurrentUser::getExerciseSet().setMarkOfChoice(exerciseSet.value("markofChoice").toInt());
			CurrentUser::getExerciseSet().setMarkOfJudge(exerciseSet.value("markOfJudge").toInt());
			CurrentUser::getExerciseSet().setMarkOfFillInTheBlanks(exerciseSet.value("markOfFillInTheBlanks").toInt());
			CurrentUser::getExerciseSet().setMarkOfSAQ(exerciseSet.value("markOfSAQ").toInt());
			CurrentUser::getExerciseSet().setNumberOfChoice(exerciseSet.value("numOfChoice").toInt());
			CurrentUser::getExerciseSet().setNumberOfJudge(exerciseSet.value("numOfJudge").toInt());
			CurrentUser::getExerciseSet().setNumberOfFillInTheBlanks(exerciseSet.value("numOfFillInTheBlanks").toInt());
			CurrentUser::getExerciseSet().setNumberOfSAQ(exerciseSet.value("numOfSAQ").toInt());
			CurrentUser::getExerciseSet().setName(exerciseSet.value("name").toString());
			QJsonArray array = exerciseSet.value("exercises").toArray();
			for (int i = 0; i < array.size(); i++)
			{
				QString type = array.at(i).toObject().value("type").toString();
				if (type == "Choice")
				{
					ChoiceExercise* choice = new ChoiceExercise();
					choice->setAnswer(array.at(i).toObject().value("answer").toString());
					choice->setType(Exercise::ExerciseType::Choice);
					choice->setSubject(array.at(i).toObject().value("subject").toString());
					QList<QString> options = array.at(i).toObject().value("options").toString().split("\n");
					for (int j = 0; j < options.size(); j++)
					{
						if (options[j].length() > 0)
						{
							choice->addOption(options[j]);
						}
					}
					CurrentUser::getExerciseSet().addExercise(choice);
				}
				if (type == "Judge")
				{
					JudgeExercise* judge = new JudgeExercise();
					judge->setAnswer(array.at(i).toObject().value("answer").toString());
					judge->setType(Exercise::ExerciseType::Judge);
					judge->setSubject(array.at(i).toObject().value("subject").toString());
					CurrentUser::getExerciseSet().addExercise(judge);
				}

				if (type == "FillInTheBlanks")
				{
					FillInTheBlanksExercise* fillInTheBlanks = new FillInTheBlanksExercise();
					fillInTheBlanks->setAnswer(array.at(i).toObject().value("answer").toString());
					fillInTheBlanks->setNumberOfBlanks(array.at(i).toObject().value("numOfBlanks").toInt());
					fillInTheBlanks->setSubject(array.at(i).toObject().value("subject").toString());
					fillInTheBlanks->setType(Exercise::ExerciseType::FillInTheBlanks);
					CurrentUser::getExerciseSet().addExercise(fillInTheBlanks);
				}

				if (type == "SAQ")
				{
					SAQExercise* saq = new SAQExercise();
					saq->setAnswer(array.at(i).toObject().value("answer").toString());
					saq->setSubject(array.at(i).toObject().value("subject").toString());
					saq->setType(Exercise::ExerciseType::SAQ);
					CurrentUser::getExerciseSet().addExercise(saq);
				}
			}
			//数据接收完毕后，跳转到主界面
			ExamClient* client = new ExamClient();
			client->show();
			this->close();
		}
		else
		{
			QMessageBox messageBox;
			messageBox.about(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("服务器繁忙请稍后重试!"));
			QApplication::quit();
		}
	}
	else
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("无法连接到服务器!请检查网络连接。"));
		QApplication::quit();
	}
	reply->deleteLater();
}

void GenerateExercise::readyRead()
{
}
