#include <stdio.h>
#include <string.h>

void func(char str_arg[100])
{
	printf("\nstr_arg = %s\n", str_arg);
	printf("sizeof(str_arg) = %d\n", sizeof(str_arg));
	printf("strlen(str_arg) = %d\n", strlen(str_arg));
}


int main()
{
	char str[] = "Hello";//注意和char * str = "Hello";是不一样的结果
	printf("str = %s\n", str);
	printf("sizeof(str) = %d\n", sizeof(str));
	printf("strlen(str) = %d\n", strlen(str));

	char * p = str;

	printf("\np = %s\n", p);
	printf("sizeof(p) = %d\n", sizeof(p));//linux 64位系统下，指针的长度是8字节，但是windows 64位系统下，指针的长度是4字节
	printf("strlen(p) = %d\n", strlen(p));

	func(str);

	return 0;
}