#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);
void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);

DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);

void QueuePrint(Queue* q);