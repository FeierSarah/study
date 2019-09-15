#include "SeqList.h"
//��ͷ�����ѭ������

void SingleListInit(SingleList* sl)
{
	//next, data
	assert(sl);
	sl->_head = NULL;
}

void SingleListDestroy(SingleList* sl)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	while (cur)
	{
		SingleListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	sl->_head = NULL;
}

SingleList* CreatNode(DataType x)
{
	SingleListNode* newNode = (SingleListNode*)malloc(sizeof(SingleListNode));
	newNode->_data = x;
	newNode->_next = NULL;
}

void SingleListPushBack(SingleList* sl, DataType x)
{
	assert(sl);
	//������
	if (sl->_head == NULL)
	{
		//sl->_head = (SingleList*)malloc(sizeof(SingleListNode));
		//sl->_head->_data = x;
		//sl->_next->_head = NULL;
		sl->_head = CreatNode(x);
	}
	//��������
	else
	{
		SingleListNode* cur = sl->_head;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		//�ҵ����һ�����
		cur->_next = CreatNode(x);
	}
}

void SingleListPopBack(SingleList* sl)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	SingleListNode* prev = NULL;
	while (cur->_next)
	{
		prev = cur;
		cur = cur->_next;
	}
	free(cur);
	cur = NULL;
	if (prev == NULL)
	{
		//ɾ������ͷ�ڵ�
		sl->_head = NULL;
	}
	else
	{
		prev->_next = NULL; 
	}
}

void SingleListPushFront(SingleList* sl,DataType x)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	SingleListNode* newNode = CreatNode(x);
	newNode->_next = cur;
}

void SingleListPopFront(SingleList* sl)
{
	assert(sl);
	SingleList *next, *cur;
	if (sl->_head == NULL)
		return;
	cur = sl->_head;
	next = sl->_head->_next;
	free(cur);
	cur = NULL;
	sl->_head = next;
}

void SingleListPrint(SingleList* sl)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void SingleListInsertAfter(SingleListNode* pos, DataType x)
{
	assert(pos);
	SingleListNode* newNode = CreatNode(x);
	SingleListNode* next = pos->_next;
	pos->_next = newNode;
	newNode->_next = next;
}

void SingleListEraseAfter(SingleListNode* pos)
{
	assert(pos);
	SingleListNode* next = pos->_next;
	if (pos->_next == NULL)
		return;
	else
	{
		SingleListNode* next2 = next->_next;
		pos->_next = next2;
		free(next);
		next == NULL;
	}
}