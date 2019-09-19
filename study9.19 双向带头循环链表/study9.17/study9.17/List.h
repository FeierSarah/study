#define CRT_SECURE_NO_WARINING 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//双向带头循环链表
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;

void Init(List* lst);
void ListDestroy(List* lst);
ListNode* CreateNode(DataType x);

void ListPushBack(List* lst, DataType x);
void ListPushFront(List* lst, DataType x);
void ListPopBack(List* lst);
void ListPopFront(List* lst);

void ListPrint(List* lst);
void ListDestroy(List* lst);