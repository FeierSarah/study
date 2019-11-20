#include <iostream>
#include <string>
#include <stdio.h>
#include <malloc.h>
using namespace std;
#define M 10 
#define N 5 

typedef struct node{
	char name[M];
	struct node *next;  //ָ����һ������ 
	int prio;   //���ȼ� 
	int time;//��Ҫ����ʱ�� 
	char state; //���̵ĵ�ǰ״̬ 
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
	newNode->prio = x;   //���ȼ� 
	newNode->time = y;//��Ҫ����ʱ�� 
	newNode->state = state; //���̵ĵ�ǰ״̬ 
}

void Push(PCBL* pcbs,char name[M], int x, int y, char state)
{
	if (pcbs->head == NULL)
	{
		pcbs->head = CreatNode(name, x, y, state);
	}
	//��������
	else
	{
		node* cur = pcbs->head;
		while (cur->next)
		{
			cur = cur->next;
		}
		//�ҵ����һ�����
		cur->next = CreatNode(name, x, y, state);
	}
}

/*��ӡһ����Ϣ*/
void Print1(int select, PCB *q)
{
	if (select == 1)
		printf("\t\t    %-10s%-10d%-10d%c\n", q->name, q->time, q->prio, q->state);
	else if (select == 2)
		printf("\t\t    %-10s%-10d%-10d%-10d%c\n", q->name, q->time, q->prio, q->state);
	else if (select == 3)
		printf("\t\t    %-10s%-10d%-10d%-10d%-10d%c\n", q->name, q->time, q->state);
}

/*�����еĽ��̴�ӡ�����������У����������˳���ӡ*/
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
		printf("1.��ʼ��\n");
		printf("2.��ӡ\n");
		printf("3.����\n");
		printf("0.�˳�ϵͳ\n\n");
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
			cout << "������Ч������������" << endl;
	}

}

int main()
{
	menu();
	return 0;
}
