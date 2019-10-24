#define _CRT_SECURE_NO_WARNING 1
#include "Date.h"
//void testDate()
//{
//	Date d1;
//	d1.SetDate(2019, 10, 22);
//	d1.Display();
//
//	Date d2;
//	d2.SetDate(2019, 10, 21);
//	d2.Display();
//}

//	//this是否可以为空
//	//可以为空：不进行解引用
//	//this指针本质上其实是一个成员函数的形参，是对象调用成员函数时，将对象地址作为实参传递给this形参。所以对象中不存储this指针

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << this->_a << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//void testA()
//{
//	A* p = NULL;
//	p->PrintA();
//	p->Show();
//}

//构造函数是一个特殊的成员函数，名字与类名相同, 创建类类型对象时由编译器自动调用，保证每个数据成员
//都有 一个合适的初始值，并且在对象的生命周期内只调用一次
void testContrust()
{
	//构造函数在实例化时编译器只调用，整个生命周期只调用1次
	//无参构造函数后无需加括号，否则是函数声明
	Date d;

	//Date d3(); //函数声明

	Date d2;
	d2.SetDate(2019, 10, 21);

	//拷贝构造
	Date d3(d2);
	Date d4 = d3;
	/*Date d5 = Date(2019, 10, 20);*/

	//赋值
	Date d5;
	d5 = d1;
	d3 = d2 = d1; //连续赋值
	cout << d5 == d1 << endl;

	//const
	const Date d4(2019, 10, 24);
	d4.Display();//由const定义的常量只能调用带有const的成员函数
	             //权限可以缩小，不可以放大

	//取地址
	Date* pd = &d1;
	const Date* pd1 = &d4;
}

void testString()
{
	String s("Hello");
}

int main()
{
	//testDate();
	testContrust();
	testString();
	return 0;
}