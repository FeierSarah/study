#include <stdio.h>
#include <string.h>
#include <math.h> 
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INITIAL -10000 //���̵ĳ�ʼֵ
int k;
int a[20];    //һά�����ʾ����

//�����̽��г�ʼ��
void init()  
{
	int *p;
	for (p = a; p < a + k; ++p)
	{
		*p = INITIAL;
	}
}

//�жϵ�row�е�col���Ƿ���Է��ûʺ�
int valid(int row, int col)    
{
	int i;
	for (i = 0; i < k; ++i)  //�����̽���ɨ��
	{   //�ж��г�ͻ��б���ϵĳ�ͻ
		if (a[i] == col || abs(i - row) == abs(a[i] - col))
			return 0;
	}
	return 1;
}

//��ӡ���N�ʺ��һ���
void print()    
{
	int i, j;
	for (i = 0; i < k; ++i)
	{
		for (j = 0; j < k; ++j)
		{
			if (a[i] != j)      //a[i]Ϊ��ʼֵ
				printf("%c ", '.');
			else                //a[i]��ʾ�ڵ�i�еĵ�a[i]�п��Է��ûʺ�
				printf("%c ", '#');
		}
		printf("\n");
	}
	for (i = 0; i < k; ++i)
		printf("%d ", a[i]);
	printf("\n\n");
}

//N�ʺ����
void queen()      
{
	int n = 0;
	int i = 0, j = 0;
	while (i < k)
	{
		while (j < k)        //��i�е�ÿһ�н���̽�⣬���Ƿ���Է��ûʺ�
		{
			if (valid(i, j))      //��λ�ÿ��Է��ûʺ�
			{
				a[i] = j;        //��i�з��ûʺ�
				j = 0;           //��i�з��ûʺ��Ժ���Ҫ����̽����һ�еĻʺ�λ�ã�
				//���Դ˴���j���㣬����һ�еĵ�0�п�ʼ����̽��
				break;
			}
			else
			{
				++j;             //����̽����һ��
			}
		}
		if (a[i] == INITIAL)         //��i��û���ҵ����Է��ûʺ��λ��
		{
			if (i == 0)             //���ݵ���һ�У���Ȼ�޷��ҵ����Է��ûʺ��λ�ã�
				//��˵���Ѿ��ҵ����еĽ⣬������ֹ
				break;
			else                    //û���ҵ����Է��ûʺ���У���ʱ��Ӧ�û���
			{
				--i;
				j = a[i] + 1;        //����һ�лʺ��λ��������һ��
				a[i] = INITIAL;      //����һ�лʺ��λ�����������̽��
				continue;
			}
		}
		if (i == k - 1)          //���һ���ҵ���һ���ʺ�λ�ã�
			//˵���ҵ�һ���������ӡ����
		{
			printf("answer %d : \n", ++n);
			print();
			//�����ڴ˴�����������Ϊ����Ҫ�ҵ���N�ʺ���������н⣬
			//��ʱӦ��������еĻʺ󣬴ӵ�ǰ���ûʺ���������һ�м���̽�⡣
			j = a[i] + 1;             //�����һ�з��ûʺ���������һ�м���̽��
			a[i] = INITIAL;           //������һ�еĻʺ�λ��
			continue;
		}
		++i;              //����̽����һ�еĻʺ�λ��
	}
}

int main(void)
{
	scanf("%d", &k);
	clock_t start1, end1;
	start1 = clock();
	init();
	queen();
	end1 = clock();
	double time1 = ((double)end1 - (double)start1) * 1000;
	printf("����ʱ�䣺%.1lf us\n", time1);
	return 0;
	system("pause");
	return 0;
}
