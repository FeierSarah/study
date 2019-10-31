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
	char str2[] = "中国";
}

void testIterator() {
	string s2("hello world");
	/*
	   迭代器：一种容器内容的访问机制
	   使用方式：类似于指针的使用方式
	   begin迭代器：指向容器的第一个元素的位置
	   end迭代器：指向容器的最后一个元素的下一个位置
	   左闭右开：[begin, end]
	*/
	string::iterator it = s2.begin();
	while (it != s2.end()) {
		//*it = 'a';  可读可写
		cout << *it << " " ;
		++it;
	}
	cout << endl;

	//反向迭代器
	// begin迭代器：指向容器的第一个元素的前一个位置
	//end迭代器：指向容器的最后一个元素的位置
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

	//const迭代器只读
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