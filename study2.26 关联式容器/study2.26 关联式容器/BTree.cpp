#include <iostream>
using namespace std;
template <class T>
struct BSTNode
{
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;

	BSTNode(const T& data = T())
		: _pLeft(nullptr), _pRight(nullptr), _data(data)
	{}
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	//BSTree() : _pRoot(nullptr)
	//{}
	//

	//~BSTree();
	// ���ݶ��������������ʲ��ң��ҵ�ֵΪdata�Ľڵ��ڶ����������е�λ��
	PNode Find(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return _pRoot;
		}
		PNode cur = _pRoot;
		while (cur)
		{
			if (cur->_data == data)
				return cur;
			else if (cur->_data < data)
				cur = cur->_pRight;
			else
				cur = cur->_pLeft;
		}
		return cur;

	}

	bool Insert(const T& data)
	{
		// �����Ϊ�գ�ֱ�Ӳ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// ���ն��������������ʲ���data�����еĲ���λ��
		PNode pCur = _pRoot;
		// ��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight; // Ԫ���Ѿ������д���
			else
				return false;
		}
		// ����Ԫ��
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
			return true;
	}
	bool Erase(const T& data)
	{
		// �����Ϊ�գ�ɾ��ʧ��
		if (nullptr == _pRoot)
			return false;
		// ������data�����е�λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		// data���ڶ����������У��޷�ɾ��
		if (nullptr == pCur)
			return false;
		// �������������ɾ����ͬѧ���Լ���ͼ�������
		if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ�����ӻ�������Ϊ��---��ֱ��ɾ��
		}
		else if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ���Һ���---��ֱ��ɾ��
		}
		else
		{
			// ��ǰ�ڵ����Һ��Ӷ����ڣ�ֱ��ɾ������ɾ��������������������һ�������㣬���磺
			// �����������е����ڵ㣬�������������Ҳ�Ľڵ㣬������������������С�Ľڵ㣬������
			������С�Ľڵ�
				// ����ڵ��ҵ��󣬽�����ڵ��е�ֵ������ɾ���ڵ㣬ת����ɾ������ڵ�
		}
		return true;
	}
	void InOrder(PNode root)
	{
	
	}
private:
	PNode _pRoot;
};

void testBSTree()
{
	BSTree<int> bst;
	bst.Insert(1);
	bst.Insert(2);
	bst.Insert(3);
	bst.Insert(4);
	bst.Insert(5);
	bst.Insert(6);
	bst.Insert(7);
	bst.Insert(8);
	bst.Insert(9);
}