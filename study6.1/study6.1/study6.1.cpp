#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>//stdlib.h
#include<limits.h>
#include<stdlib.h>
#define N 100
/*��̬�ڴ����*/
//int main()
//{
//	int arr[10];
//	int*p = NULL;
//	p = arr;
//	return 0;
//}

//Ұָ��
//1.����ָ��δ����
//2.free���δ��ָ�븳��

//malloc
//����������ڴ�����һ���������õĿռ䣬������ָ�����ռ��ָ�롣
//������ٳɹ����򷵻�һ��ָ�򿪱ٺÿռ��ָ�롣
//�������ʧ�ܣ��򷵻�һ��NULLָ�룬���malloc�ķ���ֵһ��Ҫ����顣
//����ֵ�������� void* ������malloc��������֪�����ٿռ�����ͣ�������ʹ�õ�ʱ��ʹ�����Լ���������
//������� size Ϊ0��malloc����Ϊ�Ǳ�׼��δ����ģ�ȡ���ڱ�������

//free
//free���������ͷŶ�̬���ٵ��ڴ档
//������� ptr ָ��Ŀռ䲻�Ƕ�̬���ٵģ���free��������Ϊ��δ����ġ�
//������� ptr ��NULLָ�룬����ʲô�¶�������

//calloc
//�����Ĺ�����Ϊ num ����СΪ size ��Ԫ�ؿ���һ��ռ䣬���Ұѿռ��ÿ���ֽڳ�ʼ��Ϊ0��
//�뺯�� malloc ������ֻ���� calloc ���ڷ��ص�ַ֮ǰ������Ŀռ��ÿ���ֽڳ�ʼ��Ϊȫ0��

//realloc
//realloc�����ĳ����ö�̬�ڴ���������
//��ʱ�����Ƿ��ֹ�ȥ����Ŀռ�̫С�ˣ���ʱ�������ֻ��������Ŀռ�����ˣ���Ϊ�˺����ʱ���ڴ棬
//����һ������ڴ�Ĵ�С�����ĵ������� realloc �����Ϳ��������Զ�̬�����ڴ��С�ĵ�����


//�ڴ�й©
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

/*����һ�����������һλ��ʾ������֮��˳���������*/
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
//	//p = (int*)realloc(p, 6 * sizeof(int));//���ܿ��ٲ��ɹ������������ڴ汻ռ�ã��ͻ��������ڴ�λ�ÿ������Ͽռ�һ�������ڴ�
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

//break���˳�����ѭ����,continue(��������ѭ����,goto��return��exit
//�����˳���ǰ��ѭ������������

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

//C99 �У��ṹ�е����һ��Ԫ��������δ֪��С�����飬��ͽ������������须��Ա��
//typedef struct st_type
//{
//	int i;
//	int a[0];//���������Ա
//}type_a;

//����������ص㣺
//�ṹ�е����������Աǰ���������һ��������Ա��
//sizeof ���ص����ֽṹ��С����������������ڴ档
//�������������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ
//���������Ԥ�ڴ�С��

//ʹ������������ָ���ڽṹ����ͬ����
//int i = 0;
//type_a *p = (type_a*)malloc(sizeof(type_a)+100 * sizeof(int));
////ҵ����
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
////ҵ����
//for (i = 0; i<100; i++)
//{
//	p->p_a[i] = i;
//}
////�ͷſռ�
//free(p->p_a);
//p->p_a = NULL;
//free(p);
//p = NULL;