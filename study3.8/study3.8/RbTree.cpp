#include <utility>
#include <iostream>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};
//�ڵ���<K,V>����
template <class K, class V>
struct RBNode
{
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;
	RBNode<K, V>* _parent;
	pair<K, V> _value;
	//��ɫ
	COLOR _color;

	RBNode(const pair<K, V>& value = pair<K, V>())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _color(RED)
	{}
};

template <class K, class V>
class RBTree
{
public:
	typedef RBNode<K, V> Node;
	typedef Node* pNode;

	RBTree()
	{
		//�����յĺ����
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}

	bool insert(const pair<K, V>& value)
	{
		//�������Ĳ���
		if (_header->_parent == nullptr)
		{
			//�������������ڵ�
			pNode root = new Node(value);
			root->_color = BLACK;
			root->_parent = _header;
			_header->_parent = root;

			_header->_left = root;
			_header->_right = root;
			return true;
		}
		//�Ӹ���ʼ����
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			//����keyֵȷ��λ��, key�����ظ�
			if (cur->_value.first == value.first)
				return false;
			else if (cur->_value.first > value.first)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(value);
		if (parent->_value.first > cur->_value.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//�����͸���(��ɫ��: �����ĺ�ɫʱ��Ҫ����
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			// cur, parent, gfather, uncle
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				//uncle ������Ϊ��
				if (uncle && uncle->_color == RED)
				{
					//�޸���ɫ
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//�������ϸ���
					cur = gfather;
				}
				else{
					//�������˫���ĳ����������Ƚ���һ�ε�����ʹ����ɵ����ĳ���
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//����
					RotateR(gfather);
					//�޸���ɫ
					parent->_color = BLACK;
					gfather->_color = RED;
					//ֹͣ����
					break;
				}
			}
			else
			{
				pNode uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					//�޸���ɫ
					uncle->_color = parent->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else{
					//�ж��Ƿ���˫���ĳ���
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
		//������ɫʼ���Ǻڵ�
		_header->_color = BLACK;
		//���� _header->_left, _header->_right
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
			//���¸��ڵ�
			_header->_parent = subL;
			subL->_parent = nullptr;
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
			subR->_parent = nullptr;
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

private:
	pNode _header;
};

void testRBTree()
{
	RBTree<int, int> rbt;
	rbt.insert(make_pair(1, 1));
	rbt.insert(make_pair(10, 1));
	rbt.insert(make_pair(-1, 1));
	rbt.insert(make_pair(-2, 1));
	rbt.insert(make_pair(100, 1));
	rbt.insert(make_pair(19, 1));
	rbt.insert(make_pair(21, 1));
	rbt.inOrder();
}

int main()
{
	testRBTree();
	return 0;
}