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

//	//this�Ƿ����Ϊ��
//	//����Ϊ�գ������н�����
//	//thisָ�뱾������ʵ��һ����Ա�������βΣ��Ƕ�����ó�Ա����ʱ���������ַ��Ϊʵ�δ��ݸ�this�βΡ����Զ����в��洢thisָ��

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

//���캯����һ������ĳ�Ա������������������ͬ, ���������Ͷ���ʱ�ɱ������Զ����ã���֤ÿ�����ݳ�Ա
//���� һ�����ʵĳ�ʼֵ�������ڶ��������������ֻ����һ��
void testContrust()
{
	//���캯����ʵ����ʱ������ֻ���ã�������������ֻ����1��
	//�޲ι��캯������������ţ������Ǻ�������
	Date d;

	//Date d3(); //��������

	Date d2;
	d2.SetDate(2019, 10, 21);

	//��������
	Date d3(d2);
	Date d4 = d3;
	/*Date d5 = Date(2019, 10, 20);*/

	//��ֵ
	Date d5;
	d5 = d1;
	d3 = d2 = d1; //������ֵ
	cout << d5 == d1 << endl;

	//const
	const Date d4(2019, 10, 24);
	d4.Display();//��const����ĳ���ֻ�ܵ��ô���const�ĳ�Ա����
	             //Ȩ�޿�����С�������ԷŴ�

	//ȡ��ַ
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