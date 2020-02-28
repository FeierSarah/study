#include <iostream>
using namespace std;

template<class T>
struct AVLNode
{
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;
	T _value;
	//Æ½ºâÒò×Ó
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

	void RotateR(pNode parent)
	{
		pNode subl = parent->_left;
		pNode subr = parent->_right;

		subl->right = parent;
		parent->_left = subr;
		if (subr)
			subr->_parent = 
	}
private:

};
