//费马小定理
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
int p = 19260817;
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		LL x,X;
		scanf("%lld", &x);
		X=(x%p);
		for (int i = 1; i < p - 2; i++)
		{
			x *=X;
			x = (x%p);
		}
		printf("%lld\n", x);
	}
	return 0;
}
