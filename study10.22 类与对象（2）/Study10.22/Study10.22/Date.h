#include <iostream>
#include <cstdio>
using namespace std;

class A
{
public:
	A(int a)
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
	Date(int year = 2000, int month = 1, int day = 1//,int hour = 1, int minute = 1, int a = 1)(全缺省的)
	{
		//初始化列表，每个成员只可以出现一次
		//初始化列表是成员对象真正定义的地方
		//引用和const以及自定义类型需要在定义的时候初始化，所以引用和const以及自定义类型必须在初始化列表进行初始化
		: _year(year)
		, _month(month)
		, _day(day)
		//, _hour(hour)
		//, _minute(minute)
		//, _ab(date.minute)

		// //赋值操作
		// //可多次出现,也可不出现，在没有特例时可以代替初始化列表使用
		// //特例即需要在对象定义时实现初始化的引用和const以及自定义类型
		//_year = year;
		//_month = month;
		//_day = day;

		//_year = year;
		//_month = month;
		//_day = day;
	}

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

	//const
	//可读可写  可以不存在，用下面的函数替代
	//void Display(Date* const this) 
	void Display()
	{
		cout << this->_year << ":" << this->_month << ":" << this->_day << endl;
	}
	//不可写
	//void Display(const Date* const this) 
	void Display() const
	{
		cout << this->_year << ":" << this->_month << ":" << this->_day << endl;
	}
	//1.const对象可以调用非const成员函数吗？ n
	//2. 非const对象可以调用const成员函数吗？ y
	//3. const成员函数内可以调用其它的非const成员函数吗？ n
	//4. 非const成员函数内可以调用其它的const成员函数吗？  y

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

	//赋值运算符重载函数：用一个对象改变另一个已经存在的对象的内容
	//赋值运算符重载：编译器默认生成的为浅拷贝
	//若存在资源，要自行写赋值函数，避免析构函数二次释放，资源泄漏，因为析构函数只能被调用一次，拷贝构造也是如此
	void operator=(const Date& d2)
	{
		if (this != &d)
		this->_year = d2._year;
		this->_month = d2._month;
		this->_day = d2._day;
	}
	//可实现连续赋值
	Date& operator=(const Date& d2)
	{
		if (this != &d)
			this->_year = d2._year;
		this->_month = d2._month;
		this->_day = d2._day;
		return *this;
	}

	Date* operator&()
	{
		return this;
	}

	const Date* operator&() const
	{
		return this;
	}
private:
	//编译器默认生成的构造函数
	//    内置类型：无操作
	//    自定义类型：会调用自定义类型的构造函数，完成自定义成员的初始化

	//所有的构造函数都会自动调用自定义类型的默认构造函数，销毁对象之前，本身不销毁对象
	//析构函数会自动调用自定义类型的析构函数
	int _year, _month, _day;
	//int& _hour;
	//const int _minute;
	//A _ab;
	//String s;
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

//class C
//{
//public:
//	C(int c)//初始化列表初始化的顺序按照声明的顺序，即先_a,再_c
//		: _c(c)
//		, _a(a)
//	{
//	}
//private:
//	int _a;
//	int _c;
//};

int count = 0
class D
{
	//支持单参构造函数的隐式类型转换
	D(int d)
	: _d(d)
	{
	}

	D(const D &d)
		: _d(d)
	{
		++count;
	}

	D& operator = (const D& d)
	{
		_d = d._d;
		return *this;
	}
private:
	int _d;
	//static成员：所有对象共享，属于类成员
	//static成员的访问形式：对象访问或类目+作用域
	//static成员函数不能使用this指针
	static int dcount;
	//  1.静态成员为所有类对象所共享，不属于某个具体的实例
	//	2. 静态成员变量必须在类外定义，定义时不添加static关键字
	//	3. 类静态成员即可用类名::静态成员或者对象.静态成员来访问
	//	4. 静态成员函数没有隐藏的this指针，不能访问任何非静态成员
	//	5. 静态成员和类的普通成员一样，也有public、protected、private3种访问级别，也可以具有返回值，
	//	const修饰符等参数

	 //   1.静态成员函数可以调用非静态成员函数吗？  N
	 //   2. 非静态成员函数可以调用类的静态成员函数吗？  Y
};
//static成员必须在类外初始化
int D::dcount = 0;

D fun(D d)
{
	return d;
}

void TestD()
{
	D obj = 10;//单参构造函数的隐式类型转换
	obj = 20;
	D d2 = 30;
	D d3 = 30;//dcount被几个类共享
	fun(obj);
	cout << count << endl; //4
	cout << sizeof(obj) << endl;
}