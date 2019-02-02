#pragma once
class Exercise
{
public:
	enum ExerciseType
	{
		Choice,
		Judge,
		FillInTheBlanks,
		SAQ
	};
	Exercise();
	void setSubject(QString subject);
	QString getSubject();
	void setAnswer(QString answer);
	QString getAnswer();
	void setType(ExerciseType type);
	ExerciseType getType();
	~Exercise();
private:
	QString subject;
	QString answer;
	ExerciseType type;
};

