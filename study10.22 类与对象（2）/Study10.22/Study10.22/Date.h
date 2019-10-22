#include <iostream>
#include <cstdio>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
};
//class Date
//{
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Display()
//	{
//		cout << this->_year << ":" << this->_month << ":" << this->_day << endl;
//	}
//private:
//	int _year, _month, _day;
//};

class Date
{
public:
	//没有显示定义构造时，编译器默认生成，反之不生成
	//默认构造：（默认构造只能有一个）
	//          1、无参构造
	//          2、编译器默认生成
	//          3、全缺省的构造函数
	Date()
	{
		cout << _year << ":" << _month << ":" << _day << endl;
	}
	Date(int year, int month, int day)
	{
		_year = year; 
		_month = month;
		_day = day;
	}

	//默认构造
	//Date(int year = 2000, int month = 1, int day = 1)(全缺省的)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	//拷贝构造:构造函数的一种重载
	Date(const Date& date)//传入引用类型的参数，
	{  //const&：可以接收任何类型的Date对象，临时对象也可以被接收
	   //     &：只能接收非临时Date对象
       //     如果传值，则会无限递归，语法错误
       //     编译器默认生成的拷贝构造完成字节拷贝
		_year = date._year;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << this->_year << ":" << this->_month << ":" << this->_day << endl;
	}
	//析构函数：与构造函数功能相反，析构函数不是完成对象的销毁，局部对象销毁工作是由编译器完成的。而
	//	对象在销毁时会自动调用析构函数，完成类的一些资源清理工作。
	//析构完成对象资源清理,整个生命周期只调用一次
	~Date()
	{
		cout << "~Date()" << endl;
	}

	//运算符重载函数
	//函数名：operator + 要重载的运算符
	//其他的和普通函数定义相同
	//  C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有其返回值类
	//	型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似。
	//	函数名字为：关键字operator后面接需要重载的运算符符号。
	//	函数原型：返回值类型 operator操作符(参数列表)
	//	注意：
	//	1.不能通过连接其他符号来创建新的操作符：比如operator@
	//	2.重载操作符必须有一个类类型或者枚举类型的操作数
	//	3.用于内置类型的操作符，其含义不能改变，例如：内置的整型 + ，不 能改变其含义
	//  4.作为类成员的重载函数时，其形参看起来比操作数数目少1成员函数的操作符有一个默认的形参this，限定为第一个形参
	//  5. .*、::、sizeof 、 ? : 、.注意以上5个运算符不能重载

	//赋值运算符主要有四点：
	//	1. 参数类型
	//	2. 返回值
	//	3. 检测是否自己给自己赋值
	//	4. 返回*this
	//	5. 一个类如果没有显式定义赋值运算符重载，编译器也会生成一个，完成对象按字节序的值拷贝。
	bool operator==(const Date& d2)
	{
		return this->_year == d2._year && this->_month == d2._month && this->_day == d2._day;
	}
private:
	//编译器默认生成的构造函数
	//    内置类型：无操作
	//    自定义类型：会调用自定义类型的构造函数，完成自定义成员的初始化

	//所有的构造函数都会自动调用自定义类型的默认构造函数，销毁对象之前，本身不销毁对象
	//析构函数会自动调用自定义类型的析构函数
	int _year, _month, _day;
	A _a;
	String s;
};

class String
{
public:
	String(char* str = "~String")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	//如果有资源，显式定义析构，完成资源清理，否则会有内存泄漏，
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};