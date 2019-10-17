#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include"Stack.h"
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
//时间:O(N^1.3 - N^2)
//空间：O(1)
//稳定性：不稳定
void ShellSort(int* a, int n)
{
	assert(a);
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
	assert(a);
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
//时间：O(N * log(N))
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
//时间：O(N^2)
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

/*快速排序*/
//时间：O(N * logN)
//空间：O(logN) 空间可以复用，最大的递归调用链
//稳定性：不稳定
//三数取中
int getMid(int* a, int left, int right)
{
	assert(a);
	int mid = left + (right - left) / 2;
	while (left <right)
	{
		if (a[mid] > a[left])
		{
			if (a[mid] < a[right])
				return mid;
			else
			{
				if (a[left] > a[right])
					return left;
				else
					return right;
			}
		}
		else
		{
			if (a[left] < a[right])
				return left;
			else
			{
				if (a[mid] > a[right])
					return mid;
				else
					return right;
			}
		}
	}
}

int PartSort(int* a, int left, int right)
{
	assert(a);
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int key = a[left];
	int start = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
			--right;
		while (left < right && a[right] <= key)
			++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[start], &a[left]);
	return left;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	assert(a);
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
			--right;
		a[left] = a[right];
		while (left < right && a[right] <= key)
			++left;
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	assert(a);
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int key = a[left];
	int prev = left; //最后一个小于key的位置
	int cur = left + 1;//下一个小于key的位置
	//如果下一个小于key的位置与上一个小于key的位置不连续
	//说明中间有大于key的值，进行交换，大的往后移动，小的往前移动
	while (left <= right)
	{
		if (a[cur] < key && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		++cur;
	}
	Swap(&a[left], &a[prev]);
	return left;
}

//递归
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;
	else if (right - left + 1 < 5)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int mid = PartSort(a, left, right);
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
}

//非递归
//调用栈 后进先出
void QuickSort2(int* a, int left, int right)
{
	assert(a);
	Stack st;
	StackInit(&st);
	if (left < right)
	{
		StackPush(&st, right);
		StackPush(&st, left);
	}
	while (StackEmpty(&st) == 0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		//划分当前区间
		int mid = PartSort(a, begin, end);
		//划分左右子区间
		if (begin < mid - 1)
		{
			StackPush(&st, mid - 1);
			StackPush(&st, begin);
		}
		if (mid + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, mid + 1);
		}
	}
}

/*合并牌序*/
//时间：O(N * logN)
//空间：O(N + logN) ~ O(N) 
//稳定性：稳定
void _MergeSort(int* a, int left, int right, int* tmp)
{
	assert(a);
	//区间只剩一个元素，无需分解和归并
	if (left >= right)
		return;
	//分解
	int mid = (right - left) / 2 + left;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//合并
	int begin1 = left, end1 = mid, begin2 = mid + 1, end2 = right;
	int tmpindex = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[tmpindex++] = a[begin1++];
		}
		else
		{
			tmp[tmpindex++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[tmpindex++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[tmpindex++] = a[begin2++];
	}
}
void MergeSort(int* a, int n)
{
	assert(a);
	int *tmp = (int*)malloc(n * sizeof(int));
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void ArrayPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*计数排序*/
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	int i;
	for (i = 1; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;
	int* CountArr = (int*)malloc(sizeof(int)* range);
	memset(CountArr, 0, sizeof(int)* range);
	//计数
	for (i = 0; i < n; ++i)
	{
		CountArr[a[i] - min]++;
	}
	//排序
	int index = 0;
	for (i = 0; i < range; ++i)
	{
		while (CountArr[i]--)
		{
			a[index++] = i + min;
		}
	}
}

void testSort()
{
	int a[] = { 10, 2, 3, 8, 9, 7, 6, 1, 5, 4 };
	ArrayPrint(a, sizeof(a) / sizeof(int));

	InsertSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));

	ShellSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));

	SelectSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));

	HeapSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));

	BubbleSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));

	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	ArrayPrint(a, sizeof(a) / sizeof(int));

	QuickSort2(a, 0, sizeof(a) / sizeof(int) - 1);
	ArrayPrint(a, sizeof(a) / sizeof(int));

	MergeSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
}

int main()
{
	testSort();
	return 0;
}