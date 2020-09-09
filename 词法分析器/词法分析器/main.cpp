#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0])) //����Ԫ�ظ���
using namespace std;

int lookup(string s)//����s�Ƿ��ڱ����ֱ�keyword��
{
	string keyword[] = { "void", "main", "short", "long", "int", "double", "float", "while", "if", "else", "for", "break", "return" };//keyword��
	for (int i = 0; i < ARRAY_SIZE(keyword); i++) 
	{
		if (s.compare(keyword[i]) == 0)return 1;//�Ǳ����֣�����1
	}
	return 0;//���Ǳ����֣�����0
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	string s;
	char ch;

	ch = in.get();

	while (!in.eof()) 
	{
		if (ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}') 
		{//ʶ��ֽ�� 4
			out << "<" << ch << ",4>\n";
			ch = in.get();
		}
		else if (isdigit(ch)) 
		{//ʶ������ 5 / ʵ�� 6
			s = "";
			while (isdigit(ch)) 
			{
				s += ch;
				ch = in.get();
				if (ch == '.') 
				{//����С���㣬�п����ǳ�ʵ��
					s += ch;
					ch = in.get();
					if (isdigit(ch)) 
					{
						while (isdigit(ch)) 
						{
							s += ch;
							ch = in.get();
						}
						out << "<" << s << ",6>\n";//��ʵ��
						break;
					}
					else out << s + " is error!\n";//���С�����û�����֣��򱨴�
				}
				if (!isdigit(ch)) 
				{
					out << "<" << s << ",5>\n";//������
					break;
				}
			}
		}
		else if (isalpha(ch) || ch == '_') 
		{//ʶ���ʶ�� 1 / ������ 2
			s = "";
			while (isalpha(ch) || isdigit(ch) || ch == '_') 
			{
				s += ch;
				ch = in.get();
			}
			if (lookup(s)) 
			{//��keyword���в���s�Ƿ��Ǳ�����
				out << "<" << s << ",2>\n";//������
			}
			else out << "<" << s << ",1>\n";//��ʶ��
		}
		//���涼������� 3
		else if (ch == '>') 
		{
			s = "";
			s += ch;
			ch = in.get();
			if (ch == '=') 
			{//">="
				s += ch;
				ch = in.get();
			}
			out << "<" << s << ",3>\n";
		}
		else if (ch == '<') 
		{
			s = "";
			s += ch;
			ch = in.get();
			if (ch == '=') 
			{//"<="
				s += ch;
				ch = in.get();
			}
			else if (ch == '>') 
			{//"<>"
				s += ch;
				ch = in.get();
			}
			out << "<" << s << ",3>\n";
		}
		else if (ch == '=') 
		{
			s = "";
			s += ch;
			ch = in.get();
			if (ch == '=') 
			{//"=="
				s += ch;
				ch = in.get();
			}
			out << "<" << s << ",3>\n";
		}
		else 
		{//������ǰ����
			ch = in.get();
		}
	}
	return 0;
}