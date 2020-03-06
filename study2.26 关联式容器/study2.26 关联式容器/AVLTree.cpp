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
	//平衡因子
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

	void RotateR(pNode parent)//右旋
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
		// 根据调整后的结构更新部分节点的平衡因子
		parent->_bf = pSubL->_bf = 0;
	}

	void RotateL(pNode parent)//左旋
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
		// 根据调整后的结构更新部分节点的平衡因子
		parent->_bf = pSubL->_bf = 0;
	}

	void RotateLR(PNode pParent) //左右
	{
		PNode pSubL = pParent->_left;
		PNode pSubLR = pSubL->_right;

		// 旋转之前，保存pSubLR的平衡因子，旋转完成之后，需要根据该平衡因子来调整其他节点的平衡因子
			int bf = pSubLR->_bf;

		// 先进行左单旋
		RotateL(pParent->_pLeft);

		// 再进行右单旋
		RotateR(pParent);
		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}

	void RotateRL(PNode pParent)//右左
	{
		PNode pSubR = pParent->_right;
		PNode pSubRL = pSubR->_left;

		// 旋转之前，保存pSubLR的平衡因子，旋转完成之后，需要根据该平衡因子来调整其他节点的平衡因子
		int bf = pSubRL->_bf;

		// 先进行右单旋
		RotateR(pParent->_left);

		// 再进行左单旋
		RotateL(pParent);
		if (1 == bf)
			pSubR->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}

	bool insert(const T& value)
	{
		// 1. 先按照二叉搜索树的规则将节点插入到AVL树中
		// 如果树为空，直接插入
		if (nullptr == _root)
		{
			_root = new pNode(data);
			return true;
		}
		// 按照二叉搜索树的性质查找data在树中的插入位置
		pNode pCur = _root;
		// 记录pCur的双亲，因为新元素最终插入在pCur双亲左右孩子的位置
		pNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_value)
				pCur = pCur->_left;
			else if (data > pCur->_value)
				pCur = pCur->_right; // 元素已经在树中存在
			else
				return false;
		}
		// 插入元素
		pCur = new pNode(data);
		if (data < pParent->_value)
			pParent->_left = pCur;
		else
			pParent->_right = pCur;
		// 2. 新节点插入后，AVL树的平衡性可能会遭到破坏，此时就需要更新平衡因子，
		// 的平衡性

		/*
		pCur插入后，pParent的平衡因子一定需要调整，在插入之前，pParent
		的平衡因子分为三种情况：-1，0, 1, 分以下两种情况：
		1. 如果pCur插入到pParent的左侧，只需给pParent的平衡因子-1即可
		2. 如果pCur插入到pParent的右侧，只需给pParent的平衡因子+1即可

		此时：pParent的平衡因子可能有三种情况：0，正负1， 正负2
		1. 如果pParent的平衡因子为0，说明插入之前pParent的平衡因子为正负1，插入后被调整成0，此时满
		足
		AVL树的性质，插入成功
		2. 如果pParent的平衡因子为正负1，说明插入前pParent的平衡因子一定为0，插入后被更新成正负1， 此
		时以pParent为根的树的高度增加，需要继续向上更新
		3. 如果pParent的平衡因子为正负2，则pParent的平衡因子违反平衡树的性质，需要对其进行旋转处理
		*/
		while (pParent)
		{
			// 更新双亲的平衡因子
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;
			// 更新后检测双亲的平衡因子
			if (0 == pParent->_bf)
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				// 插入前双亲的平衡因子是0，插入后双亲的平衡因为为1 或者 -1 ，说明以双亲为根的二叉
				// 树的高度增加了一层，因此需要继续向上调整
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else
			{
				// 双亲的平衡因子为正负2，违反了AVL树的平衡性，需要对以pParent
				// 为根的树进行旋转处理
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
		// 空树也是AVL树
		if (nullptr == root) 
			return true;

		// 计算root节点的平衡因子：即root左右子树的高度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		// 如果计算出的平衡因子与root的平衡因子不相等，或者
		// root平衡因子的绝对值超过1，则一定不是AVL树
		if (diff != root->_bf || (diff > 1 || diff < -1))
			return false;
		// pRoot的左和右如果都是AVL树，则该树一定是AVL树
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
