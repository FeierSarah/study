#include <iostream>
#include <cstdio>
using namespace std;
/*��*/
/*��Ķ���*/
class Student
{
public://��Ա������ɼ�
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	//void PrintStudentInfo()
	//{
	//	cout << _name << " " << _gender << " " << _age << endl;
	void PrintStudentInfo();

private://��Ա�����ⲻ�ɼ�
	char _name[20];
	char _gender[3];
protected://��Ա�����ⲻ�ɼ�
	int _age;
};

/*��ķ�װ*/
//�������ⶨ���Ա����Ҫʹ�� :: �����������ָ����Ա�����ĸ�����
//void PrintStudentInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}

void Student::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}

/*1.���巽ʽ*/
//struct + ����//��ԱĬ�Ϲ���
//{
//	// ���壺�ɳ�Ա�����ͳ�Ա�������
//};

//class + ����//��ԱĬ��˽��
//{
//	// ���壺�ɳ�Ա�����ͳ�Ա�������
//};

/*2.public, private, protected*/
//private��protected�������ھ���ȫ�����ԣ���Ա�����ⲻ�ɼ�

/*�ڴ����*/
class A
{
	int a;
};

class B
{
	int aa(int a, int b)
	{
		return a + b;
	}
};

class C
{

};

class D
{
public:
	int a;
	char c;
	double d;
};

class E
{
	int a;
	char c;
	double d;
	class F
	{
		int a;
		char c;
		double d;
	};
};

class G
{
	int a;
	char c;
	double d;
	class F
	{
		int a;
		char c;
		double d;
	};
	F f;
};

union U
{
	int a;
	char c;
};

int main()
{
	//struct,class Ψһ�������ڳ�Ա��Ĭ�Ϸ���Ȩ�޲�ͬ
	//���ʵ������������һ�������͵ı���
	//�����͵ı�������Ķ���
	Student st; 
	//st._age = 18;
	st.SetStudentInfo("Peter", "��", 18);
	st.PrintStudentInfo();

	A a;
	B b;
	C c;
	D d;
	E e;
	G g;
	int sz = sizeof(a); //4
	sz = sizeof(b);     //1
	sz = sizeof(c);     //1
	sz = sizeof(d);     //16
	sz = sizeof(e);     //16
	sz = sizeof(g);     //32
	//һ����Ĵ�С��ʵ�ʾ��Ǹ����С���Ա������֮�ͣ���ȻҲҪ�����ڴ���룬ע�����Ĵ�С��
	//����Ƚ����⣬���������˿���һ���ֽ���Ψһ��ʶ�����

	//��ƫ����
	cout << ((char*)&d.a - (char*)&d) << endl;

	//��ˣ��洢��ģʽ����ָ���ݵĵ�λ�������ڴ�ĸߵ�ַ�У������ݵĸ�λ���������ڴ�ĵ͵�ַ�У�
	//С�ˣ��洢��ģʽ����ָ���ݵĵ�λ�������ڴ�ĵ͵�ַ�У������ݵĸ�λ, ���������ڴ�ĸߵ�ַ�С�
	U u;
	if (u.c == 0)
	{
		printf("���\n");
	}
	else
	{
		printf("С��\n");
	}

	return 0;
}