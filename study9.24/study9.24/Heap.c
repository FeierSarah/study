#include "Heap.h"
//���
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
void HeapInit(Heap* hp);
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void ShiftDown(HPDataType* a, int n, int root)
//���һ����Ҷ�ӽ��������(n-2)/2
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//��ǰ�ڵ��Ƿ��к���
	while (child < n)
	{
		//�Ƿ����Һ��ӣ�������бȽ�
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		//�����Ƿ���ڸ��ף�������н���
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			//������һ�ε�����λ��
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//�Ը���Ϊ���������Ѿ���һ����ѣ���������
			break;
		}
	}
}
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
// ������
void HeapSort(int* a, int n);
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);
}
int main()
{
	TestHeap();
	return 0;
}