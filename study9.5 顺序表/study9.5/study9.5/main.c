#include"sqlist.h"
void TestSeqList()
{
	struct SeqList s;
	SeqListInit(&s);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPrint(&s);
	SeqListDestory(&s);
}
int main()
{
	TestSeqList();
	return 0;
}