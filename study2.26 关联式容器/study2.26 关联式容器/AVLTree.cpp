#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
struct AVLNode
{
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;
	T _value;
	//ƽ������
	int _bf;

	AVLNode(const T& value = T())
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _bf(0)
	{}
};

template<class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;

	void RotateR(pNode parent)//����
	{
		PNode pSubL = parent->_left;
		PNode pSubLR = pSubL->_right;
		parent->_left = pSubLR;
		
		if (pSubLR)
			pSubLR->_parent = parent;
		pSubL->_right = parent;
		PNode pParent = parent->_parent;
		parent->_parent = pSubL;
		pSubL->_parent = pParent;
		if (NULL == pParent)
		{
			_root = pSubL;
			pSubL->_parent = NULL;
		}
		else
		{
			if (pParent->_left == parent)
				pParent->_left = pSubL;
			else
				pParent->_right = pSubL;
		}
		// ���ݵ�����Ľṹ���²��ֽڵ��ƽ������
		parent->_bf = pSubL->_bf = 0;
	}

	void RotateL(pNode parent)//����
	{
		PNode pSubR = parent->_right;
		PNode pSubRL = pSubR->_left;
		parent->_right = pSubRL;

		if (pSubRL)
			pSubRL->_parent = parent;
		pSubR->_left = parent;
		PNode pParent = parent->_parent;
		parent->_parent = pSubR;
		pSubR->_parent = pParent;
		if (NULL == pParent)
		{
			_root = pSubR;
			pSubR->_parent = NULL;
		}
		else
		{
			if (pParent->_right == parent)
				pParent->_right = pSubR;
			else
				pParent->_left = pSubR;
		}
		// ���ݵ�����Ľṹ���²��ֽڵ��ƽ������
		parent->_bf = pSubL->_bf = 0;
	}

	void RotateLR(PNode pParent) //����
	{
		PNode pSubL = pParent->_left;
		PNode pSubLR = pSubL->_right;

		// ��ת֮ǰ������pSubLR��ƽ�����ӣ���ת���֮����Ҫ���ݸ�ƽ�����������������ڵ��ƽ������
			int bf = pSubLR->_bf;

		// �Ƚ�������
		RotateL(pParent->_pLeft);

		// �ٽ����ҵ���
		RotateR(pParent);
		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}

	void RotateRL(PNode pParent)//����
	{
		PNode pSubR = pParent->_right;
		PNode pSubRL = pSubR->_left;

		// ��ת֮ǰ������pSubLR��ƽ�����ӣ���ת���֮����Ҫ���ݸ�ƽ�����������������ڵ��ƽ������
		int bf = pSubRL->_bf;

		// �Ƚ����ҵ���
		RotateR(pParent->_left);

		// �ٽ�������
		RotateL(pParent);
		if (1 == bf)
			pSubR->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}

	bool insert(const T& value)
	{
		// 1. �Ȱ��ն����������Ĺ��򽫽ڵ���뵽AVL����
		// �����Ϊ�գ�ֱ�Ӳ���
		if (nullptr == _root)
		{
			_root = new pNode(data);
			return true;
		}
		// ���ն��������������ʲ���data�����еĲ���λ��
		pNode pCur = _root;
		// ��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
		pNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_value)
				pCur = pCur->_left;
			else if (data > pCur->_value)
				pCur = pCur->_right; // Ԫ���Ѿ������д���
			else
				return false;
		}
		// ����Ԫ��
		pCur = new pNode(data);
		if (data < pParent->_value)
			pParent->_left = pCur;
		else
			pParent->_right = pCur;
		// 2. �½ڵ�����AVL����ƽ���Կ��ܻ��⵽�ƻ�����ʱ����Ҫ����ƽ�����ӣ�
		// ��ƽ����

		/*
		pCur�����pParent��ƽ������һ����Ҫ�������ڲ���֮ǰ��pParent
		��ƽ�����ӷ�Ϊ���������-1��0, 1, ���������������
		1. ���pCur���뵽pParent����ֻ࣬���pParent��ƽ������-1����
		2. ���pCur���뵽pParent���Ҳֻ࣬���pParent��ƽ������+1����

		��ʱ��pParent��ƽ�����ӿ��������������0������1�� ����2
		1. ���pParent��ƽ������Ϊ0��˵������֮ǰpParent��ƽ������Ϊ����1������󱻵�����0����ʱ��
		��
		AVL�������ʣ�����ɹ�
		2. ���pParent��ƽ������Ϊ����1��˵������ǰpParent��ƽ������һ��Ϊ0������󱻸��³�����1�� ��
		ʱ��pParentΪ�������ĸ߶����ӣ���Ҫ�������ϸ���
		3. ���pParent��ƽ������Ϊ����2����pParent��ƽ������Υ��ƽ���������ʣ���Ҫ���������ת����
		*/
		while (pParent)
		{
			// ����˫�׵�ƽ������
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;
			// ���º���˫�׵�ƽ������
			if (0 == pParent->_bf)
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				// ����ǰ˫�׵�ƽ��������0�������˫�׵�ƽ����ΪΪ1 ���� -1 ��˵����˫��Ϊ���Ķ���
				// ���ĸ߶�������һ�㣬�����Ҫ�������ϵ���
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else
			{
				// ˫�׵�ƽ������Ϊ����2��Υ����AVL����ƽ���ԣ���Ҫ����pParent
				// Ϊ������������ת����
				if (2 == pParent->_bf && pCur->_bf == 1)
				{
					RotateL(pParent);
				}
				else if (2 == pParent->_bf && pCur->_bf == -1)
				{
					RotateRL(pParent);
				}
				else if (-2 == pParent->_bf && pCur->_bf == 1)
				{
					RotateLR(pParent);
				}
				else 
				{
					RotateR(pParent);
				}
			}
		}
		return true;
	}

	void _InOrder(pNode root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_value << " ";
			_InOrder(root->_right);
		}
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int _Height(PNode root)
	{
		if (root == nullptr)
			return 0;
		int left = _Height(root->_left);
		int right = _Height(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	bool _IsBalanceTree(pNode root)
	{
		// ����Ҳ��AVL��
		if (nullptr == root) 
			return true;

		// ����root�ڵ��ƽ�����ӣ���root���������ĸ߶Ȳ�
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		// ����������ƽ��������root��ƽ�����Ӳ���ȣ�����
		// rootƽ�����ӵľ���ֵ����1����һ������AVL��
		if (diff != root->_bf || (diff > 1 || diff < -1))
			return false;
		// pRoot��������������AVL���������һ����AVL��
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}

private:
	pNode _root = nullptr;
};

void test()
{
	AVLTree<int>* avl = new AVLTree<int>();
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		avl->insert(arr[i]);
	}
}

int main()
{
	test();
	return 0;
}
