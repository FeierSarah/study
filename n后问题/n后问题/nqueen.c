#include <stdio.h>
#include <string.h>
#include <math.h> 
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INITIAL -10000 //棋盘的初始值
int k;
int a[20];    //一维数组表示棋盘

//对棋盘进行初始化
void init()  
{
	int *p;
	for (p = a; p < a + k; ++p)
	{
		*p = INITIAL;
	}
}

//判断第row行第col列是否可以放置皇后
int valid(int row, int col)    
{
	int i;
	for (i = 0; i < k; ++i)  //对棋盘进行扫描
	{   //判断列冲突与斜线上的冲突
		if (a[i] == col || abs(i - row) == abs(a[i] - col))
			return 0;
	}
	return 1;
}

//打印输出N皇后的一组解
void print()    
{
	int i, j;
	for (i = 0; i < k; ++i)
	{
		for (j = 0; j < k; ++j)
		{
			if (a[i] != j)      //a[i]为初始值
				printf("%c ", '.');
			else                //a[i]表示在第i行的第a[i]列可以放置皇后
				printf("%c ", '#');
		}
		printf("\n");
	}
	for (i = 0; i < k; ++i)
		printf("%d ", a[i]);
	printf("\n\n");
}

//N皇后程序
void queen()      
{
	int n = 0;
	int i = 0, j = 0;
	while (i < k)
	{
		while (j < k)        //对i行的每一列进行探测，看是否可以放置皇后
		{
			if (valid(i, j))      //该位置可以放置皇后
			{
				a[i] = j;        //第i行放置皇后
				j = 0;           //第i行放置皇后以后，需要继续探测下一行的皇后位置，
				//所以此处将j清零，从下一行的第0列开始逐列探测
				break;
			}
			else
			{
				++j;             //继续探测下一列
			}
		}
		if (a[i] == INITIAL)         //第i行没有找到可以放置皇后的位置
		{
			if (i == 0)             //回溯到第一行，仍然无法找到可以放置皇后的位置，
				//则说明已经找到所有的解，程序终止
				break;
			else                    //没有找到可以放置皇后的列，此时就应该回溯
			{
				--i;
				j = a[i] + 1;        //把上一行皇后的位置往后移一列
				a[i] = INITIAL;      //把上一行皇后的位置清除，重新探测
				continue;
			}
		}
		if (i == k - 1)          //最后一行找到了一个皇后位置，
			//说明找到一个结果，打印出来
		{
			printf("answer %d : \n", ++n);
			print();
			//不能在此处结束程序，因为我们要找的是N皇后问题的所有解，
			//此时应该清除该行的皇后，从当前放置皇后列数的下一列继续探测。
			j = a[i] + 1;             //从最后一行放置皇后列数的下一列继续探测
			a[i] = INITIAL;           //清除最后一行的皇后位置
			continue;
		}
		++i;              //继续探测下一行的皇后位置
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
	printf("运行时间：%.1lf us\n", time1);
	return 0;
	system("pause");
	return 0;
}
