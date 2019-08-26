#include<vector>
#include<iostream>
#include<typeinfo>
using namespace std;
///*函数重载*/
//int func(int a)
//{
//	return a;
//}
//int func(int b)
//{
//	return b;
//}
////在C语言中，名字修饰只是在函数名前加下划线，所以只要函数名相同就会导致冲突，
////在C++中，名字修饰是由“？函数名@域名1@域名2...@@参数列表@z
//
///*引用*/
//int main()
//{
//	int ming = 5;
//	int &xiaoming = ming;
//	cout << &ming << endl;
//	cout << &xiaoming << endl;
//	cout << xiaoming << endl;
//	return 0;
//	//引用不是新定义一个变量，而是给已存在变量取了一个别名，编译器不会为引用变量开辟内存空间，它和它引用的变量共用同一块内存空间。
//}
//
//void func(int &a, int &b)
//{
//	int tmp;
//	tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 5;
//	int b = 6;
//	int &ra = a;
//	int &rb = b;
//	func(a, b);
//	cout << a << " " << b << endl;
//}//C++函数实现两数交换数值
//
//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a;   // 该语句编译时会出错，a为常量
//	const int& ra = a;
//	// int& b = 10; // 该语句编译时会出错，b为常量
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//	const int& rd = d;
//}//常引用
//
//int &test1(int &a)
//{
//	return a;
//}
//int test2(int &a)
//{
//	return a;
//}
//int main()
//{
//	int a = 3;
//	cout << test1(a) << endl;
//	cout << test2(a) << endl;
//	return 0;
//}//引用做参数和返回值
//
//struct A{
//	int a[10000];
//};
//void test1(A &a)
//{
//	
//}
//void test2(A a)
//{
//	
//}
//int main()
//{
//	A a;
//	for (int i = 0; i < 10000; i++)
//	{
//		test1(a);//test 1.2相比，传引用速度快了近400倍，C中指针亦然
//		//返回引用和返回指针速度差不多，引用是通过指针实现的
//	}
//	return 0;
//}
//
//int& Add(int a, int b) 
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;   //7   //返回c的引用，c的位置未发生改变
//	//理论上ret返回应该为随机值，但这题返回7
//	return 0;
//}
//// 如果函数返回时，离开函数作用域后，其栈上空间已经还给系统，因此不能用栈上的空间作为引用类型
////返回。如果以引用类型返回，返回值的生命周期必须不受函数的限制(即比函数生命周期长)。
//
//int &test1(int &a)
//{
//	return a;
//}
//int test2(int &a)
//{
//	return a;
//}
//int *test3(int *pa)
//{
//	return pa;
//}
//int main()
//{
//	int a = 3;
//	cout << test2(a) << endl;
//	cout <<( test1(a)=4) << endl;//若返回为引用，可直接赋值
//	*test3(&a) = 5;//若返回值为指针，可对指针解引用，再进行赋值
//	return 0;
//}
//
///*auto*/
int main()
{
	int i = 0;
	auto j = i;      //int
	//auto j = &i;     //int *
	cout << typeid(j).name() << endl;
	return 0;
}//参数不能包括auto类型，数组的元素类型不能包括auto类型