#include<iostream>
#include<iomanip>
#include<string>
using std::string;


// StudentScore �洢ѧ���ɼ�
class StudentScore
{
public:
	int ID;  //ѧ��
	string lesson_number; //�γ̱��
	string lesson_name; //�γ�����
	int credit;  //ѧ��
	int daily_score;  //ƽʱ�ɼ�
	int exp_score;  //ʵ��ɼ�
	int exam_score; //����ɼ�
	double total_score;  //�ۺϳɼ�, ����õ�
	double actual_score; // ʵ�ʵ÷֣� ����õ�
	StudentScore();
	StudentScore(int ID, string lesson_number, string lesson_name, int credit,
		int daily_score, int exp_score, int exam_score);
	~StudentScore();
	friend std::ostream& operator<<(std::ostream& os, const StudentScore& score);
};

//Student�࣬�洢ѧ����Ϣ
class Student
{
public:
	int ID;  //ѧ��
	string name; //����
	string sex; //�Ա�
	int dor_number; //�������
	int phone; //�绰
	Student();
	~Student();
	friend std::ostream & operator<<(std::ostream & os, const Student& stu);
};