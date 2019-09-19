#include "List.h"
void test()
{
	List lst;
	Init(&lst);

	ListPushBack(&lst, 1);
	ListPushFront(&lst, 2);
	ListPushBack(&lst, 3);
	ListPushFront(&lst, 4);
	ListPushBack(&lst, 5);
	ListPushFront(&lst, 6);

	ListPrint(&lst);
	ListDestroy(&lst);
}

int main()
{
	void test();
	return 0;
}