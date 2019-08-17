#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
int main()
{
	LL a,b;
	scanf("%lld %lld", &a,&b);
	LL chushu,beichushu,yushu;
	chushu=min(a,b);
	beichushu=max(a,b);
	yushu=beichushu%chushu;
	while(yushu!=0)
	{
		beichushu=chushu;
		chushu=yushu;
		yushu=beichushu%chushu;
	}
	printf("%lld\n",chushu);
	return 0;
}
