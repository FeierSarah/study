#include <vector>
#include <string>
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

template <class K, class HF1, class HF2, class HF3>
class BloomFilter
{
public:
	// k = m/n * ln2  m =  nk /  ln2  =  n *  k / ln2 =  n *  k / 0.6931
	BloomFilter(size_t range)
		:_bm(range * 5)
		, _bitNum(range * 5)
	{}

	void set(const K& key)
	{
		// 防止idx越界： % _bitNum
		size_t idx1 = HF1()(key) % _bitNum;
		size_t idx2 = HF2()(key) % _bitNum;
		size_t idx3 = HF3()(key) % _bitNum;
		_bm.set(idx1);
		_bm.set(idx2);
		_bm.set(idx3);
	}

	bool test(const K& key)
	{
		size_t idx1 = HF1()(key) % _bitNum;
		size_t idx2 = HF2()(key) % _bitNum;
		size_t idx3 = HF3()(key) % _bitNum;
		if (!_bm.test(idx1))
			return false;  //正确
		if (!_bm.test(idx2))
			return false;  //正确
		if (!_bm.test(idx3))
			return false;   //正确

		return true;  // 误判
	}
	//一般不提供
	//reset();
private:
	BitMap _bm;
	size_t _bitNum;

};

struct HF1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

struct HF2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
};

struct HF3
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		size_t magic = 63689;
		for (const auto& ch : str)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
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

void testBloomFilter()
{
	BloomFilter<string, HF1, HF2, HF3> bf(10);
	string str1 = "1234fhladgljghoifsajglkjhtjligjgjgigjigjivnjfjdaj";
	string str2 = "1234fhladgljghoifsajglkjhtjligjgjgigjigjivnjfjdak";
	string str3 = "1234fhladgljghoifsajglkjhtjligjgjgigjigjivnjfjdal";

	bf.set(str1);
	bf.set(str2);
	bf.set(str3);

	bool ret = bf.test(str1);
	ret = bf.test(str2);
	ret = bf.test(str3);
	ret = bf.test(str3 + 'a');
}

int main()
{
	//test();
	testBloomFilter();
	return 0;
}