#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
/*ʱ�临�Ӷ�*/
long long Fibonacci(size_t N) //�ݹ�ʵ��쳲���������
{
	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
}

long long Fib(size_t N)//ѭ��ʵ��쳲�����
{//���Ǳ߽�����
	int fn1 = 1, fn2 = 0;
	int fn;
	for (int i = 2; i <= N; i++)
	{
		fn = fn1 + fn2;
		fn2 = fn1;
		fn1 = fn;
	}
}
long long Factorial(size_t N) //�׳�
{
	return N < 2 ? N : Factorial(N - 1)*N;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("go on\n");
	Fibonacci(n);//ʱ�临�Ӷ� 2^N
	printf("go on\n");
	Factorial(n);
	return 0;
}
//�ռ临�Ӷ����ڿռ�����ظ����ã�����ֻ��Ҫ�������˼����������ɣ�����쳲��������пռ临�Ӷ�Ϊn��
//ʱ�临�Ӷ�Ϊlog Nʱ�����磺�۰���ң�Ч�ʼ��ߣ�����Щ����ʱ�临�Ӷȿɴﵽ�����������ϣ��