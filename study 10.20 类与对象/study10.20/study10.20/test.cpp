#include <iostream>
#include <cstdio>
using namespace std;
/*类*/
/*类的定义*/
class Student
{
public://成员在类外可见
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

private://成员在类外不可见
	char _name[20];
	char _gender[3];
protected://成员在类外不可见
	int _age;
};

/*类的封装*/
//在类体外定义成员，需要使用 :: 作用域解析符指明成员属于哪个类域
//void PrintStudentInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}

void Student::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}

/*1.定义方式*/
//struct + 类名//成员默认公有
//{
//	// 类体：由成员函数和成员变量组成
//};

//class + 类名//成员默认私有
//{
//	// 类体：由成员函数和成员变量组成
//};

/*2.public, private, protected*/
//private，protected：在类内具有全局属性，成员在类外不可见

/*内存对齐*/
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
	//struct,class 唯一区别在于成员的默认访问权限不同
	//类的实例化：定义了一个类类型的变量
	//类类型的变量：类的对象
	Student st; 
	//st._age = 18;
	st.SetStudentInfo("Peter", "男", 18);
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
	//一个类的大小，实际就是该类中”成员变量”之和，当然也要进行内存对齐，注意空类的大小，
	//空类比较特殊，编译器给了空类一个字节来唯一标识这个类

	//求偏移量
	cout << ((char*)&d.a - (char*)&d) << endl;

	//大端（存储）模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
	//小端（存储）模式，是指数据的低位保存在内存的低地址中，而数据的高位, ，保存在内存的高地址中。
	U u;
	if (u.c == 0)
	{
		printf("大端\n");
	}
	else
	{
		printf("小端\n");
	}

	return 0;
}