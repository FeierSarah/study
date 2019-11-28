#include<array>
#include<iostream>
#include<string>
using namespace std;

//#define N 100
//非类型模板参数，可作为常量使用
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
	//有限制大小，一般不大
	//array<int, 10000000> arr3;
	int a = 10;
	int arr4[10];
}

//函数模板
template <class T>
bool isBig(T& a, T& b)
{
	return a > b;
}

//函数模板不推荐使用
template <>
bool isBig<char*>(char*& a, char*& b)
{
	return strcmp(a, b) > 0;
}

void testString()
{
	//普通函数和模板函数共存，优先运行普通函数
	char* str1 = "123";
	char* str2 = "456";
	bool ret = isBig(str1, str2);//没有函数模板则进行的是比地址的操作
	int a = 1, b = 2;
	ret = isBig(a, b);//符合普通模板则执行普通模板
}

//普通
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>
class Data<int, char> {
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	int _d2;
};

//偏特化:特化部分参数

// 将第二个参数特化为int
template <class T1>
class Data<T1, int> {
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
//偏特化：限制函数
//两个参数偏特化为指针类型
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
//特化的运用
template<>
struct Sum<1>
{
	enum{RET = 1};
};
void Sumtest()
{
	//求解1+2+。。。+10的操作
	cout << Sum<10>::RET;
}

template <class T>//内置类型调用浅拷贝，
void Copy(T* dest, T* src, size_t sz)
{
	memcpy(dest, src, sizeof(T)* sz);
}

template <class T>//自定义类型调用深拷贝
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