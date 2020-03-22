#include <vector>
#include <utility>
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
	pair<K, V> _kv;
	State _state;
};

template <class K, class V>
class HashTable
{
public:
	typedef Node<K, V> Node;

	HashTable(size_t N = 10)
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
private:
	vector<Node> _table;
	size_t _size;  //���Ԫ�ظ�����
};