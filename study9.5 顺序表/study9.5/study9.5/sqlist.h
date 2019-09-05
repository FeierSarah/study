#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#ifndef _sqlist_H_
#define _sqlist_H_
typedef int DataType;

typedef struct SeqList
{
	DataType *_array;
	int _size;
	int _capacity;
}SeqList;

void SeqListInit(SeqList* sl);
void SeqListDestory(SeqList* sl);
void SeqListCheckCapacity(SeqList* sl);
void SeqListPushFront(SeqList* sl, DataType x);
void SeqListPopFront(SeqList* sl);
void SeqListPushBack(SeqList* sl, DataType x);
void SeqListPopBack(SeqList* sl);
void SeqListInsert(SeqList* sl,size_t* pos, DataType x);
void SeqListErase(SeqList* sl, size_t* pos);

size_t SeqListFind(SeqList*sl, DataType x);
size_t SeqListSize(SeqList*sl);
DataType SeqListAt(SeqList*sl, size_t pos);
void SeqListRemoveAll(SeqList*sl, DataType x);

int SeqListBinaryFind(SeqList*sl,DataType x);
void SeqListBubbleSort(SeqList*sl);

void SeqListPrint(SeqList* sl);
void TestSeqList();

#endif