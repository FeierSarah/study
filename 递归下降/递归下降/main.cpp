#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int error;
int num;
char lookahead;
ifstream in("input.txt");
ofstream out("output.txt");
string s;

void match(char ch)
{
	if (ch == lookahead || isdigit(lookahead)) 
	{
		lookahead = s[++num];
	}
	else out << "ch = " << ch << "�� lookahead = " << lookahead << "��ƥ��" << endl;
}

void T();
void G();
void E();
void F();
void H();

void E()
{
	T();
	G();
}

void G()
{
	if (lookahead == '+') 
	{
		match('+');
		T();
		G();
	}
	else if (lookahead == '-') 
	{
		match('-');
		T();
		G();
	}
}

void T()
{
	F();
	H();
}

void H()
{
	if (lookahead == '*') 
	{
		match('*');
		F();
		H();
	}
	else if (lookahead == '/') 
	{
		match('/');
		F();
		H();
	}
}

void F()
{
	if (lookahead == 'i' || isdigit(lookahead)) 
	{
		match('i');
	}
	else if (lookahead == '(') 
	{
		match('(');
		E();
		if (lookahead == ')') 
		{
			match(')');
		}
		else 
		{
			error = 1;//����״̬��Ϊ1
			out << "δƥ�䵽������')'  ";
		}
	}
	else 
	{
		error = 1;//����״̬��Ϊ1
		out << "��" << num + 1 << "���ַ�'" << lookahead << "'ƥ�����  ";
	}
}

int main()
{
	int number = 0;
	while (!in.eof()) 
	{
		out << ++number << " : ";//����
		num = 0;//�����±�ָ���ʼ��Ϊ0
		s = "";//s��ʼ��Ϊ��
		error = 0;//error״̬��ʾ�Ƿ�����˴��󣬳�ʼ��Ϊ0��ʾδ��������
		getline(in, s);//����һ�б��ʽ�����s��
		lookahead = s[0];
		E();
		out;
		if (lookahead == '\0' && !error) 
		{
			out << "���ʽ" << s << "��ȷ" << endl;
		}
		else out << "\n\t���ʽ" << s << "����" << endl;
	}
	return 0;
}