#include <iostream>
#include <utility>
using namespace std;
enum COLOR
{
	BLACK,
	RED
};
//节点只关心V
template <class V>
struct RBNode
{
	RBNode<V>* _left;
	RBNode<V>* _right;
	RBNode<V>* _parent;
	V _value;
	//颜色
	COLOR _color;

	RBNode(const V& value = V())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _color(RED)
	{}
};

template <class V>
struct RBIterator
{
	//封装节点，实现迭代器的功能，类似于list迭代器的实现
	typedef RBNode<V> Node;
	typedef Node* pNode;
	typedef RBIterator<V> Self;
	pNode _node;

	RBIterator(pNode node)
		:_node(node)
	{
	}

	V& operator*()
	{
		return _node->_value;
	}

	V* operator->()
	{
		return &_node->_value;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		//如果存在右节点， 移动到右子树的最左节点
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)
			{
				_node = _node->_left;
			}
		}
		else
		{
			//向上回溯，找到它的孩子不是它的右的节点
			pNode parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			//特殊情况下有问题：
			_node = parent;
		}

		return *this;
	}

};

template <class K, class V, class KeyOfValue>
class RBTree
{
public:
	typedef RBNode<V> Node;
	typedef Node* pNode;
	typedef RBIterator<V> iterator;

	iterator begin()
	{
		return iterator(_header->_left);
	}

	iterator end()
	{
		return iterator(_header);
	}

	RBTree()
	{
		//构建空的红黑树
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}

	bool insert(const V& value)
	{
		//搜索树的插入
		if (_header->_parent == nullptr)
		{
			//空树，创建根节点
			pNode root = new Node(value);
			root->_color = BLACK;
			root->_parent = _header;
			_header->_parent = root;

			_header->_left = root;
			_header->_right = root;
			return true;
		}
		//从根开始搜索
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		//通过仿函数对象获取V对应的K
		KeyOfValue kov;
		while (cur)
		{
			parent = cur;
			//对于不同的V,需要获取V对应的K
			if (kov(cur->_value) == kov(value))
				return false;
			else if (kov(cur->_value) > kov(value))
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(value);
		if (kov(parent->_value) > kov(cur->_value))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//调整和更新(颜色）: 连续的红色时需要调整
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			// cur, parent, gfather, uncle
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				//uncle 存在且为红
				if (uncle && uncle->_color == RED)
				{
					//修改颜色
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//继续向上更新
					cur = gfather;
				}
				else{
					//如果存在双旋的场景，可以先进行一次单旋，使它变成单旋的场景
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//右旋
					RotateR(gfather);
					//修改颜色
					parent->_color = BLACK;
					gfather->_color = RED;
					//停止调整
					break;
				}
			}
			else
			{
				pNode uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					//修改颜色
					uncle->_color = parent->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else{
					//判断是否有双旋的场景
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}

		}
		//根的颜色始终是黑的: _header->_parent
		_header->_parent->_color = BLACK;
		//更新 _header->_left, _header->_right
		_header->_left = leftMost();
		_header->_right = rightMost();
		return true;
	}

	pNode leftMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_left != nullptr)
		{
			cur = cur->_left;
		}
		return cur;
	}

	pNode rightMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_right != nullptr)
		{
			cur = cur->_right;
		}
		return cur;
	}

	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		// 1
		subL->_right = parent;
		// 2
		parent->_left = subLR;
		// 3
		if (subLR)
			subLR->_parent = parent;
		// 4,  5
		if (parent != _header->_parent)
		{
			// subL <---> parent->parent
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subL;
			else
				gParent->_right = subL;
			subL->_parent = gParent;
		}
		else
		{
			//更新根节点
			_header->_parent = subL;
			//subL->_parent = nullptr;
			subL->_parent = _header;

		}
		// 6
		parent->_parent = subL;

	}

	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent != _header->_parent){
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subR;
			else
				gParent->_right = subR;
			subR->_parent = gParent;
		}
		else
		{
			_header->_parent = subR;
			//根的父节点不是nullptr
			//subR->_parent = nullptr;
			subR->_parent = _header;

		}
		parent->_parent = subR;
	}

	void inOrder()
	{
		_inOrder(_header->_parent);
		cout << endl;
	}

	void _inOrder(pNode root)
	{
		if (root){
			_inOrder(root->_left);
			cout << "< " << root->_value.first << "--->" << root->_value.second << "> ";
			_inOrder(root->_right);
		}
	}

	bool isRBTree()
	{
		pNode root = _header->_parent;
		if (root == nullptr)
			return true;
		if (root->_color == RED)
		{
			cout << "根节点必须是黑色的!" << endl;
			return false;
		}
		//每条路径黑色个数相同
		//可以任意遍历一条路径:
		//此处获取最右路径黑色个数
		pNode cur = root;
		int blackCount = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
				++blackCount;
			cur = cur->_right;
		}
		int k = 0;
		return _isRBTree(root, k, blackCount);
	}

	bool _isRBTree(pNode root, int curBlackCount, int totalBlackCount)
	{
		//每条路径上黑色个数相同
		//一条路径走完
		if (root == nullptr)
		{
			if (curBlackCount != totalBlackCount)
			{
				cout << "每条路径黑色节点个数不同" << endl;
				return false;
			}
			return true;
		}

		if (root->_color == BLACK)
			++curBlackCount;

		//没有红色连续的
		pNode parent = root->_parent;
		if (parent->_color == RED && root->_color == RED)
		{
			cout << "有红色连续的节点" << endl;
			return false;
		}

		return _isRBTree(root->_left, curBlackCount, totalBlackCount)
			&& _isRBTree(root->_right, curBlackCount, totalBlackCount);
	}

private:
	pNode _header;
};

template <class K, class V>
class MyMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename RBTree<K, pair<K, V>, MapKeyOfValue>::iterator iterator;

	iterator begin()
	{
		return _rb.begin();
	}

	iterator end()
	{
		return _rb.end();
	}

	bool insert(const pair<K, V>& data)
	{
		return _rb.insert(data);
	}
	/*
	void mapInorder()
	{
	_rb.inOrder();
	}
	*/
private:
	RBTree<K, pair<K, V>, MapKeyOfValue> _rb;
};

template <class K>
class MySet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	bool insert(const K& value)
	{
		return _rb.insert(value);
	}

private:
	RBTree<K, K, SetKeyOfValue> _rb;
};



void testMap()
{
	MyMap<int, int> mp;
	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(2, 2));
	mp.insert(make_pair(3, 3));
	mp.insert(make_pair(4, 4));
	//mp.mapInorder();
	MyMap<int, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << "---" << it->second << endl;
		it->first = 10;
		it->second = 100;
		++it;
	}

	it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << "---" << it->second << endl;
		it->first = 10;
		it->second = 100;
		++it;
	}
}

void testSet()
{
	MySet<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
}

int main()
{
	testMap();
	//testSet();
	return 0;
}