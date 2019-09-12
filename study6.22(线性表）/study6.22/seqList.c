#include"seqList.h"

void SeqListInit(SeqList*psl, size_t capacity)
{
	psl->capacity = capacity;
	psl->array = (SLDataType*)malloc(capacity*sizeof(SeqList));//malloc内存不够会失败，先判空
	assert(psl->array);
	psl->size = 0;
}

void SeqListDestory(SeqList*psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size= 0;
		psl->capacity = 0;
	}
}

void CheckCapacity(SeqList*psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl,psl->capacity*sizeof(SeqList));
	}
	else if (!psl->capacity)
	{
		psl->capacity += 20 * sizeof(SLDataType*);
		psl->array = (SLDataType*)realloc(psl, psl->capacity*sizeof(SeqList));
	}
}

void SeqListPushBack(SeqList*psl,SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList*psl)
{
	assert(psl||psl->size);
	CheckCapacity(psl);
	psl->size--;
}

void SeqListPushFront(SeqList*psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	int i;
	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

void SeqListPopFront(SeqList*psl)
{
	assert(psl);
	psl->size--;
}
void SeqListPrint(SeqList*psl)
{
	assert(psl);
	int i;
	for (i = 0; i < (int) psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar(('\n'));
}

int SeqListFind(SeqList*psl, SLDataType x)
{
	assert(psl);
	int i;
	for (i = 0; i <(int)psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList*psl, size_t pos, SLDataType x)
{
	assert(psl||pos<=psl->size);
	CheckCapacity(psl);
	int i;
	for (i = (int)psl->size - 1; i >= (int)pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList*psl, size_t pos)
{
	assert(psl || pos < psl->size);
	psl->size--;
	int i;
	for (i = pos; i < (int)psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

void SeqListRemove(SeqList*psl, SLDataType x)
{
	assert(psl);
	int pos = SeqListFind(psl, x);
	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}

void SeqListModify(SeqList*psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);
	psl->array[pos] = x;
}

