#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
#define maxn 19260817
ll gcd(ll a,ll b){
  return b==0?a:gcd(b,a%b);
}
ll Euler(ll n){
  ll x=n;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      x=x/i*(i-1);
    while(n%i==0) n/=i;
    }
  }
  if(n>1) x=x/n*(n-1);
  return x;
}
ll Pow(ll a,ll b,ll mod){
  ll res=1;
  while(b){
    if(b&1) res=(res*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return res;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    ll a,c,n;
    scanf("%lld%lld%lld",&a,&c,&n);
    ll p=Euler(n);
    ll res=0;
    //printf("lld\n",gcd(a,n));
    if(gcd(a,n)==1){
      res=Pow(a,c%p,n)%n;
    }
    else if(gcd(a,n)!=1&&c<p){
      res=Pow(a,c,n)%n;
    }
    else if(gcd(a,n)!=1&&c>=p){
      res=Pow(a,c%p+p,n)%n;
    }
    printf("%lld\n",res);
    /*ll n;
    scanf("%lld",&n);
    printf("%lld\n",Pow(n,maxn-2,maxn));*/
  }
  return 0;
}
