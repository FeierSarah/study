//Â¬¿¨Ë¹¶¨Àí 
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
#define maxn 100010
ll n, m, p=1000000007, fac[maxn];
ll Fast_Pow(ll x, ll k) 
{
    ll ans = 1;
    while(k) 
	{
        if( k&1 )
		ans = ans * x % p;
        k >>= 1;
		x = x * x % p;
    }
    return ans;
}
ll C(ll k, ll b) 
{
    if( k<b )
	  return 0;
	return fac[k] * Fast_Pow(fac[b] % p, p-2) % p * Fast_Pow(fac[k-b] % p, p-2) % p;
}
ll Lucas(ll k, ll b)
{
    if( !b )  return 1;
    return C(k%p, b%p) * Lucas(k/p, b/p) % p;
}
int main()
{
    fac[0] = 1;
    scanf("%lld%lld", &n, &m);
    for(int i=1; i<=p; ++i)
    fac[i] = fac[i-1] * i % p;
    printf("%lld\n", Lucas(n, m));
    return 0;
}
