#include <stdio.h>

/*�����ռ�*/
/*
1.�ֶζ��塢Ƕ�׶���
2.�����ռ��Աʹ�÷�ʽ
  �����ռ�+::+��Ա(�Ƽ�)
  �����Ա using+�����ռ�+::+��Ա������ʹ�ó�Աʱ������Ҫ��������,��Ա��¶��ȫ���У����ȫ�����У����������ͻ
  չ�������ռ� using+�����ռ�
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
	//int a;�ض���
}

int a;
int b;
using bit::func2;
//using namespace bit;

void test()
{
	bit::a = 1;
	bit::print(bit::a);//����bit�����ռ��µĳ�Աa
	bit::print(a);//����ȫ��a
	func2();
	::a; //(ȫ��������)
}

/*ȱʡ����*/
//��������˳�򣺴�����
void func1(int a = 1, int b = 1, int c = 1)
{

}
void func2(int a, int b = 1, int c = 1);
//void func2(int a=1, int b , int c = 1);
void func3(int a, int b, int c = 1)
{

}

/*����*/
void test()
{
	//����+&+��������
	int a = 10;
	int& ra = a;//a�ı���
	int& ra2 = a;
	ra = 100;
	//���ö���ʱ�����ʼ��
	//int& ra3;

	const int b = 10;
	const int& rb = b;
}

int main()
{
	func1();
	return 0;
}

