#include <stdio.h>

/*命名空间*/
/*
1.分段定义、嵌套定义
2.命名空间成员使用方式
  命名空间+::+成员(推荐)
  引入成员 using+命名空间+::+成员，后面使用成员时，不需要加作用域,成员暴露在全局中，如果全局中有，则会命名冲突
  展开命名空间 using+命名空间
  */
namespace bit
{
	void print(int a)
	{
		printf("%d \n", a);
	}
	int a;
	int b;
	void func2()
	{

	}
	namespace bit_1
	{
	}
}
namespace bit
{
	//int a;重定义
}

int a;
int b;
using bit::func2;
//using namespace bit;

void test()
{
	bit::a = 1;
	bit::print(bit::a);//调用bit命名空间下的成员a
	bit::print(a);//调用全局a
	func2();
	::a; //(全局作用域)
}

/*缺省参数*/
//参数接受顺序：从左到右
void func1(int a = 1, int b = 1, int c = 1)
{

}
void func2(int a, int b = 1, int c = 1);
//void func2(int a=1, int b , int c = 1);
void func3(int a, int b, int c = 1)
{

}

/*引用*/
void test()
{
	//类型+&+引用名称
	int a = 10;
	int& ra = a;//a的别名
	int& ra2 = a;
	ra = 100;
	//引用定义时必须初始化
	//int& ra3;

	const int b = 10;
	const int& rb = b;
}

int main()
{
	func1();
	return 0;
}

