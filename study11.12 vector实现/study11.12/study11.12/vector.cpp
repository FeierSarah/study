#include <iostream>
using namespace std;
template <class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{}
	void pushback(const T& val)
	{
		//容量
		if (_finish == _eos)
		{
			size_t newC = start == nullptr ? 1 : 2 * Capacity();
			Reserv0e....(newC);
		}
		*_finish = val;
		++_finish;
	}
	size_t Capacity()
	{
		return _eos - _start;
	}

	void Reserve(size_t n)
	{
		int sz = Size();
		if (n > Capacity())
		{
			//开空间
			T* tmp = new T[n];
			//拷贝
			memcpy(tmp, _start, sizeof(T)* Size());
			//释放原有的空间
			delete[] _start;

			_start = tmp;
			_finish = _start + sz;
			_eos = _start + n;
		}
	}

	size_t Size()
	{
		return _finish - _start;
	}

	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}
private:
	iterator _start;
	iterator _finish;
	iterator _eos;
};

void PrintVec(const vector<int>& vec)
{
	for (size_t i = 0; i < vec.Size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void TestVec1()
{
	Vector<int> v;
	v.pushback(1);
	v.pushback(2);
	v.pushback(3);
	v.pushback(4);
}

int main()
{
	return 0;
}