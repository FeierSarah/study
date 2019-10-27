#include<iostream>
#include<iomanip>
#include<string>
using std::string;


// StudentScore 存储学生成绩
class StudentScore
{
public:
	int ID;  //学号
	string lesson_number; //课程编号
	string lesson_name; //课程名称
	int credit;  //学分
	int daily_score;  //平时成绩
	int exp_score;  //实验成绩
	int exam_score; //卷面成绩
	double total_score;  //综合成绩, 计算得到
	double actual_score; // 实际得分， 计算得到
	StudentScore();
	StudentScore(int ID, string lesson_number, string lesson_name, int credit,
		int daily_score, int exp_score, int exam_score);
	~StudentScore();
	friend std::ostream& operator<<(std::ostream& os, const StudentScore& score);
};

//Student类，存储学生信息
class Student
{
public:
	int ID;  //学号
	string name; //姓名
	string sex; //性别
	int dor_number; //宿舍号码
	int phone; //电话
	Student();
	~Student();
	friend std::ostream & operator<<(std::ostream & os, const Student& stu);
};