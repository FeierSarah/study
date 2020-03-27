#include <vector>
#include <utility>
#include <iostream>
using namespace std;
//状态， 标记元素： 存在，删除，空
enum State
{
	EXIST,
	DELETE,
	EMPTY
};

template <class K, class V>
struct Node
{
	pair<K, V> _value;
	State _state;
};

template <class K, class V>
class HashTable
{
public:
	typedef Node<K, V> Node;

	HashTable(size_t N = 2)
	{
		//_table.reserve(N);
		// resize之后可以使用[]进行随机访问
		_table.resize(N); 
		for (size_t i = 0; i < N; ++i)
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}

	bool insert(const pair<K, V>& value)
	{
		//检查容量
		checkCapcity();

		int idx = value.first % _table.size();
		while (_table[idx]._state == EXIST)
		{
			if (_table[idx]._value.first == value.first)
				return false;
			++idx;
			//如果走到表尾，则从头开始查找
			if (idx == _table.size())
				idx = 0;
		}
		_table[idx]._value = value;
		_table[idx]._state = EXIST;
		++_size;
		return true;
	}

	void checkCapcity()
	{
		//超过负载因子， 需要增容
		if (_size * 10 / _table.size() >= 7)
		{
			int newC = _table.size() * 2;
			//增容： 不能直接resize, 元素在新表中的位置可能会发生变化
			//_table.resize(newC);
			//建新表，旧表中的每一个元素重新计算他们在新表中位置
			HashTable<K, V> newHt(newC);
			for (size_t i = 0; i < _table.size(); ++i)
			{
				//旧表中有效元素全部存入新表
				if (_table[i]._state == EXIST)
				{
					newHt.insert(_table[i]._value);
				}
			}

			_table.swap(newHt._table);
		}
	}

	Node* find(const K& key)
	{
		int idx = key % _table.size();
		//查找时遇到空结束
		while (_table[idx]._state != EMPTY)
		{
			// DELETE,  EXIST
			if (_table[idx]._state == EXIST &&_table[idx]._value.first == key)
				return &_table[idx];
			++idx;   // idx += 2   idx += 4   idx += 8
			//idx是否越界
			if (idx == _table.size())
				++idx;
		}

		return nullptr;
	}

	bool erase(const K& key)
	{
		//查找
		Node* node = find(key);
		//如果找到了，假删除
		if (node)
		{
			node->_state = DELETE;
			--_size;
			return true;
		}
		return false;
	}

	void hashTablePrint()
	{
		for (int i = 0; i < _table.size(); ++i)
		{
			if (_table[i]._state == EXIST)
				cout << _table[i]._value.first << "--->" << _table[i]._value.second << "\t";
		}
		cout << endl;
	}

private:
	vector<Node> _table;
	size_t _size;  //存放元素个个数
};

void testHT()
{
	HashTable<int, int> ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(18, 18));
	ht.insert(make_pair(23, 23));
	ht.insert(make_pair(4, 4));
	ht.insert(make_pair(54, 54));
	ht.hashTablePrint();
	cout << ht.erase(18) << endl;
	ht.hashTablePrint();
	cout << ht.erase(100) << endl;
	ht.hashTablePrint();

}


int main()
{
	testHT();
	return 0;
}
