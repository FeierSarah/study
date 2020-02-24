#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
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

typedef struct MyStack
{
	Queue q1;
	Queue q2;
}MyStack;
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}
void QueuePush(Queue* q, DataType x)
{
	assert(q);
	QueueNode* newNode = (Queue*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;
	if (q->_front == NULL)
	{
		q->_front = q->_rear = newNode;
	}
	else
	{
		q->_rear->_next = newNode;
		q->_rear = q->_rear->_next;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;
	}
}

DataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_front)
		return q->_front->_data;
	return -1;
}
DataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_rear)
		return q->_rear->_data;
	return -1;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}

int QueueSize(Queue* q)
{
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		++n;
		cur = cur->_next;
	}
	return n;
}

void QueuePrint(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

MyStack* mystackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}

void myStackPush(MyStack* obj, int x)
{
	assert(obj);
	if (QueueEmpty(&obj->q1) == 0)
		QueuePush(&obj->q1, x);
	else
		QueuePush(&obj->q2, x);
}

int myStackPop(MyStack* obj)
{
	assert(obj);
	Queue* emptyQ, *fullQ;
	emptyQ = &obj->q2;
	fullQ = &obj->q1;
	int front;
	if (QueueEmpty(&obj->q1) == 0)
	{
		while (QueueSize(fullQ) > 1)
		{
			QueuePush(emptyQ, QueueFront(fullQ));
			QueuePop(fullQ);
		}
		front = QueueFront(fullQ);
		QueuePush(emptyQ, QueueFront(fullQ));
		QueuePop(fullQ);
	}
	return front;
}

bool myStackFree(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}
void myStackFree2(MyStack* obj)
{
	if (!myStackFree(&obj))
	{
		QueueDestroy(&obj->q1);
		QueueDestroy(&obj->q2);
	}
	free(obj);
}
int main()
{
	MyStack obj;
	myStackPush(&obj, 1);
	myStackPush(&obj, 2);
	myStackPush(&obj, 3);
	printf("%d\n", myStackPop(&obj));

	return 0;
}