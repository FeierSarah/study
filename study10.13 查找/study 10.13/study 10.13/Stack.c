#include "Stack.h"

void StackInit(Stack* st)
{
	assert(st);
	st->_a = NULL;
	st->_top = st->_capacity = 0;
}

void StackPush(Stack* st, DataType x)
{
	assert(st);
	if (st->_top == st->_capacity)
	{
		size_t newC = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		st->_a = (DataType*)realloc(st->_a, newC * sizeof(st->_top));
		st->_capacity = newC;
	}
	st->_a[st->_top++] = x;
}

void StackPop(Stack* st)
{
	assert(st);
	if (st->_top)
		--st->_top;
}

DataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top - 1];
}

int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 1 : 0;
}

void StackPrint(Stack* st)
{
	assert(st);
	while (StackEmpty(st) != 1)
	{
		printf("%d ", StackTop(st));
		StackPop(st);
	}
	printf("\n");
}

size_t StackSize(Stack* st)
{
	return st->_top;
}

void test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPrint(&s);
	StackEmpty(&s);
}
//int main()
//{
//	test();
//	return 0;
//}