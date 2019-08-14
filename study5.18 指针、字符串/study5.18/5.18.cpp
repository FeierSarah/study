#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*指针初了解*/
//void mymalloc(char **p)
//{
//	static char a[100];
//	*p = a;
//}
//int main()
//{
//	char *str = NULL;
//	mymalloc(&str);
//	strcpy(str, "hello world");
//	puts(str);
//	return 0;
//}

//int main()
//{
//	int a = 6;
//	int *p = &a;
//	printf("%p\n", p);
//	printf("%p\n", p + 1);
//	printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (short*)p + 1);
//	printf("%p\n", (double*)p + 1);
//	return 0;
//}

//char *c[] = { "enter", "new", "point", "first" };
//char **cp[] = { c + 3, c + 2, c + 1, c };
//char ***cpp = cp;
//
//int main()
//{
//	printf("%s\n", **++cpp);
//	printf("%s\n", *--*++cpp+3);
//	printf("%s\n", *cpp[-2]+3);//**(cpp-2)+3
//	printf("%s\n", cpp[-1][-1]+1);//*(*(cpp-1)-1)+1
//	return 0;
//}

//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//注意逗号表达式
//	//int a[3][2]={1,3,5,0,0,0,};
//	int *p = a[1];
//	printf("%d\n", p[0]);
//	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	int *p1 = (int*)(&a + 1);
//	int *p2 = (int*)((int)a + 1);
//	printf("%x,%x\n", p1[-1], *p2);
//	return 0;
//}
////00000001 00000000 00000000 00000000
////00000010 00000000 00000000 00000000

//int main()
//{
//	char *str[] = { "welcome", "to", "fortemedia", "nanjing" };
//	char **p = str + 1;
//	str[0] = (*p++) + 2;
//	str[1] = *(p+1);
//	str[2] =p[1] + 3;
//	str[3] = p[0]+(str[2]-str[1]);
//	printf("%s\n", str[0]);
//	printf("%s\n", str[1]);
//	printf("%s\n", str[2]);
//	printf("%s\n", str[3]);
//	return 0;
//}

//int main()
//{
//	char a[10] = { 'a', 'b', 'c', 'd', 'e' };
//	char b[] = { 'a', 'b', 'c', 'd', 'e' };
//	char c[] = "123456";
//	char str[] = "abc\012abc";
//	char str1[] = "abc\0abc";
//
//}

/*字符串*/
//int main()
//{
//	char a[20] = "12345678";
//	char b[20] = "qwer";
//	strcpy(a, b);
//	printf("%s\n", a);
//	return 0;
//}

int main()
{
	char str[] = "i,am.a student";
	char sep[] = ",. ";
	char *tok = NULL;
	for (tok = strtok(str, sep); tok != NULL; tok = strtok(NULL, sep))
	{
		puts(tok);
	}
	return 0;
}

