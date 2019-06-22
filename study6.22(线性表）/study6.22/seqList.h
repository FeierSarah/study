//Ë³Ðò±í
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
#endif