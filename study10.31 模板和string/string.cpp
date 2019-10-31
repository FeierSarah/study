#include<iostream>
#include<list>
#include<string>
using namespace std;
//string    basic_string<char>
//typedef basic_string<char, char_traits, allocator> string

void testString1() {
	string s;
	string s2("hello world");
	string copy(s2);
	string s2(s2, 0, 5);//hello
	string s4("hello world", 2);//he
	string s5(10, 'a');//aaaaaaaaaa

	char str1[] = "china";
	char str2[] = "�й�";
}

void testIterator() {
	string s2("hello world");
	/*
	   ��������һ���������ݵķ��ʻ���
	   ʹ�÷�ʽ��������ָ���ʹ�÷�ʽ
	   begin��������ָ�������ĵ�һ��Ԫ�ص�λ��
	   end��������ָ�����������һ��Ԫ�ص���һ��λ��
	   ����ҿ���[begin, end]
	*/
	string::iterator it = s2.begin();
	while (it != s2.end()) {
		//*it = 'a';  �ɶ���д
		cout << *it << " " ;
		++it;
	}
	cout << endl;

	//���������
	// begin��������ָ�������ĵ�һ��Ԫ�ص�ǰһ��λ��
	//end��������ָ�����������һ��Ԫ�ص�λ��
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	for (int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	//const������ֻ��
	const string s3("hello");
	string::const_iterator s3it = s3.begin();
	while (s3it != s3.end())
	{
		//*s3it = 'a';
		cout << *s3it << " ";
		++s3it;
	}
	cout << endl;

	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	list<int>::iterator lit = l.begin();
	while (lit != l.end()) {
		cout << *lit << " " ;
		++lit;
	}
	cout << endl;
}

int main() {
	testString1();
	return 0;
}