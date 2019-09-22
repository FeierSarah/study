#include "Queue.h"
//╤сап
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
void testQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePrint(&q);
	QueueDestroy(&q);
}

int main()
{
	testQueue();
	return 0;
}