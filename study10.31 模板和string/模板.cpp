#include<iostream>
using namespace std;
template<typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T add(const T& a, const T& b) {
	return a + b;
}

int add(const int& a, const int& b) {
	return a + b;
}

template<typename T, typename T2>
T add(const T& a, const T2& b) {
	return a + b;
}

//template<class T>
//void swap(T* a, T* b) {
//
//}

class A {
public:
	A(int a = 0) 
		: _a(a)
	{}
private:
	int _a;
};

//int main() {
//	int a = 1, b = 2;
//	char c = 'a', d = 'b';
//	double e = 1.1, f = 2.2;
//	//隐式实例化
//	swap(a, b);//swap(int, int)
//	swap(c, d);//swap(char, char)
//	swap(e, f);//swap(double, double)
//	A ao = 10;
//	A bo = 20;
//	swap(ao, bo);//swap(A, A)
//
//	const double& rd = a;//
//	add((double)a, e);//强制类型转换是临时的，所以是const类型
//
//	//显式实例化
//	add<int>(a, e);
//	return 0;
//}

//int main() {
//	int a = 1, b = 2;
//	swap(a, b);//非模板函数和模板函数共存的时候，优先匹配非模板函数
//
//	double c = 1.2;
//	//非模板函数和模板函数共存的时候，优先匹配非模板函数
//	//如果不能完全匹配，实例化可以生成更加匹配的代码，则走实例化
//	add(a, c);
//
//	//如果声明显式实例化，一定会进行实例化
//	add<int>(a, b);
//
//	return 0;
//}

//typedef int DataType;
template<class DataType>//所有抽象类型实例化的时候都会变成具体类型
class SeqList {
public:
	SeqList(int num = 10) 
		: _data(new DataType[num])
		, _size(num)
		, _capacity(num)
	{}

	//浅拷贝
	SeqList<DataType>& operator = (const SeqList<DataType>& sq) {
		if (this != &sq) {
			_data = sq._data;
			_size = sq._size;
			_capacity = sq._capacity;
		}
		return *this;
	}

	void Display() {
		for (int i = 0; i < _size; ++i) {
			cout << _ data[i] << endl;
		}
	}

	DataType& operator[](size_t pos);
//	{//返回值是临时const变量，不能被修改;要返回引用类型才能修改
//		return _data[pos];
//	}

	~SeqList() {
		if (_data) {
			delete[] data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	size_t Size() {
		return _size;
	}
private:
	DataType* _data;
	size_t _size;
	size_t _capacity;
};

template<class DataType>
DataType& SeqList<DataType>::operator[] (size_t pos) {
	return _data[pos];
}

int main() {
	//类模板：
	//类名 != 类型
	//类名     类名<类型>
	SeqList<int> s1;
	SeqList<int> s12;
	SeqList<char> s2;
	SeqList<float> s3;

	for (int i = 0; i < s1.Size(); ++i) {
		//s1[i] <---> s1.operator[](i)
		s1[i] = i;
		//s1.operator[](i) = i;
		cout << s1[i] << endl;
	}

	s1 = s12;//同一个地方走析构的时候将会被释放两次，不能这样用
	return 0;
}














