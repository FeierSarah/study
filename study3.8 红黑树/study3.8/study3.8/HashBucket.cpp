#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <time.h>
using namespace std;
template <class K>
struct KeyOfValue
{
	const K& operator()(const K& key)
	{
		return key;
	}
};

// ����+������

//������ڵ�
template <class V>
struct HashNode
{
	HashNode<V>* _next;
	V _data;

	HashNode(const V& data = V())
		:_data(data)
		, _next(nullptr)
	{}
};

//ǰ������
template <class K, class V, class KeyOfValue, class HFun>
class HashBucket;

template <class K, class V, class KeyOfValue, class HFun>
struct HIterator
{
	typedef HashNode<V> Node;
	typedef Node* pNode;

	typedef HashBucket<K, V, KeyOfValue, HFun> htable;

	typedef HIterator<K, V, KeyOfValue, HFun> Self;

	pNode _node;
	htable* _ht;

	HIterator(pNode node, htable* ht)
		:_node(node)
		, _ht(ht)
	{}

	V& operator*()
	{
		return _node->_data;
	}

	V* operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else{
			//�ҵ���ǰ��ϣ������һ���ǿ������ͷ��㣬 ����

			//���㵱ǰ�ڵ��ڱ��е�λ��
			KeyOfValue kov;
			HFun hf;
			//int idx = kov(_node->_data) % _ht->getTableSize();
			// ��Ԫ�����ֱ�ӷ���˽�г�Ա
			size_t idx = hf(kov(_node->_data)) % _ht->_table.size();
			//�ӹ�ϣ�����һ��λ�ÿ�ʼ�ҵ���һ���ǿ������ͷ���
			++idx;
			for (; idx < _ht->_table.size(); ++idx)
			{
				if (_ht->_table[idx])
				{
					//�ҵ��˵�һ���ǿ������ͷ���
					_node = _ht->_table[idx];
					break;
				}
			}
			//�п��ܺ���Ľڵ㶼Ϊ�սڵ�
			if (idx == _ht->_table.size())
				_node = nullptr;  //��ʾ��end��������λ��
		}
		return *this;
	}

};

template <class K, class V, class KeyOfValue, class HFun>
class HashBucket
{
public:
	//����������Ϊ��ϣ�����Ԫ��
	template <class K, class V, class KeyOfValue, class HFun>
	friend struct HIterator;

	typedef HashNode<V> Node;
	typedef Node* pNode;

	typedef HIterator<K, V, KeyOfValue, HFun> iterator;

	iterator begin()
	{
		//�ҵ�һ���ǿ������ͷ���
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i])
				return iterator(_table[i], this);
		}
		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	//����������ظ�Ԫ��
	pair<iterator, bool> insert(const V& data)
	{
		checkCapacity();

		//����key�Ƿ��Ѿ�����
		//����λ��
		KeyOfValue kov;
		HFun hf;
		int idx = hf(kov(data)) % _table.size();
		pNode cur = _table[idx];
		while (cur)
		{
			if (kov(cur->_data) == kov(data))
				//return false;
				return make_pair(iterator(cur, this), false);
			cur = cur->_next;
		}
		//����, ͷ��
		cur = new Node(data);
		cur->_next = _table[idx];
		_table[idx] = cur;

		++_size;
		//return true;
		return make_pair(iterator(cur, this), true);
	}

	//������: ���͹�ϣ��ͻ
	size_t getPrime(size_t num)
	{
		const int PRIMECOUNT = 28;
		static const size_t primeList[PRIMECOUNT] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};

		for (int i = 0; i < PRIMECOUNT; ++i)
		{
			if (primeList[i] > num)
				return primeList[i];
		}
		return primeList[PRIMECOUNT - 1];
	}

	void checkCapacity()
	{
		//�������ӣ� ����Ϊ1
		if (_size == _table.size())
		{
			//size_t newC = _table.size() == 0 ? 10 : 2 * _table.size();
			size_t newC = getPrime(_table.size());

			//�����µ�vector
			vector<pNode> newT;
			newT.resize(newC);
			KeyOfValue kov;
			HFun hf;
			//�����ɱ��ɱ�ڵ����¹��ص��±���
			for (size_t i = 0; i < _table.size(); ++i)
			{
				//��ȡ��ǰλ�õ������ͷ
				pNode cur = _table[i];
				//������ǰ�����ÿһ���ڵ㣬���¼���λ��
				while (cur)
				{
					//���ȱ���ɱ��next�ڵ�
					pNode next = cur->_next;

					int idx = hf(kov(cur->_data)) % newT.size();
					//ͷ��
					cur->_next = newT[idx];
					newT[idx] = cur;

					cur = next;
				}
				//�ɱ�ǰλ�ñ�ɿ�����
				_table[i] = nullptr;
			}
			//������
			_table.swap(newT);
		}
	}

	size_t getTableSize()
	{
		return _table.size();
	}

	bool erase(const K& key);

	pNode find(const K& key);

private:
	//ָ������
	vector<pNode> _table;
	size_t _size = 0;
};

template <class K>
struct HashFun
{
	//ʵ��һ�������ϣֵ��()���غ���
	int operator()(const K& key)
	{
		return key;
	}
};

//ģ���ػ�
template <>
struct HashFun<string>
{
	//ʵ��һ�������ϣֵ��()���غ���
	int operator()(const string& key)
	{
		//��string ת����int
		int hash = 0;
		for (const auto& ch : key)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

template <class K, class V, class HFun = HashFun<K>>
class UnorderedMap
{

	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename HashBucket<K, pair<K, V>, MapKeyOfValue, HFun>::iterator iterator;
	iterator begin()
	{
		return _hb.begin();
	}

	iterator end()
	{
		return _hb.end();
	}
	pair<iterator, bool> insert(const pair<K, V>& data)
	{
		return _hb.insert(data);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _hb.insert(make_pair(key, V()));
		return ret.first->second;
	}

	//��ϣ��ʵ��
private:
	HashBucket<K, pair<K, V>, MapKeyOfValue, HFun> _hb;
};

template <class V, class HFun = HashFun<V>>
class UnorderedSet
{

	struct SetKeyOfValue
	{
		const V& operator()(const V& data)
		{
			return data;
		}
	};
public:
	typedef typename HashBucket<V, V, SetKeyOfValue, HFun>::iterator iterator;
	iterator begin()
	{
		return _hb.begin();
	}

	iterator end()
	{
		return _hb.end();
	}
	pair<iterator, bool> insert(const V& data)
	{
		return _hb.insert(data);
	}

	//��ϣ��ʵ��
private:
	HashBucket<V, V, SetKeyOfValue, HFun> _hb;
};


/*
void testHB()
{
HashBucket<int, int, KeyOfValue<int>> hb;
hb.insert(21);
hb.insert(48);
hb.insert(36);
hb.insert(43);
hb.insert(5);
hb.insert(61);
hb.insert(78);
hb.insert(15);
hb.insert(6);
hb.insert(23);
hb.insert(51);
hb.insert(52);
hb.insert(53);
hb.insert(54);
hb.insert(55);
hb.insert(56);
}
*/

void testMap2()
{
	UnorderedMap<int, int> mp;
	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(2, 2));
	mp.insert(make_pair(3, 3));
	mp.insert(make_pair(4, 4));
	mp.insert(make_pair(5, 5));
}

void testMap3()
{
	UnorderedMap<int, int> mp;
	mp.insert(make_pair(49, 4));
	mp.insert(make_pair(55, 5));
	mp.insert(make_pair(9, 4));
	mp.insert(make_pair(15, 5));
	mp.insert(make_pair(29, 4));
	mp.insert(make_pair(35, 5));

	//����: ����������Χfor
	UnorderedMap<int, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
	cout << "operator[]:" << endl;
	mp[100] = 100;  //����
	mp[55] = 55;  //�޸�
	for (auto& p : mp)
	{
		cout << p.first << "--->" << p.second << endl;
	}

}

void testMap4()
{
	UnorderedMap<int, int>  mp2;
	mp2[1] = 1;
	mp2.insert(make_pair(1, 1));
	// ���keyΪ���������ͣ������ṩkey�Ĺ�ϣ������ key  ---> int
	UnorderedMap<string, int>  mp;
	mp.insert(make_pair("1", 1));
	mp["2"] = 2;

}

void testPrime()
{
	const int PRIMECOUNT = 28;
	static const size_t primeList[PRIMECOUNT] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};

	static const size_t noPrimeList[PRIMECOUNT] =
	{
		54ul, 98ul, 194ul, 388ul, 768ul,
		1542ul, 3078ul, 6152ul, 12288ul, 24594ul,
		49158ul, 98318ul, 196614ul, 393242ul, 786432ul,
		1572868ul, 3145738ul, 6291468ul, 12582916ul, 25165842ul,
		50331654ul, 100663318ul, 201326610ul, 402653188ul, 805306456ul,
		1610612742ul, 3221225474ul, 4294967281ul
	};
	unordered_set<size_t>  set;
	unordered_map<size_t, size_t>  map;
	unordered_map<size_t, size_t>  map2;
	unordered_set<size_t> array;
	srand(time(nullptr));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		array.insert(rand() + 20000);
	}

	for (int i = 0; i < PRIMECOUNT; ++i)
	{
		set.clear();
		for (const auto& e : array)
		{
			set.insert(e % primeList[i]);  //����λ��
		}
		map[primeList[i]] = set.size();
		set.clear();
		for (const auto& e : array)
		{
			set.insert(e % noPrimeList[i]);  //����λ��
		}
		map2[noPrimeList[i]] = set.size();
	}
	for (const auto& e : array)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "Ԫ�ظ���:" << array.size() << endl;
	cout << "����λ�ã�" << endl;
	for (const auto& p : map)
	{
		cout << p.first << "---->" << p.second << endl;
	}

	cout << "������λ�ã�" << endl;
	for (const auto& p : map2)
	{
		cout << p.first << "---->" << p.second << endl;
	}
}
/*
int main()
{
    //testHB();
    //testMap2();
    //testMap3();
    //testMap4();
    testPrime();
    return 0;
}
*/