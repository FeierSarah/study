/*类和对象*/
#include <iostream>
using namespace std;
class ct{
	int a;
public:
	double b;
	char c;
	void test()
	{

	}
	void changeA(int i)
	{
		a = i;
	}
	void printA() //成员函数中可以直接使用自己的成员变量
	{
		printf("%d\n", a);
	}
protected:
	void printB();
};
void ct::printB()
{
	printf("%.2lf\n", b);
}
int main()
{
	ct c;
	ct d;
	ct * pc = nullptr;
	c.changeA(5);
	c.printA();
	d.changeA(6);
	d.printA();
	pc->test();
	//cout << sizeof(ct) << endl;
	return 0;
}


struct A1{
	int a;
	double b;
};
struct A2{

};
struct A3{
	int a;
	double b;
	char c;
	void printA()
	{
		printf("%d\n", a);
	}
	void printB();
};
void A3::printB()
{
	printf("%.2lf\n", b);
}
int structtest()
{
	printf("%d %d %d\n", sizeof(A1), sizeof(A2), sizeof(A3));
	//printf("%p %p %p\n%p\n", &test.a, &test.b, &test.c, &test);
	A3 test;
	test.a = 5;
	test.printA();
	test.b = 3.14;
	test.printB();
	return 0;
}