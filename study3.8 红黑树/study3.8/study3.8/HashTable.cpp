#include <vector>
#include <utility>
#include <iostream>
using namespace std;
//״̬�� ���Ԫ�أ� ���ڣ�ɾ������
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
		// resize֮�����ʹ��[]�����������
		_table.resize(N);
		for (int i = 0; i < N; ++i)
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}

	bool insert(const pair<K, V>& value)
	{
		//�������
		CheckCapcity();

		int idx = value.first % _table.size();
		while (_table[idx]._state == EXIST)
		{
			if (_table[idx]._value.first == value.first)
				return false;
			++idx;
			//����ߵ���β�����ͷ��ʼ����
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
		//�����������ӣ���Ҫ����
		if (_size * 10 / _table.size() >= 7)
		{
			int newC = _table.size() * 2;
			//����,����ֱ��resize��Ԫ�����±��е�λ�ÿ��ܻ�仯
			//_table.resize(newC);
			//���±��ɱ��е�ÿһ��Ԫ�����¼������±��е�λ��
			HashTable<K, V> newHt(newC);
			for (int i = 0; i < _table.size(); ++i)
			{
				//�ɱ�����ЧԪ�ش����±�
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
		//����ʱ�����ս���
		while (_table[idx]._state != EMPTY)
		{
			//delete,exit
			if (_table[idx]._state == EXIST && _table[idx]._value.first == key)
				return &_table[idx];
			++idx;
			//idx�Ƿ�Խ��
			if (idx == _table.size())
				++idx;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		//����
		Node* node = find(key);
		if (node != nullptr)
		{
			--_size;
		    return true;
		}
	    return false;
	}
private:
	vector<Node> _table;
	size_t _size;  //���Ԫ�ظ�����
};

void testHt()
{
	HashTable<int, int>ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(10, 10));
	ht.insert(make_pair(12, 12));
	ht.insert(make_pair(54, 54));
	ht.insert(make_pair(2, 2));

	cout << ht.erase(10) << endl;
}