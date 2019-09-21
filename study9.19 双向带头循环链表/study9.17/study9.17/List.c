#include "List.h"
void Init(List* lst)
{
	assert(lst);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	lst->_head = head;
	lst->_head->_next = lst->_head;
	lst->_head->_prev = lst->_head;
	lst->_head->_data = NULL;
}

void ListDestroy(List* lst)
{
	assert(lst);
	ListNode* cur = lst->_head->_next;
	while (cur != lst->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(lst->_head);
}

ListNode* CreateListNode(DataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	return newNode;
}

void ListPushBack(List* lst, DataType x)
{
	assert(lst);
	ListNode* tail;
	ListNode* newNode = CreateListNode(x);
	tail = lst->_head->_prev;

	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = lst->_head;
	lst->_head->_prev = newNode;
}

void ListPushFront(List* lst, DataType x)
{
	assert(lst);
	ListNode* next;
	ListNode* newNode = CreateListNode(x);
	next = lst->_head->_next;

	next->_prev = newNode;
	newNode->_next = next;
	newNode->_prev = lst->_head;
	lst->_head->_next = newNode;
}

void ListPopBack(List* lst)
{
	assert(lst);
	ListNode* prev, *tail;
	if (lst->_head == lst->_head->_next)
		return;
	tail = lst->_head->_prev;
	prev = lst->_head->_next;

	lst->_head->_prev = tail->_prev;
	tail->_prev->_next = lst->_head;
	free(tail);
	tail = NULL;
}

void ListPopFront(List* lst)
{
	assert(lst);
	ListNode* next, *nextnext;
	if (lst->_head == lst->_head->_next)
		return;

	next = lst->_head->_next;
	nextnext = lst->_head->_next->_next;

	lst->_head->_next = nextnext;
	nextnext->_prev = lst->_head;
	free(next);
	next = NULL;
}

void ListInsert(List* lst, ListNode* pos, DataType x)
{
	assert(pos && lst);
	ListNode* prev = pos->_prev;
	ListNode* newNode = CreateListNode(x);
	newNode->_next = pos;
	newNode->_prev = prev;
	pos->_prev = newNode;
	prev->_next = newNode;
}

void ListErase(List* lst, ListNode* pos)
{
	assert(lst && pos);
	ListNode* prev, *next;
	if (lst->_head == pos)
		return;
	prev = pos->_prev;
	next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

void ListPrint(List* lst)
{
	assert(lst);
	ListNode* cur = lst->_head->_next;
	while (cur != lst->_head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}