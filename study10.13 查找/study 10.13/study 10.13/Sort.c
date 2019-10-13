#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

/*插入排序*/
//时间：O(N^2)
//空间：O(1)
//稳定性：稳定
void InsertSort(int* a, int n)
{
	assert(a);
	int i;
	for (i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

/*希尔排序*/
//时间:O(n^1.3 - n^2)
//空间：O(1)
//稳定性：不稳定
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*选择排序*/
//时间：O(N^2)
//空间：O(1)
//稳定性：稳定
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	//每次选一个最大的和最小的，放到相应的位置
	while (begin < end)
	{
		int i, max, min;
		max = min = begin;
		for (i = begin; i <= end; ++i)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] >= a[min])//if (a[i] > a[min]) 修改条件后不稳定
				max = i;
		}
		Swap(&a[begin], &a[min]);
		if (max == begin)
			max = min;
		Swap(&a[end], &a[max]);
		begin++;
		--end;
	}
}

/*堆排序*/
//时间：O(n * log(n))
//空间：O(1)
//稳定性：
void ShiftDown(int* a, int n, int root)
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

void HeapSort(int* a, int n)
{
	assert(a);
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		ShiftDown(a, n, i);
	}
	while (n > 1)
	{
		Swap(&a[0], &a[n - 1]);
		ShiftDown(a, n - 1, 0);
		n--;
	}
}

/*冒泡排序*/
//时间：O(n^2)
//空间：O(1)
//稳定性：稳定
void BubbleSort(int* a, int n)
{
	assert(a);
	for (int i = n; i > 0; i--)
	{
		int flag = 0;
		for (int j = 0; j < i - 1; j++)
		{
			//标记一次的冒泡过程是否发生元素交换
			flag = 1;
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
		if (flag == 0)//如果没有发生元素交换，提前结束
			break;
	}
}

void ArrayPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void testSort()
{
	int a[] = { 10, 2, 3, 8, 9, 7, 6, 1, 5, 4 };
	ArrayPrint(&a, sizeof(a) / sizeof(int));

	InsertSort(&a, sizeof(a) / sizeof(int));
	ArrayPrint(&a, sizeof(a) / sizeof(int));

	ShellSort(&a, sizeof(a) / sizeof(int));
	ArrayPrint(&a, sizeof(a) / sizeof(int));

	SelectSort(&a, sizeof(a) / sizeof(int));
	ArrayPrint(&a, sizeof(a) / sizeof(int));

	HeapSort(&a, sizeof(a) / sizeof(int));
	ArrayPrint(&a, sizeof(a) / sizeof(int));

	BubbleSort(&a, sizeof(a) / sizeof(int));
	ArrayPrint(&a, sizeof(a) / sizeof(int));
}

int main()
{
	testSort();
	return 0;
}