#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
	int a, b, x;
	cin >> x;
	a = x / 2;
	b = x - a;
	for (; a > 0, b < x; a--, b++)
	{
		int count = 0;
		for (int i = 2; i < a; i++)
		{
			if (a % i == 0)
				break;
			count++;
		}
		for (int i = 2; i < b; i++)
		{
			if (b % i == 0)
				break;
			count++;
		}
		if (count == a + b - 4)
			break;
	}
	cout << a << endl << b << endl;
	return 0;
}