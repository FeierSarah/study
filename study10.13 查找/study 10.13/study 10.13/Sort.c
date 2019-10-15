#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include"Stack.h"
/*��������*/
//ʱ�䣺O(N^2)
//�ռ䣺O(1)
//�ȶ��ԣ��ȶ�
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

/*ϣ������*/
//ʱ��:O(n^1.3 - n^2)
//�ռ䣺O(1)
//�ȶ��ԣ����ȶ�
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

/*ѡ������*/
//ʱ�䣺O(N^2)
//�ռ䣺O(1)
//�ȶ��ԣ��ȶ�
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	//ÿ��ѡһ�����ĺ���С�ģ��ŵ���Ӧ��λ��
	while (begin < end)
	{
		int i, max, min;
		max = min = begin;
		for (i = begin; i <= end; ++i)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] >= a[min])//if (a[i] > a[min]) �޸��������ȶ�
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

/*������*/
//ʱ�䣺O(n * log(n))
//�ռ䣺O(1)
//�ȶ��ԣ�
void ShiftDown(int* a, int n, int root)
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

/*ð������*/
//ʱ�䣺O(n^2)
//�ռ䣺O(1)
//�ȶ��ԣ��ȶ�
void BubbleSort(int* a, int n)
{
	assert(a);
	for (int i = n; i > 0; i--)
	{
		int flag = 0;
		for (int j = 0; j < i - 1; j++)
		{
			//���һ�ε�ð�ݹ����Ƿ���Ԫ�ؽ���
			flag = 1;
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
		if (flag == 0)//���û�з���Ԫ�ؽ�������ǰ����
			break;
	}
}

/*��������*/
//ʱ�䣺N * logN
//�ռ䣺logN �ռ���Ը��ã����ĵݹ������
//�ȶ��ԣ�
//����ȡ��
int getMid(int* a, int left, int right)
{
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
	int mid = getMid(&a, left, right);
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

//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = getMid(&a, left, right);
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

//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int mid = getMid(&a, left, right);
	Swap(&a[mid], &a[left]);

	int key = a[left];
	int prev = left; //���һ��С��key��λ��
	int cur = left + 1;//��һ��С��key��λ��
	//�����һ��С��key��λ������һ��С��key��λ�ò�����
	//˵���м��д���key��ֵ�����н�������������ƶ���С����ǰ�ƶ�
	while (left <= right)
	{
		if (a[cur] < key && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		++cur;
	}
	Swap(&a[left], &a[prev]);
	return left;
}

//�ݹ�
void QuickSort(int* a, int left, int right)
{
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

//�ǵݹ�
//����ջ ����ȳ�
void QuickSort2(int* a, int left, int right)
{
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
		//���ֵ�ǰ����
		int mid = PartSort(a, begin, end);
		//��������������
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

	QuickSort(&a, 0, sizeof(a) / sizeof(int) - 1);
	ArrayPrint(&a, sizeof(a) / sizeof(int));

	QuickSort2(&a, 0, sizeof(a) / sizeof(int)-1);
	ArrayPrint(&a, sizeof(a) / sizeof(int));
}

int main()
{
	testSort();
	return 0;
}