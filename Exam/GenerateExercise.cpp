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
	label->setText(QString::fromLocal8Bit("������������..."));
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
		//���շ���������
		QJsonObject json = QJsonDocument::fromJson(data).object();
		if (json.value("responseCode").toInt() == 0)
		{
			QJsonArray array = json.value("data").toArray();
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
			//���ݽ�����Ϻ���ת��������
			ExamClient* client = new ExamClient();
			client->show();
			this->close();
		}
		else
		{
			QMessageBox messageBox;
			messageBox.about(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��������æ���Ժ�����!"));
			QApplication::quit();
		}
	}
	else
	{
		QMessageBox messageBox;
		messageBox.about(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�޷����ӵ�������!�����������ӡ�"));
		QApplication::quit();
	}
	reply->deleteLater();
}

void GenerateExercise::readyRead()
{
}
