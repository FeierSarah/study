#include <iostream>
#include <functional>
#include <map>
using namespace std;

void testMulMap()
{
	multimap<char, int> mp;

	mp.insert(make_pair('b', 20));
	mp.insert(make_pair('b', 30));
	mp.insert(make_pair('b', 40));
	mp.insert(make_pair('b', 50));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('c', 60));

	cout << "multimap" << endl;
	for (const auto& p : mp)
	{
		cout << p.first << "-->" << p.second << endl;
	}
	cout << endl;

	pair<multimap<char, int>::const_iterator, multimap<char, int>::const_iterator> ret = mp.equal_range('b');
	auto ret1 = mp.equal_range('b');
	cout << "key:b" << endl;
	auto begin = ret.first;
	begin++;
	cout << endl;

	cout << "find key:b" << endl;
	cout << endl;
}
void testMap()
{
	map<char, int> mp;
	mp.insert(make_pair('b', 20));
	mp.insert(make_pair('b', 30));
	mp.insert(make_pair('b', 40));
	mp.insert(make_pair('b', 50));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('c', 60));

	cout << "multimap less" << endl;
	for (const auto& p : mp)
	{
		cout << p.first << "-->" << p.second << endl;
	}
	cout << endl;
}

void testMap2()
{
	map<char, int, greater<int>> mp;
	mp.insert(make_pair('b', 20));
	mp.insert(make_pair('b', 30));
	mp.insert(make_pair('b', 40));
	mp.insert(make_pair('b', 50));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('c', 60));

	cout << "multimap greater" << endl;
	for (const auto& p : mp)
	{
		cout << p.first << "-->" << p.second << endl;
	}
	cout << endl;
}
int main()
{
	testMulMap();
	testMap();
	testMap2();
	return 0;
}