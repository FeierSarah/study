#include<array>
#include<iostream>
#include<string>
using namespace std;

//#define N 100
//������ģ�����������Ϊ����ʹ��
template <class T, size_t N>
class array
{
private:
	_arr[N];
};

void testArray()
{
	array<int, 100> arr;
	array<int, 20> arr2;
	//�����ƴ�С��һ�㲻��
	//array<int, 10000000> arr3;
	int a = 10;
	int arr4[10];
}

//����ģ��
template <class T>
bool isBig(T& a, T& b)
{
	return a > b;
}

//����ģ�岻�Ƽ�ʹ��
template <>
bool isBig<char*>(char*& a, char*& b)
{
	return strcmp(a, b) > 0;
}

void testString()
{
	//��ͨ������ģ�庯�����棬����������ͨ����
	char* str1 = "123";
	char* str2 = "456";
	bool ret = isBig(str1, str2);//û�к���ģ������е��Ǳȵ�ַ�Ĳ���
	int a = 1, b = 2;
	ret = isBig(a, b);//������ͨģ����ִ����ͨģ��
}

//��ͨ
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//ȫ�ػ�
template<>
class Data<int, char> {
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	int _d2;
};

//ƫ�ػ�:�ػ����ֲ���

// ���ڶ��������ػ�Ϊint
template <class T1>
class Data<T1, int> {
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
//ƫ�ػ������ƺ���
//��������ƫ�ػ�Ϊָ������
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

void TestVector()
{
	Data<char, int> d1;
	Data<int, int> d2;
	Data<int, char> d3;
}

template<size_t N>
struct Sum
{
	enum{RET = N + Sum<N-1>::RET};
};
//�ػ�������
template<>
struct Sum<1>
{
	enum{RET = 1};
};
void Sumtest()
{
	//���1+2+������+10�Ĳ���
	cout << Sum<10>::RET;
}

template <class T>//�������͵���ǳ������
void Copy(T* dest, T* src, size_t sz)
{
	memcpy(dest, src, sizeof(T)* sz);
}

template <class T>//�Զ������͵������
void Copy(T* dest, T* src, size_t sz)
{
	
	for (size_t i = 0; i < sz; i++)
	{
		dest[i] = src[i];
	}
}

void testMemcpy()
{
	string strArr[] = { "1","2","3" };
	string strcopy;
	//Copy(strcopy, strArr, 3);
	//Copy(strcopy, strArr, 3);

}

int main()
{
	testArray();
	return 0;
}