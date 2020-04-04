#include <vector>
using namespace std;
/*
数据单元更小的哈希表
哈希函数(可以认为是直接定址法， 线性函数)： num  /   32,   num % 32
*/
class BitMap
{
public:
	BitMap(size_t range)
	{
		_array.resize((range >> 5) + 1);
	}

	//存放数据
	void set(int data)
	{
		//通过哈希函数计算位置
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] |= (1 << bitIdx);
	}
	//查找
	bool test(int data)
	{
		//通过哈希函数计算位置
		int idx = data >> 5;
		int bitIdx = data % 32;
		return (_array[idx] >> bitIdx) & 1;
	}
	//删除操作
	void reset(int data)
	{
		//通过哈希函数计算位置
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] &= ~(1 << bitIdx);
	}

private:
	vector<int> _array;
};

void test()
{
	BitMap bm(500);
	bm.set(511);
	bm.set(16);
	bm.set(63);
	bool ret = bm.test(511);
	ret = bm.test(63);
	ret = bm.test(16);
	ret = bm.test(100);
	bm.reset(16);
	ret = bm.test(16);
}

int main()
{
	test();
	return 0;
}