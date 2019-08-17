//Å·À­º¯Êý
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
int main() 
{
	LL x;
	scanf("%lld",&x);
	LL phi=x;
	for(int pi=2;pi<=x;pi++)
	{
	    if(x%pi==0)
	    {
	    	phi=phi/pi*(pi-1);
	    	while(x%pi==0)
	    	{
	    		x/=pi;
			}
	    }
	}
	printf("%lld\n",phi);
	return 0; 
}
