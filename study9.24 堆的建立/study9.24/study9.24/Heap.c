#include "Heap.h"
//大堆
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	int i;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* n);
	for (i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(hp->_a, n, i);
	}
	hp->_size = hp->_capacity = n;
}
void HeapEmptyInit(Heap* hp)
{
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
//向上调整
void ShiftUp(HPDataType* a, int n, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
//向下调整
void ShiftDown(HPDataType* a, int n, int root)
//最后一个非叶子结点索引：(n-2)/2
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//当前节点是否有孩子
	while (child < n)
	{
		//是否有右孩子，有则进行比较
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		//孩子是否大于父亲，大则进行交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			//更新下一次调整的位置
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//以父亲为根的子树已经是一个大堆，结束调整
			break;
		}
	}
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	if (hp->_a)
	{
		free(hp->_a);
		hp->_a = NULL;
		hp->_capacity = hp->_size = 0;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int newC = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, newC * sizeof(HPDataType));
		hp->_capacity = newC;
	}
	hp->_a[hp->_size] = x;
	++hp->_size;
	ShiftUp(hp->_a, hp->_size, hp->_size - 1);
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
		return 1;
	else
		return 0;
}
void HeapPop(Heap* hp)
{
	assert(hp);
	if (HeapEmpty(hp) == 0)
	{
		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		--hp->_size;
		ShiftDown(hp->_a, hp->_size, 0);
	}
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp && hp->_size);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// 堆排序
void HeapSort(int* a, int n)
{
	//改成小堆
	assert(a);
	int i;
	for (i = (n - 2) / 2; i >= 0 ; i--)
	{
		ShiftDown(a, n , i);
	}
	while (n > 1)
	{
		Swap(&a[0], &a[n - 1]);
		ShiftDown(a, n - 1, 0);
		n--;
	}
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap()
{
	Heap hp;
	HeapEmptyInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 8);
	HeapPush(&hp, 5);
	HeapPush(&hp, 7);
	HeapPush(&hp, 6);
	HeapPush(&hp, 3);
	HeapPush(&hp, 9);
	HeapPush(&hp, 5);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
}

void TestHeapSort()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	//TestHeap();
	TestHeapSort();
	return 0;
}