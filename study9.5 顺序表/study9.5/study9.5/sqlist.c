#include"sqlist.h"
void SeqListInit(SeqList* sl)
{
	assert(sl);
	sl->_array = NULL;
	sl->_capacity = 0;
	sl->_size = 0;
}

void SeqListDestory(SeqList* sl)
{
	assert(sl);
	if (sl->_array)
	{
		free(sl->_array);
		sl->_array = NULL;
		sl->_capacity = sl->_size = 0;
	}
}

void SeqListPrint(SeqList* sl)
{
	assert(sl);
	for (size_t i = 0; i < sl->_size; ++i)
	{
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SeqList* sl)
{
	if (sl->_size == sl->_capacity)
	{
		if (sl->_capacity!=0)
			sl->_capacity *= 2;
		else
			sl->_capacity = 5 * sizeof(DataType);
		sl->_array = (DataType *)realloc(sl->_array, sl->_capacity * sizeof(DataType));
	}
}

void SeqListPushBack(SeqList* sl, DataType x)
{
	assert(sl);
	//检查容量
	SeqListCheckCapacity(sl);
	size_t end = sl->_size;
	sl->_array[end] = x;
	++sl->_size;
}

void SeqListPopBack(SeqList* sl)
{
	assert(sl&& sl->_size > 0);
	//检查容量
	SeqListCheckCapacity(sl);
	--sl->_size;
}

void SeqListPushFront(SeqList*sl, DataType x)
{
	assert(sl);
	//检查容量
	SeqListCheckCapacity(sl);
	//移动元素
	size_t end = sl->_size;
	while (end >0)
	{
		sl->_array[end] = sl->_array[end - 1];
		--end;//防止越界
	}
	//插入
	sl->_array[0] = x;
	++sl->_size;
}

void SeqListPopFront(SeqList*sl)
{
	assert(sl && sl->_size > 0);//加入判空步骤
	size_t start = 0;
	while (start < sl->_size - 1)//注意size所在位置没有元素，访问不能越界
	{
		sl->_array[start] = sl->_array[start+1];
		++start;
	}
	--sl->_size;
}

void SeqListInsert(SeqList*sl,DataType x,size_t pos)
{
	assert(sl&&pos<=sl->_size);
	SeqListCheckCapacity(sl);
	size_t res = sl->_size;
	while (res > pos)
	{
		sl->_array[res] = sl->_array[res - 1];
		--res;
	}
	sl->_array[pos] = x;
	++sl->_size;
}

void SeqListErase(SeqList*sl,size_t pos)
{
	assert(sl&&pos <sl->_size);
	SeqListCheckCapacity(sl);
	size_t res = pos + 1;
	while (res<sl->_size)
	{
		sl->_array[res-1] = sl->_array[res];
		++pos;
	}
	--sl->_size;
}

size_t SeqListFind(SeqList*sl, DataType x)
{
	assert(sl);
	for (size_t i = 0; i < sl->_size; ++i)
	{
		if (sl->_array == x)
			return i;
	}
	return -1;
}

size_t SeqListSize(SeqList*sl)
{
	assert(sl);
	return sl->_size;
}

DataType SeqListAt(SeqList*sl, size_t pos)
{
	assert(sl&& pos < sl->_size);
	return sl->_array[pos];
}

void SeqListRemoveAll(SeqList*sl, DataType x)
{
	assert(sl);
	size_t index = 0;
	for (size_t i = 0; i < sl->_size; ++i)
	{
		if (sl->_array[i] != x)
		{
			sl->_array[index] = sl->_array[i];
			index++;
		}
	}
	sl->_size = index;
}

void SeqListBubbleSort(SeqList*sl)
{
	assert(sl);
	size_t end = sl->_size;
	while (end > 1)
	{
		//单趟排序
		for (size_t i = 1; i < end; ++i)
		{
			if (sl->_array[i - 1]>sl->_array[i])
			{
				DataType tmp = sl->_array[i - 1];
				sl->_array[i - 1] = sl->_array[1];
				sl->_array[i] = tmp;
			}
		}
		--end;
	}
}

int SeqListBinaryFind(SeqList*sl, DataType x)
{
	assert(sl);
	size_t start = 0;
	size_t end = sl->_size - 1;
	while (start <= end)
	{
		size_t mid = start + (end - start) / 2;
		if (sl->_array[mid] == x)
			return mid;
		else if (sl->_array[mid] > x)
			mid = end;
		else
			mid = start;
	}
	return -1;
}