//Ë³Ðò±í
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#ifndef  _SEQLIST_H_
#define  _SEQLIST_H_

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType*array;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList*psl, size_t capacity);
void SeqListDestory(SeqList*psl);
void CheckCapacity(SeqList*psl);
void SeqListDestory(SeqList*psl);

void SeqListPushBack(SeqList*psl, SLDataType x);
void SeqListPopBack(SeqList*psl);
void SeqListPushFront(SeqList*psl, SLDataType x);
void SeqListPopFront(SeqList*psl);
void SeqListPrint(SeqList*psl);
int SeqListFind(SeqList*psl, SLDataType x);
void SeqListInsert(SeqList*psl, size_t pos, SLDataType x);
void SeqListErase(SeqList*psl, size_t pos);
void SeqListRemove(SeqList*psl, SLDataType x);
void SeqListModify(SeqList*psl, size_t pos, SLDataType x);
#endif