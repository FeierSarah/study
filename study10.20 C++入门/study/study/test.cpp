#include <iostream>
#include <cstdio>
using namespace std;

/*1.�����ռ�*/
/****
*�����ռ��Ա���ʷ�ʽ��1.�����ռ����� + :: + ������
*                      2.using + �����ռ����� + :: + ������
*                      3.using namespace + �����ռ����� ->���г�Աȫ����¶��ȫ����(���Ƽ�)
**/

namespace N1
{
	int a;
	int add(int a, int b)
	{
		return a + b;
	}
}

//�����ռ��Ƕ��
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

//�����ռ�ķֶζ���
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

/*2.�������*/
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

	//���������������������
	std::cin >> a >> b;
	std::cout << a << endl << b << endl;
}

/*3.ȱʡ����*/
//ȱʡ�������������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ
//�ڵ��øú���ʱ�����û��ָ��ʵ������ø�Ĭ��ֵ������ʹ��ָ����ʵ��
//ȱʡֵΪ������ȫ�ֱ���
void TestFunc1(int a = 0) 
{
	cout << a << endl;
}

//ȫȱʡ
void TestFunc2(int a = 0, int b = 3)
{
	cout << a << " " << b << endl;
}

//��ȱʡ
void TestFunc3(int a, int b = 3)
{
	cout << a << " " << b << endl;
}

//��ȱʡ:������������������θ�ֵ�����ܼ���Ÿ�
//void TestFunc4(int a, int b = 3, int c)
//{
//	cout << a << " " << b << " " << c <<endl;
//}

//ȱʡ���������ں��������Ͷ�����ͬʱ����
//void TestFunc5(int b = 10);
//void TestFunc5(int b = 3)
//{
//	cout << " " << b << endl;
//}

void test3()
{
	TestFunc1();      // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
	TestFunc1(10);    // ����ʱ��ʹ��ָ����ʵ��
	TestFunc2();
	TestFunc3(1);
	//TestFunc4();
	//TestFunc5();
}

/*4.��������*/
//��������ͬ��������Ϣ��ͬ
//��ǰ�᣺��ͬһ��������
//��������:ֻ�ͺ������Ͳ����й�(���ͣ�������˳��)���ͷ���ֵ�޹�

//������Ϣ����������
int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

//������Ϣ����������
int add(int a, int b, int c)
{
	return a + b + c;
}

//������Ϣ����������˳��
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

/*5.extern ��C��*/
//��ʱ����C++�����п�����Ҫ��ĳЩ��������C�ķ�������룬�ں���ǰ��extern "C"����˼�Ǹ��߱�������
//���ú�������C���Թ���������
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

/*6.����*/
void Swap(int* a, int* b)//C����д��
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
//������
void TestFunc1(A a)
{}
void TestFunc2(A& a)
{}
//������ֵ����
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
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}

void test6()
{
	int a = 10;
	int b = 20;

	int &rra = SelfAdd(a);
	cout << rra << endl;

	//���ã������ı���
	/****
	 *ע�⣺
	 *1. �����ڶ���ʱ�����ʼ��
	 *2. һ�����������ж������
	 *3. ����һ������һ��ʵ�壬�ٲ�����������ʵ��
	 */
	
	//����& ���ñ�����(������) = ����ʵ�壻
	int& ra = a;//<====������������
	int& ra1 = a;
	int& ra2 = a;
	//int& ra3;

	ra = 100;  //a -> 100
	ra = b;    //ra, a, ra1, ra2 -> &b
	printf("%d\n", &a);
	printf("%d\n", &ra);

	//cout << rra << endl;

	//������
	//�������ͱ��������ʵ����ͬ�����͵�
	//int c = 10.0;
	//const int& rc = 10;
	//cout << rc << endl;

	const int d = 10;
	const int& rd = 10;	
	cout << rd << endl;

	Swap(&a, &b);
	Swap(a, b);

	/*****
	*���õ�ʹ�ó���
	*1. ������ Swap
	*2. ������ֵ(ע����������)
	*�����������ʱ���뿪�������������ջ�Ͽռ��Ѿ�����ϵͳ����˲�����ջ�ϵĿռ���Ϊ�������ͷ���
	*(����������ֵ������ʵ����������� > ������������)
	*/

	//��ֵ��ָ������Ϊ�����Լ�����ֵ������Ч�����ܴ�
	//���õ�Ч�ʱȴ�ֵ�ߺܶ�
	//���ж�Σ����ֵ�������ڴ��η����Ч������
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
	}

	//�ײ�ʵ���ϣ�����ͨ��ָ��ʵ��
	//���ã�����* const
	//int& ra = a;
	//ra = 100;
	//++a;
	//sizeof(ra);

	//int* pa = &a;
	//int* const cpa = &a;
	//++cpa;
	//sizeof(cpa);
	  /****
       * ���ú�ָ��Ĳ�ͬ��:
	   * 1. �����ڶ���ʱ�����ʼ����ָ��û��Ҫ��
	   * 2. �����ڳ�ʼ��ʱ����һ��ʵ��󣬾Ͳ�������������ʵ�壬��ָ��������κ�ʱ��ָ���κ�һ��ͬ����ʵ��
	   * 3. û��NULL���ã�����NULLָ��
	   * 4. ��sizeof�к��岻ͬ�����ý��Ϊ�������͵Ĵ�С����ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ���(32λƽ̨��ռ4���ֽ�)
	   * 5. �����ԼӼ����õ�ʵ������1��ָ���ԼӼ�ָ�����ƫ��һ�����͵Ĵ�С
	   * 6. �ж༶ָ�룬����û�ж༶����
	   * 7. ����ʵ�巽ʽ��ͬ��ָ����Ҫ��ʽ�����ã����ñ������Լ�����
	   * 8. ���ñ�ָ��ʹ��������Ը���ȫ
	   **/
}

/*7.��������*/
//��inline���εĺ���������������������ʱC++���������ڵ������������ĵط�չ����û�к���ѹջ�Ŀ�����
//�������������������е�Ч�� (�ÿռ任ʱ��)

#define Fun(a, b) (a) * (b)
//inline������һ������չ��������������ݴ��븴�ӳ̶�����չ��
inline int Mul(int a, int b)
{
	return a * b;
}

//���ԣ�
//1. inline��һ���Կռ任ʱ���������ʡȥ���ú�����������Դ���ܳ�������ѭ�� / �ݹ�ĺ���������ʹ
//����Ϊ��������
//2. inline���ڱ���������ֻ��һ�����飬���������Զ��Ż����������Ϊinline�ĺ���������ѭ�� / �ݹ��
//�ȣ��������Ż�ʱ����Ե�����
//3. inline�����������Ͷ�����룬����ᵼ�����Ӵ�����Ϊinline��չ������û�к�����ַ�ˣ����Ӿͻ���
//����

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
	//auto:����ռλ��
	//ʹ��auto�������ʱ���������г�ʼ�����ڱ���׶α�������Ҫ���ݳ�ʼ�����ʽ���Ƶ�auto��ʵ����
	//�͡����auto������һ�֡����͡�������������һ����������ʱ�ġ�ռλ�������������ڱ����ڻὫauto
	//�滻Ϊ����ʵ�ʵ�����
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��

	//ָ��
	auto pa = &a;
	auto* ppa = &a;

	//����
	auto& ra = a;

	//auto�������ڶ�������ͺ�������
	//void funcc(auto a);
	int a[] = { 1, 2, 3 };
	//auto a[] = { 1, 2, 3 };

	//autoͬʱ������ͬ���͵ı���
	auto e = 1, f = 2;
}

/*9.��Χfor*/
void test9()
{
	//����һ���з�Χ�ļ��϶��ԣ��ɳ���Ա��˵��ѭ���ķ�Χ�Ƕ���ģ���ʱ�򻹻����׷��������C++11����
	//���˻��ڷ�Χ��forѭ����forѭ�����������ð�š� ������Ϊ�����֣���һ�����Ƿ�Χ�����ڵ����ı�����
	//�ڶ��������ʾ�������ķ�Χ
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

/*10. ָ���ֵnullptr*/
void fun(int* a)
{
	cout << typeid(a).name() << endl;
}

void test10()
{
	int* p1 = NULL;
	int* p2 = 0;
	//nullptr���� -->nullptr_t
	//nullptr���Խ�����ʽ����ת����ת�����������͵�ָ���ֵ
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