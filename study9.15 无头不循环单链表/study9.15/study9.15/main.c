#include"SeqList.h"
void test()
{
	SingleList sl;
	SingleListInit(&sl);
	SingleListPushBack(&sl, 1);
	SingleListPushBack(&sl, 2);
	SingleListPushBack(&sl, 3);
	SingleListPushBack(&sl, 4);
	SingleListPushFront(&sl, -1);
	SingleListInsertAfter(sl._head->_next->_next, 33);
	SingleListInsertFront(&sl, 33, 5);
	SingleListPrint(&sl);
	SingleListDestroy(&sl);
}
int main()
{
	test();
	return 0;
}