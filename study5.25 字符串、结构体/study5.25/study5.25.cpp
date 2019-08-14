#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define N 10
#include<stddef.h>
/*字符串*/
//int main1()
//{
//	char str[] = "you are,a.student";
//	char str1[] = "i am. a.student";
//	char sep[] = " ,.";
//	char *tok = NULL;
//	char maxlen[20]=
//	for(tok = strtok(str, sep); tok != NULL; tok = strtok(NULL, sep))
//	{
//		//puts(tok);
//if ()
//	}
//	return 0;
//}
//int main2(){
//	char str1[] = "abcedf";
//	char str2[] = "abcasdfads";
//	int n = strncmp(str1+ 1, str2 + 1, 3);
//	printf("%d\n", n);
//	return 0;
//}
////int __cdecl strncmp（//strncmp源代码
////(
////const char *first,
////const char *last,
////size_t      count
////)
////{
////	size_t x = 0;
////
////	if (!count)
////	{
////		return 0;
////	}
////
////	/*
////	* This explicit guard needed to deal correctly with boundary
////	* cases: strings shorter than 4 bytes and strings longer than
////	* UINT_MAX-4 bytes .
////	*/
////	if (count >= 4)
////	{
////		/* unroll by four */
////		for (; x < count - 4; x += 4)
////		{
////			first += 4;
////			last += 4;
////
////			if (*(first - 4) == 0 || *(first - 4) != *(last - 4))
////			{
////				return(*(unsigned char *)(first - 4) - *(unsigned char *)(last - 4));
////			}
////
////			if (*(first - 3) == 0 || *(first - 3) != *(last - 3))
////			{
////				return(*(unsigned char *)(first - 3) - *(unsigned char *)(last - 3));
////			}
////
////			if (*(first - 2) == 0 || *(first - 2) != *(last - 2))
////			{
////				return(*(unsigned char *)(first - 2) - *(unsigned char *)(last - 2));
////			}
////
////			if (*(first - 1) == 0 || *(first - 1) != *(last - 1))
////			{
////				return(*(unsigned char *)(first - 1) - *(unsigned char *)(last - 1));
////			}
////		}
////	}
////
////	/* residual loop */
////	for (; x < count; x++)
////	{
////		if (*first == 0 || *first != *last)
////		{
////			return(*(unsigned char *)first - *(unsigned char *)last);
////		}
////		first += 1;
////		last += 1;
////	}
////
////	return 0;
////}
//
//int main3(){
//	char str1[20] = "abcdef";
//	char str2[20] = "1234";
//	strncpy(str1, str2, 6);
//	puts(str1);
//	return 0;
//}
////char * __cdecl strncpy(//strncpy源代码
////	char * dest,
////	const char * source,
////	size_t count
////	)
////{
////	char *start = dest;
////
////	while (count && (*dest++ = *source++))    /* copy string */
////		count--;
////
////	if (count)                              /* pad out with zeroes */
////	while (--count)
////		*dest++ = '\0';
////
////	return(start);
////}
////
////
////int main(){
////	char str1[20] = "abcdef";//内存错误（scanf未加&；指针指向不明；数组越界）
////	char str2[] = "1234";
////	strncat(str1, str2, 3);
////	puts(str1);
////	return 0;
////}
////char * __cdecl strncat(//strncat源代码
////	char * front,
////	const char * back,
////	size_t count
////	)
////{
////	char *start = front;
////
////	while (*front++)
////		;
////	front--;
////
////	while (count--)
////	if (!(*front++ = *back++))
////		return(start);
////
////	*front = '\0';
////	return(start);
////}
////
////int main(){
////	char str1[20] = "abcbcdefgggggg";
////	char str2[] = "bcdefk";
////	char *p = NULL;
////	if(p=strstr(str1, str2))
////	puts(p);
////	return 0;
////}
////
////#include<assert.h>
////char *my_strstr(const char*str1, const char*str2)//KMP算法
////{
////	char*p = (char*)NULL;
////	char*s1 = (char*)str1;
////	char*s2 = (char*)str2;
////	assert(str1 != NULL);
////	if (str2 == NULL)
////	{
////		return NULL;
////	}
////	while (*p)
////	{
////		s1 = p;
////		s2 = (char*)str2;
////		while (*s1&&*s2&&*s1 == *s2)
////		{
////			s1++;
////			s2++;
////		}
////		if (*s2 == '\0')
////			return p;
////		p++;
////	}
////
////}
////int main(){
////	char str1[20] = "abcbcdefgggggg";
////	char str2[] = "bcdefk";
////	char *p = NULL;
////	if (p = my_strstr(str1, str2))
////		puts(p);
////	//while (*p)
////	//{
////	//	s1 = p;
////	//}
////	return 0;
////}
//
//#include<assert.h>
//void *my_memcpy(void *dest, const void *src, size_t count)
//{
//	void *ret = (char*)dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (count)
//	{
//		*(char*)dest - *(char*)src;
//		src = (char*)src + 1;
//		dest = (char*)dest + 1;
//		count--;
//	}
//	return ret;
//}
//int main5(){
//	char str1[20] = "1234567890";
//	char str2[20];// = "123";
//	gets(str2);
//	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int arr2[10] = { 9, 8, 0 };
//	my_memcpy(str1, str2, 6);
//	puts(str1);
//	return 0;
//	}
//
//void * my_memmove(void * dst, const void * src, size_t count)
//{
//	void * ret = dst;
//	if (dst <= src || (char *)dst >= ((char *)src + count)) {
//		/* Non-Overlapping Buffers copy from lower addresses to higher addresses */
//		while (count--) {
//			*(char *)dst = *(char *)src;
//			dst = (char *)dst + 1;
//			src = (char *)src + 1;
//		}
//	}
//	else {
//		/* Overlapping Buffers* copy from higher addresses to lower addresses */
//		dst = (char *)dst + count - 1;
//		src = (char *)src + count - 1;
//		while (count--) {
//			*(char *)dst = *(char *)src;
//			dst = (char *)dst - 1;
//			src = (char *)src - 1;
//		}
//	}
//	return(ret);
//}
//
///*结构体*/
//  //自身对齐数
//  //默认对齐数   VS:8   linux gcc:4
//  //单个选取自身和默认对齐数的最小对齐
//  //所有选取各个单个中最大的对齐数
//struct student
//{
//	int num;
//	char name[20];
//	//int age;
//	char sex;
//};
//struct data
//{          //内存对齐
//	int a; //4
//	char b; //1 4
//	char c; //1
//	//char b;  //1  4
//	//int a;  //4
//	//char c;  //1  4
//};
//struct s1
//{
//	char a[5];
//	int n;
//};
//
//int main6()
//{
//	struct student a;
//	printf("%d\n", sizeof(struct student));//28
//	printf("%d\n", sizeof(struct data));//8  12
//	printf("%d\n", sizeof(struct s1));//12
//	return 0;
//}
//typedef struct
//{
//	int data;
//	Node* next;
//}Node;
//内存对齐规律：
//1. 第一个成员在与结构体变量偏移量为0的地址处。
//2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
//3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是
//所有最大对齐数（含嵌套结构体的对齐数）的整数倍
//struct s1
//{
//	char c1;
//	int c2;
//	char c3;
//};
//struct s2
//{
//	char c1;
//	char c2;
//	int c3;
//};
//struct s3
//{
//	struct s2 a;
//	int b;
//	//double c;
//	char c[15];
//};
//int main7()
//{
//	/*printf("%d\n", offsetof(s1, c1));
//	printf("%d\n", offsetof(s1, c2));
//	printf("%d\n", offsetof(s1, c3));
//	printf("%d\n", offsetof(s2, c1));
//	printf("%d\n", offsetof(s2, c2));
//	printf("%d\n", offsetof(s2, c3));*/
//	printf("%d\n", sizeof(struct s3));
//	return 0;
//}

//typedef struct student
//{
//	int num;
//	char name[20];
//	char sex;
//}STU;
//int main8()
//{
//	STU a = { 1, "lily", 'f' };
//	STU b;
//	STU c;
//	STU *p = &a;
//	//b = { 2, "sarah", 'm' };(原则上不允许）
//	b.num = 2;
//	strcpy(b.name, "sarah");
//	b.sex = 'm';
//	printf("%d,%s,%c\n", a.num, a.name, a.sex);
//	c = a;
//	printf("%d,%s,%c\n", c.num, c.name, c.sex);
//	printf("%d,%s,%c\n", (*p).num, p->name, p->sex);
//	return 0;
//}
//
//#pragma pack(2)
//struct data
//{
//	int a;
//	char c;
//};
//#pragma pack()
//int main()
//{
//	printf("%d\n", sizeof(struct data));
//	return 0;
//}

//struct A
//{
//	char e;
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//int main(){
//	printf("%d\n", sizeof(struct A));
//	return 0;
//}

//struct S
//{
//	int a : 3;
//	int b : 4;
//	int c : 5;
//	int d : 4;
//};
//int main(){
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}

//enum week{mon=1,tues,wed,thur,fri,sat,sun};//枚举
//enum data{a=5,b,c,d,e=1,f};
//enum color{red,green,blue};
//int main(){
//	enum week w;
//	w = thur;
//	printf("%d\n", w);
//	return;
//}

//union data
//{
//	int a;
//	char b;
//	double c;
//};
//int main()
//{
//	union data aa;
//	printf("%d\n", sizeof(union data));
//	printf("%p\n", &(aa.a));
//	printf("%p\n", &(aa.b));
//	printf("%p\n", &(aa.c));
//	return 0;
//}

//union data
//{
//	int i;
//	char c;
//};
//int main()
//{
//	union data d;
//	d.i = 0x11223344;
//	d.c = 0x55;
//	printf("%x\n", d.i);
//	printf("%x\n", d.c);
//	return 0;
//}

//判断当前计算机的大小端存储
int sys_check()
{
	int a = 1;
	return *((char*)&a);
}
int main()
{
	int n = sys_check();
	if (n == 1)
		printf("小端");
	else
		printf("大端");
	return 0;
}