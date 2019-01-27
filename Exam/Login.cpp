#include "stdafx.h"
#include "Login.h"


Login::Login()
{
	this->imageHeadpartrait = new QLabel();
	this->imageHeadpartrait->setPixmap(QPixmap("Resources\\default\\icon\\headpartrait.jpg"));
	this->imageHeadpartrait->setFixedSize(QSize(90, 90));
	this->checkBoxRemeberPassword = new QCheckBox();
	this->checkBoxRemeberPassword->setFixedWidth(90);
	this->checkBoxRemeberPassword->setText(QString::fromLocal8Bit("��ס����"));
	this->checkBoxAutoLogin = new QCheckBox();
	this->checkBoxAutoLogin->setText(QString::fromLocal8Bit("�Զ���¼"));
	this->linkButtonRegist = new LinkButton();
	this->linkButtonRegist->setText(QString::fromLocal8Bit("ע���˺�"));
	this->linkButtonRegist->setFixedHeight(30);
	this->editId = new QLineEdit();
	this->editId->setPlaceholderText(QString::fromLocal8Bit("������ѧ��"));
	this->editId->setFixedSize(QSize(200, 30));
	this->editPassword = new QLineEdit();
	this->editPassword->setPlaceholderText(QString::fromLocal8Bit("����������"));
	this->editPassword->setEchoMode(QLineEdit::EchoMode::Password);
	this->editPassword->setFixedSize(QSize(200, 30));
	this->buttonLogin = new QPushButton();
	this->buttonLogin->setFixedSize(QSize(200, 40));
	this->buttonLogin->setText(QString::fromLocal8Bit("��¼"));
	this->setFixedSize(QSize(420, 260));
	this->labelTip = new QLabel();
	QPalette palette = this->labelTip->palette();
	palette.setColor(QPalette::Foreground, QColor(255, 0, 0));
	this->labelTip->setPalette(palette);
	this->setWindowTitle(QString::fromLocal8Bit("������ϰ�ͻ���"));
	this->setCentralWidget(new QWidget());

	QGridLayout* layout = new QGridLayout();
	layout->setSpacing(8);
	layout->setContentsMargins(20, 40,10, 10);
	layout->addWidget(this->imageHeadpartrait, 0, 0, 3, 1, Qt::AlignTop);
	layout->addWidget(this->editId, 0, 1,1,3, Qt::Alignment::enum_type::AlignTop);
	layout->addWidget(this->linkButtonRegist, 0, 2,1,1, Qt::AlignLeft | Qt::AlignVCenter);
	layout->addWidget(this->editPassword, 1, 1,1,3, Qt::Alignment::enum_type::AlignBottom);
	QHBoxLayout* layoutCheckBox = new QHBoxLayout();
	layoutCheckBox->addWidget(this->checkBoxRemeberPassword);
	layoutCheckBox->addWidget(this->checkBoxAutoLogin);
	layoutCheckBox->setContentsMargins(0, 0, 0, 0);
	layoutCheckBox->setAlignment(Qt::AlignLeading);
	QWidget* widgetCheckBox = new QWidget();
	widgetCheckBox->setLayout(layoutCheckBox);
	layout->addWidget(widgetCheckBox, 2, 1,1,3, Qt::AlignVCenter | Qt::AlignLeft);
	layout->addWidget(this->buttonLogin, 3, 1, 2, 1, Qt::AlignLeft|Qt::AlignTop);
	layout->addWidget(this->labelTip, 4, 1, 1, 1, Qt::AlignLeft|Qt::AlignTop);
	this->centralWidget()->setLayout(layout);

	connect(this->linkButtonRegist, SIGNAL(clicked()), this, SLOT(slotRegist()));
	connect(this->buttonLogin, SIGNAL(clicked()), this, SLOT(slotLogin()));

	//��ȡ�û���������
	QDir dir(QString::fromLocal8Bit(SystemVariable::CONFIGPATH));
	if (dir.exists())
	{
		QString isAutoLogin = "0";
		QString path = dir.currentPath() + dir.path() + "/" + SystemVariable::USERFILENAME;
		QFile file(path);
		if (file.exists())
		{
			file.open(QFile::ReadWrite);
			if (file.size() > 0)
			{
				QString data = file.readAll();
				QString id = data.split("\n")[0];
				QString password = data.split("\n")[1];
				isAutoLogin = data.split("\n")[2];
				this->editId->setText(id);
				this->editPassword->setText(password);
				this->checkBoxRemeberPassword->setChecked(true);
			}
			file.close();
			if (isAutoLogin == "1")
			{
				this->checkBoxAutoLogin->setChecked(true);
				slotLogin();
			}
		}
	}
}

Login::Login(QWidget *parent, Qt::WindowFlags flags)
{
	QMainWindow(parent, flags);
	Login();
}


Login::~Login()
{
}

void Login::slotLogin()
{
	httpManager = new QNetworkAccessManager(this);
	QObject::connect(httpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
	QString url = QString("http://") + SystemVariable::SERVER + ":" + QString::number(SystemVariable::SERVERPORT) + "/" + SystemVariable::LOGINSERVLET;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/x-www-form-urlencoded");
	QCryptographicHash md5(QCryptographicHash::Md5);
	md5.addData(this->editPassword->text().toLocal8Bit());
	reply = httpManager->post(request, ("account=" + this->editId->text() + "&password=" + md5.result().toHex()).toLocal8Bit());
}

void Login::requestFinished(QNetworkReply*reply)
{
	QByteArray data = reply->readAll();
	QJsonObject json = QJsonDocument::fromJson(data).object();
	int responseCode = json.value("responseCode").toInt();
	if (responseCode == 0)
	{
		if (this->checkBoxRemeberPassword->isChecked())
		{
			//�����ѡ�˼�ס���룬��ô���浱ǰ�û�
			QDir dir(QString::fromLocal8Bit(SystemVariable::CONFIGPATH));
			if (!dir.exists())
			{
				dir.mkdir(dir.path());
			}
			QString path = dir.currentPath()+dir.path() +"/"+ SystemVariable::USERFILENAME;
			QFile file(path);
			file.open(QIODevice::OpenMode::enum_type::ReadWrite);
			QString data = this->editId->text() + "\n" + this->editPassword->text();
			if (this->checkBoxAutoLogin->isChecked())
			{
				data = data + "\n1";
			}
			else
			{
				data = data + "\n0";
			}
			file.write((data).toLocal8Bit());
			file.close();
		}
		else
		{
			//���û�й�ѡ��ס���룬��ôɾ����ǰ�û�
			QDir dir(QString::fromLocal8Bit(SystemVariable::CONFIGPATH));
			if (!dir.exists())
			{
				dir.mkdir(dir.path());
			}
			QString path = dir.currentPath() + dir.path() + "/" + SystemVariable::USERFILENAME;
			QFile file(path);
			if (file.exists())
			{
				file.open(QFile::ReadWrite);
				file.resize(0);
				file.close();
			}
		}

		SelectExercise* selectExercise = new SelectExercise();
		selectExercise->show();
		this->close();
	}
	else
	{
		this->labelTip->setText(QString::fromLocal8Bit("��¼ʧ��:")+json.value("msg").toString());
	}
	reply->deleteLater();
}

void Login::slotRegist()
{
	Regist* regist = new Regist(this);
	regist->show();
}
