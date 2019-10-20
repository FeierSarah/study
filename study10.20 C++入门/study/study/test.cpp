#include <iostream>
#include <cstdio>
using namespace std;

/*1.命名空间*/
/****
*命名空间成员访问方式：1.命名空间名称 + :: + 变量名
*                      2.using + 命名空间名称 + :: + 变量名
*                      3.using namespace + 命名空间名称 ->所有成员全部裸露在全局中(不推荐)
**/

namespace N1
{
	int a;
	int add(int a, int b)
	{
		return a + b;
	}
}

//命名空间的嵌套
namespace N2
{
	int b;
	int sub(int a, int b)
	{
		return a - b;
	}
	namespace N3
	{
		int b;
		int add(int a, int b)
		{
			return a - b;
		}
	}
}

//命名空间的分段定义
namespace N1
{
	int b;
	int sub(int a, int b)
	{
		return a - b;
	}
}

//using N1::a;
//using N1::sub;
//using namespace N1;
void test1()
{
	N1::a = 10;
	N1::sub(10, 5);
	//a = 20;
	//sub(100, 200);
	N2::N3::b = 20;
}

/*2.输入输出*/
void test2()
{
	int a;
	double b = 4.2;

	scanf("%d", &a);
	std::cin >> a;

	printf("%d\n", a); 
	std::cout << a << endl;

	printf("%lf\n", b); 
	std::cout << b << endl;

	//连续的输入输出：从左到右
	std::cin >> a >> b;
	std::cout << a << endl << b << endl;
}

/*3.缺省参数*/
//缺省参数是声明或定义函数时为函数的参数指定一个默认值
//在调用该函数时，如果没有指定实参则采用该默认值，否则使用指定的实参
//缺省值为常量或全局变量
void TestFunc1(int a = 0) 
{
	cout << a << endl;
}

//全缺省
void TestFunc2(int a = 0, int b = 3)
{
	cout << a << " " << b << endl;
}

//半缺省
void TestFunc3(int a, int b = 3)
{
	cout << a << " " << b << endl;
}

//半缺省:参数必须从右往左依次赋值，不能间隔着给
//void TestFunc4(int a, int b = 3, int c)
//{
//	cout << a << " " << b << " " << c <<endl;
//}

//缺省参数不能在函数声明和定义中同时出现
//void TestFunc5(int b = 10);
//void TestFunc5(int b = 3)
//{
//	cout << " " << b << endl;
//}

void test3()
{
	TestFunc1();      // 没有传参时，使用参数的默认值
	TestFunc1(10);    // 传参时，使用指定的实参
	TestFunc2();
	TestFunc3(1);
	//TestFunc4();
	//TestFunc5();
}

/*4.函数重载*/
//函数名相同，参数信息不同
//大前提：在同一个作用域
//函数重载:只和函数名和参数有关(类型，个数，顺序)，和返回值无关

//参数信息：参数类型
int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

//参数信息：参数个数
int add(int a, int b, int c)
{
	return a + b + c;
}

//参数信息：参数类型顺序
void Print(int a, char c)
{
	cout << a << c;
}

void Print(char c, int a)
{
	cout << a << c;
}

void test4()
{
	add(1, 2);
	add(1.0, 2.0);
	add(1, 2, 3);
	Print(1, '2');
	Print('1', 2);
}

/*5.extern “C”*/
//有时候在C++工程中可能需要将某些函数按照C的风格来编译，在函数前加extern "C"，意思是告诉编译器，
//将该函数按照C语言规则来编译
extern "C"
{
	void Print1(int a, char c)
	{
		cout << a << c;
	}

	//void Print1(char c, int a)
	//{
	//	cout << a << c;
	//}
}

void test5()
{
	Print1(1, '2');
	//Print1('1', 2);
}

/*6.引用*/
void Swap(int* a, int* b)//C语言写法
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int& SelfAdd(int a)
{
	a++;
	return a;
}

#include <time.h>
struct A {
	int a[10000];
};
//传参数
void TestFunc1(A a)
{}
void TestFunc2(A& a)
{}
//传返回值类型
//A TestFunc1()
//{
//	return a;
//}A& TestFunc2()
//{
//	return a;
//}
void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}

void test6()
{
	int a = 10;
	int b = 20;

	int &rra = SelfAdd(a);
	cout << rra << endl;

	//引用：变量的别名
	/****
	 *注意：
	 *1. 引用在定义时必须初始化
	 *2. 一个变量可以有多个引用
	 *3. 引用一旦引用一个实体，再不能引用其他实体
	 */
	
	//类型& 引用变量名(对象名) = 引用实体；
	int& ra = a;//<====定义引用类型
	int& ra1 = a;
	int& ra2 = a;
	//int& ra3;

	ra = 100;  //a -> 100
	ra = b;    //ra, a, ra1, ra2 -> &b
	printf("%d\n", &a);
	printf("%d\n", &ra);

	//cout << rra << endl;

	//常引用
	//引用类型必须和引用实体是同种类型的
	//int c = 10.0;
	//const int& rc = 10;
	//cout << rc << endl;

	const int d = 10;
	const int& rd = 10;	
	cout << rd << endl;

	Swap(&a, &b);
	Swap(a, b);

	/*****
	*引用的使用场景
	*1. 做参数 Swap
	*2. 做返回值(注意生命周期)
	*如果函数返回时，离开函数作用域后，其栈上空间已经还给系统，因此不能用栈上的空间作为引用类型返回
	*(引用做返回值，引用实体的声明周期 > 函数生命周期)
	*/

	//传值和指针在作为传参以及返回值类型上效率相差很大。
	//引用的效率比传值高很多
	//运行多次，检测值和引用在传参方面的效率区别
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
	}

	//底层实现上，引用通过指针实现
	//引用：类型* const
	//int& ra = a;
	//ra = 100;
	//++a;
	//sizeof(ra);

	//int* pa = &a;
	//int* const cpa = &a;
	//++cpa;
	//sizeof(cpa);
	  /****
       * 引用和指针的不同点:
	   * 1. 引用在定义时必须初始化，指针没有要求
	   * 2. 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型实体
	   * 3. 没有NULL引用，但有NULL指针
	   * 4. 在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占4个字节)
	   * 5. 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小
	   * 6. 有多级指针，但是没有多级引用
	   * 7. 访问实体方式不同，指针需要显式解引用，引用编译器自己处理
	   * 8. 引用比指针使用起来相对更安全
	   **/
}

/*7.内联函数*/
//以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销，
//内联函数提升程序运行的效率 (用空间换时间)

#define Fun(a, b) (a) * (b)
//inline函数不一定都会展开，编译器会根据代码复杂程度酌情展开
inline int Mul(int a, int b)
{
	return a * b;
}

//特性：
//1. inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环 / 递归的函数不适宜使
//用作为内联函数
//2. inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数体内有循环 / 递归等
//等，编译器优化时会忽略掉内联
//3. inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找
//不到

void test7()
{
	int c = Fun(2, 3);
	int d = Mul(2, 3);
}

/*8.auto*/
int TestAuto()
{
	return 10;
}
void test8()
{
	//auto:类型占位符
	//使用auto定义变量时必须对其进行初始化，在编译阶段编译器需要根据初始化表达式来推导auto的实际类
	//型。因此auto并非是一种“类型”的声明，而是一个类型声明时的“占位符”，编译器在编译期会将auto
	//替换为变量实际的类型
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化

	//指针
	auto pa = &a;
	auto* ppa = &a;

	//引用
	auto& ra = a;

	//auto不能用于定义数组和函数参数
	//void funcc(auto a);
	int a[] = { 1, 2, 3 };
	//auto a[] = { 1, 2, 3 };

	//auto同时定义相同类型的变量
	auto e = 1, f = 2;
}

/*9.范围for*/
void test9()
{
	//对于一个有范围的集合而言，由程序员来说明循环的范围是多余的，有时候还会容易犯错误。因此C++11中引
	//入了基于范围的for循环。for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量，
	//第二部分则表示被迭代的范围
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;

	for (auto& e : array)
	    e *= 2;
	for (const auto e : array)
		cout << e << " ";
}

/*10. 指针空值nullptr*/
void fun(int* a)
{
	cout << typeid(a).name() << endl;
}

void test10()
{
	int* p1 = NULL;
	int* p2 = 0;
	//nullptr类型 -->nullptr_t
	//nullptr可以进行隐式类型转换，转换成任意类型的指针空值
	int* p3 = nullptr;

	fun(NULL);
	fun((int*) NULL);
	fun(p3);
}

int main()
{
	//test1(); 
	//cout << endl;
	//test2();
	//cout << endl;
	//test3();
	//cout << endl;
	//test4();
	//cout << endl;
	//test5();
	//cout << endl;
	//test6();
	//cout << endl;
	//test7();
	//cout << endl;
	//test8();
	//cout << endl;
	//test9();
	//cout << endl;
	test10();
	cout << endl;
	return 0;
}