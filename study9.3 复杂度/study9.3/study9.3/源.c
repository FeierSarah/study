#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
/*时间复杂度*/
long long Fibonacci(size_t N) //递归实现斐波那契数列
{
	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
}

long long Fib(size_t N)//循环实现斐波那契
{//考虑边界问题
	int fn1 = 1, fn2 = 0;
	int fn;
	for (int i = 2; i <= N; i++)
	{
		fn = fn1 + fn2;
		fn2 = fn1;
		fn1 = fn;
	}
}
long long Factorial(size_t N) //阶乘
{
	return N < 2 ? N : Factorial(N - 1)*N;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("go on\n");
	Fibonacci(n);//时间复杂度 2^N
	printf("go on\n");
	Factorial(n);
	return 0;
}
//空间复杂度由于空间可以重复利用，所以只需要看调用了几个参数即可，例如斐波那契数列空间复杂度为n，
//时间复杂度为log N时（例如：折半查找）效率极高，但有些程序时间复杂度可达到常数，例如哈希表