#include<iostream>
#include<fstream>
#include<string>
#include"student.h"

/*
函数:read_record()
功能:从record.txt读入记录，得到现有的记录条数
参数:学生信息记录条数&m, 成绩条数&n，
返回值:1
*/
int read_record(int &m, int &n)
{
	std::ifstream fin("record.txt");
	fin >> m;
	fin >> n;
	return 1;
}

/*
函数:write_record()
功能:写入记录到record.txt，更新记录条数
参数:学生信息记录条数m, 成绩条数n，
返回值: 0
*/
int write_record(int m, int n)
{
	std::ofstream fout("record.txt");
	fout << m;
	fout << " ";
	fout << n;
	return 1;
}
/*
函数:save_score()
功能:保存文件到score.dat
参数: 学生成绩指针StudentScore*, 学生成绩条数n
*/
void save_score(StudentScore* stu_score, int n)
{
	using namespace std;
	ofstream fout("score.dat", ios::binary);
	if (!fout)
	{
		cout << "创建文件失败\n";
		return;
	}
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		fout << stu_score[i].ID << "  " << stu_score[i].lesson_number << "  "
			<< stu_score[i].lesson_name << "  " << stu_score[i].credit << "  "
			<< stu_score[i].daily_score << "  " << stu_score[i].exp_score << "  "
			<< stu_score[i].exam_score << "  " << stu_score[i].total_score << "  "
			<< stu_score[i].actual_score << "\n";
	}
	fout.close();
}
/*
函数:read_to_stu_score()
功能:从文件score.dat读入分数到数组
参数:学生成绩数组StudentScore*, 学生成绩条数&n
*/
int read_to_stu_score(StudentScore* stu_score, int &n)
{
	using namespace std;
	int i = 0;
	ifstream fin("score.dat", ios::binary);
	if (!fin)
	{
		cout << "读取成绩文件score.dat失败" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		fin >> stu_score[i].ID >> stu_score[i].lesson_number
			>> stu_score[i].lesson_name >> stu_score[i].credit
			>> stu_score[i].daily_score >> stu_score[i].exp_score
			>> stu_score[i].exam_score >> stu_score[i].total_score
			>> stu_score[i].actual_score;
	}
	fin.close();
	return i;
}

/*
函数:read_to_stu()
功能:从文件student.txt读入学生信息到数组
参数:学生数组Student*, 学生信息条数m
*/
int read_to_stu(Student* stu, int &m)
{
	using namespace std;
	int i = 0;
	ifstream fin("student.txt");
	if (!fin)
	{
		cout << "读取学生基本文件student.txt失败" << endl;
		return 0;
	}
	string temp;//临时string，读入第一行的5个字符串
	for (int i = 0; i < 5; i++)
	{
		fin >> temp;
	}
	for (int i = 0; i < m; i++)
	{
		fin >> stu[i].ID >> stu[i].name >> stu[i].sex >> stu[i].dor_number
			>> stu[i].phone;
	}
	fin.close();
	return 1;
}
/*
函数:save_stu
功能:写入学生信息到student.txt
参数:学生数组Student*,学生信息条数m
*/
void save_stu(Student* stu, int m)
{
	using namespace std;
	ofstream fout("student.txt");
	if (!fout)
	{
		cout << "创建文件失败\n";
		return;
	}
	fout << "学号 姓名  性别  宿舍号码  电话号码\n";
	for (int i = 0; i < m; i++)
	{
		fout << stu[i].ID << "  " << stu[i].name << "  " << stu[i].sex << "  "
			<< stu[i].dor_number << "     " << stu[i].phone << "\n";
	}

	fout.close();
}