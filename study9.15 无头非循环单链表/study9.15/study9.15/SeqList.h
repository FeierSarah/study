#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;
typedef struct SingleListNode
{
	DataType _data;
	struct SingleListNode* _next;
}SingleListNode;

typedef struct SingleList
{
	SingleListNode* _head;
}SingleList;

void SingleListInit(SingleList* sl);
void SingleListDestroy(SingleList* sl);
void SingleListPrint(SingleList* sl);
SingleList* CreatNode(DataType x);

void SingleListPushBack(SingleList* sl, DataType x);
void SingleListPopBack(SingleList* sl);
void SingleListPushFront(SingleList* sl, DataType x);
void SingleListPopFront(SingleList* sl);

void SingleListInsertAfter(SingleListNode* pos, DataType x);
void SingleListEraseAfter(SingleListNode* pos);
