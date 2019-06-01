#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>//stdlib.h
#include<limits.h>
#include<stdlib.h>
#define N 100
/*动态内存管理*/
//int main()
//{
//	int arr[10];
//	int*p = NULL;
//	p = arr;
//	return 0;
//}

//野指针
//1.声明指针未赋空
//2.free完成未给指针赋空

//malloc
//这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针。
//如果开辟成功，则返回一个指向开辟好空间的指针。
//如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
//返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定。
//如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器。

//free
//free函数用来释放动态开辟的内存。
//如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。
//如果参数 ptr 是NULL指针，则函数什么事都不做。

//calloc
//函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。
//与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0。

//realloc
//realloc函数的出现让动态内存管理更加灵活。
//有时会我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，那为了合理的时候内存，
//我们一定会对内存的大小做灵活的调整。那 realloc 函数就可以做到对动态开辟内存大小的调整。


//内存泄漏
//int main()
//{
//	int*p = NULL;
//	p = (int*)malloc(sizeof(int));
//	*p = 8;
//	printf("%d\n", *p);
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int*p = NULL;
//	int i;
//	int *q;
//	p = (int*)malloc(INT_MAX);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	p = (int*)malloc(sizeof(int)*N);
//	q = p;
//	for (i = 0; i < N; i++)
//	{
//		*(p + i) = i;
//	}
//	for (; p < q + N;p++)
//	for (i = 0; i < N; i++)
//	//for ()
//	{
//		printf("%d", p[i]);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

/*输入一组数，输出第一位显示个数，之后顺序输出各数*/
//int main()
//{
//	char *p = (char*)malloc(sizeof(char)* 10);
//	strcpy(p, "123456");
//	printf(p);
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	char str[20];
//	char*p = (char*)malloc(100);
//	char str[20] = "";
//	char*p = (char*)malloc(100);
//	memset(p, 0, 100);
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	char*p = NULL;
//	p = (char*)calloc(10, sizeof(char));
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int*p = NULL;
//	int*q = NULL;
//	p = (int*)malloc(4);
//	//	q = (int*)malloc(20);
//	*p = 6;
//	printf("%d\n", *p);
//	//p = (int*)realloc(p, 6 * sizeof(int));//可能开辟不成功，后面所需内存被占用，就会在其他内存位置开辟新老空间一共所需内存
//	q = (int*)realloc(p, 6 * sizeof(int));
//	if (q != NULL)
//		p = q;
//	int i;
//	for (i = 1; i < 6; i++)
//	{
//		printf("%d", *(p + i));
//	}	
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int *p = NULL;
//	int num;
//	int n = 0;
//	int size = N;
//	p = (int*)malloc(sizeof(int)*(size + 1));
//	while (1 == scanf("%d", &num))
//	{
//		n++;
//		if (n > size)
//		{
//			size = size + N;
//			int *q = NULL;
//			q = (int*)realloc(p, sizeof(int)*(size + 1));
//			if (q != NULL)
//				p = q;
//		}
//		p[n] = num;
//	}
//	p[0] = n;
//	p = (int*)realloc(p, sizeof(int)*(n + 1));
//	int i;
//	for (i = 0; i < n+1;i++)
//		printf("%d ", p[i]);
//	printf("\n");
//	return 0;
//	free(p);
//	p = NULL;
//	return 0;
//}

//break（退出本次循环）,continue(结束本次循环）,goto，return，exit
//四种退出，前两循环，后两函数

//void GetMemory(char **p)
//{
//	*p = (char *)malloc(100);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}

//C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。
//typedef struct st_type
//{
//	int i;
//	int a[0];//柔性数组成员
//}type_a;

//柔性数组的特点：
//结构中的柔性数组成员前面必须至少一个其他成员。
//sizeof 返回的这种结构大小不包括柔性数组的内存。
//包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应
//柔性数组的预期大小。

//使用柔性数组与指针于结构体有同有异
//int i = 0;
//type_a *p = (type_a*)malloc(sizeof(type_a)+100 * sizeof(int));
////业务处理
//p->i = 100;
//for (i = 0; i<100; i++)
//{
//	p->a[i] = i;
//}
//free(p);

//typedef struct st_type
//{
//	int i;
//	int *p_a;
//}type_a;
//type_a *p = malloc(sizeof(type_a));
//p->i = 100;
//p->p_a = (int *)malloc(p->i*sizeof(int));
////业务处理
//for (i = 0; i<100; i++)
//{
//	p->p_a[i] = i;
//}
////释放空间
//free(p->p_a);
//p->p_a = NULL;
//free(p);
//p = NULL;