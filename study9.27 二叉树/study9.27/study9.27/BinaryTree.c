#include "BinaryTree.h"

//前序遍历
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
	}
	else
		return NULL;

}

void BinaryTreeDestory(BTNode** root)
{
	BTNode* curRoot = *root;
	if (curRoot)
	{
		BinaryTreeDestory(&curRoot->_left);
		BinaryTreeDestory(&curRoot->_right);
		free(curRoot);
		* root = NULL;
	}
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right) + 1;
}

//叶子节点数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_left);
}

//第K层的节点数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root->_data == x)
		return root;
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;
	return NULL;
}

// 遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
	else
		printf("# ");
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	else
		printf("# ");
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
	else
		printf("# ");
}

// 非递归遍历
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void TestBinaryTree()
{
	int i = 0;
	char a[] = { 'A', 'B', 'D', '#', '#', 'E', '#', 'H', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
	BTNode* root = BinaryTreeCreate(a, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeDestory(&root);
	i = BinaryTreeLeafSize(root);
	i = BinaryTreeLevelKSize(root, 1);
}

int main()
{
	TestBinaryTree();
	return 0;
}