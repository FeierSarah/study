#include"SeqList.h"
void test()
{
	SingleList *sl;
	SingleListInit(&sl);
	SingleListPushBack(&sl, 1);
	SingleListPushBack(&sl, 2);
	SingleListPushBack(&sl, 3);
	SingleListPushBack(&sl, 4);
	SingleListPushFront(&sl, -1);
	SingleListPrint(&sl);
	SingleListDestroy(&sl);
}
int main()
{
	test();
	return 0;
}