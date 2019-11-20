#include <iostream>
#include <string>
#include <stdio.h>
#include <malloc.h>
using namespace std;
#define M 10 
#define N 5 

typedef struct node{
	char name[M];
	struct node *next;  //指向下一个进程 
	int prio;   //优先级 
	int time;//需要多少时间 
	char state; //进程的当前状态 
}PCB;

typedef struct list
{
	node* head;
}PCBL;

PCB *finish, *ready, *tail, *run;

void Init(PCBL* list)
{
	list->head = NULL;
}

void Destroy(PCBL* list)
{
	node* cur = list->head;
	while (cur)
	{
		node* next = cur->next;
		free(cur);
		cur = next;
	}
	list->head = NULL;
}

node* CreatNode(char name[M], int x, int y, char state)
{
	node* newNode = (node*)malloc(sizeof(node));
	strcpy(name, newNode->name);
	newNode->next = NULL;
	newNode->prio = x;   //优先级 
	newNode->time = y;//需要多少时间 
	newNode->state = state; //进程的当前状态 
}

void Push(PCBL* pcbs,char name[M], int x, int y, char state)
{
	if (pcbs->head == NULL)
	{
		pcbs->head = CreatNode(name, x, y, state);
	}
	//遍历链表
	else
	{
		node* cur = pcbs->head;
		while (cur->next)
		{
			cur = cur->next;
		}
		//找到最后一个结点
		cur->next = CreatNode(name, x, y, state);
	}
}

/*打印一个信息*/
void Print1(int select, PCB *q)
{
	if (select == 1)
		printf("\t\t    %-10s%-10d%-10d%c\n", q->name, q->time, q->prio, q->state);
	else if (select == 2)
		printf("\t\t    %-10s%-10d%-10d%-10d%c\n", q->name, q->time, q->prio, q->state);
	else if (select == 3)
		printf("\t\t    %-10s%-10d%-10d%-10d%-10d%c\n", q->name, q->time, q->state);
}

/*将所有的进程打印出来，按运行，就绪，完成顺序打印*/
void Print2(int select)
{
	PCB *p;
	if (run != NULL)
		Print1(select, run);
	p = ready;
	while (p != NULL)
	{
		Print1(select, p);
		p = p->next;
	}
	p = finish;
	while (p != NULL)
	{
		Print1(select, p);
		p = p->next;
	}
}

int menu()
{
	int choose;
	cin >> choose;
	PCBL l;
	Init(&l);
	while (1)
	{
		printf("1.初始化\n");
		printf("2.打印\n");
		printf("3.运行\n");
		printf("0.退出系统\n\n");
		if (choose == 1)
		{
			char name[M][N];
			int n, time[N], prio[N];
			char state[N];
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> name[M][N]>>time[i] >> prio[i] >> state[i];
			}
		}
		else if (choose == 2)
		{
			
		}
		else if (choose == 3)
		{
			
		}
		else if (choose == 0)
		{
			Destroy(&l);
			return;
		}
		else
			cout << "命令无效，请重新输入" << endl;
	}

}

int main()
{
	menu();
	return 0;
}
