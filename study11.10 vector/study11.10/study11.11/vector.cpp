#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

void testVec1()
{
	vector<char> v;
	vector<int> v2(10, 1);
	string s("123456");
	vector<int> v3(v2.begin(), v2.end());
	vector<char> v4(s.begin(), s.end());

	vector<int>::iterator v2vit = v2.begin();
	vector<char>::iterator v4vit = v4.begin();
	while (v2vit != v2.end())
	{
		cout << *v2vit << " ";
		++v2vit;
	}
	cout << endl;
	while (v4vit != v4.end())
	{
		cout << *v4vit << " ";
		++v4vit;
	}
	cout << endl;
}

struct A{
	A(int a)
	{}
	int a;
	int b;
	char c;
	double d;
};
void testVec2()
{
	vector<int> v;
	vector<char> v2;
	vector<A> v3;
	int v1s = v.max_size();
	int v2s = v.max_size();
	int v3s = v.max_size();
	v.resize(10);//int()
	v2.resize(10);//char()
	v3.resize(10,A(10));//默认构造

	v[5] = 100;
	/*for (const auto& ch : v3)
	{
		ch = 'a';
	}*/

	auto vit = v2.begin();

	*vit = 'Z';
}

void testVec3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.pop_back();

	vector<int> v2;
	size_t cap = v2.capacity();
	cout << cap << endl;
	for (int i = 0; i < 100;i++)
	{
		v2.push_back(i);
		if (cap != v2.capacity())
		{
			cap = v2.capacity();
			cout << cap << endl;
		}
	}

	vector<char> v3;
	v3.insert(v3.begin(), 'a');
	v3.insert(v3.end(), 'b');
	string str("123");
	v3.insert(v3.begin(), str.begin(), str.end());
	v3.insert(v3.end(), 10, 'e');
	v3.erase(v3.begin());
	auto vit = v3.begin();
	cout << *vit << endl;
	v3.erase(v3.begin(), v3.end());
	cout << *vit << endl;

	////迭代器失效
	//vector<int> v;
	//v.push_back(1);
	//auto vit = v.begin();
	////cout << *vit << endl;
	//v.insert(vit, 10, 10);
	////插入如果进行增容，会导致迭代器失效
	////插入之后，重新获取迭代器避免失效
	////cout << *vit << endl;
	//auto vit = v.begin();
	////cout << *vit << endl;
	//v.insert(vit, 5);
	////cout << *vit << endl;
	//auto vit = v.begin();
	////删除也会导致迭代器失效
	//v.erase(vit);
	////cout << *vit << endl;

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(7);

	auto it2 = v2.begin();
	while (it2 != v2.end())
	{
		if (*it2 % 2 == 0)
		{
			it2 = v2.erase(it2);
		}
		else
			++it2;
	}

	//string 迭代器在插入，如果增容，也会导致失效
	string str("123456");
	auto it3 = str.begin();
	cout << *it3 << endl;
	str += "78901234566";
	it3 = str.begin();
	str.erase(it3);
	cout << *it3 << endl;
}

void testVec4()
{
	vector<int> v;
	v.push_back(1);
	v.emplace_back(2);

	v.insert(v.begin(), 0);
	v.emplace(v.begin(), -1);
}

int main()
{
	testVec1();
	testVec2();
	return 0;
}