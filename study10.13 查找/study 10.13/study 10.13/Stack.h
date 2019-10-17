#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	size_t _top;
	size_t _capacity;
}Stack;
void StackInit(Stack* st);
void StackPush(Stack* st, DataType x);
void StackPop(Stack* st);
DataType StackTop(Stack* st);
int StackEmpty(Stack* st);
void StackPrint(Stack* st);