/*
ST表求解 RMQ 区间最值查询
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
int num[maxn][25];
int a[maxn];
int n,q;
void ST(){
	int l=int(log((double)n)/log(2.0));
	for(int j=1;j<=l;j++){
		for(int i=1;i+(1<<(j-1))-1<=n;i++){
			num[i][j]=max(num[i][j-1], num[i+(1<<(j-1))][j-1]);
		}
	}
}
int rmq(int l,int r){
	int k=int(log((double)(r-l+1))/log(2.0));
	return max(num[l][k],num[r-(1<<k)+1][k]);
}
int main(){
	int x,y;
	scanf("%d %d", &n, &q);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		num[i][0]=a[i];
	}
	ST();
	while(q--){
		scanf("%d %d", &x, &y);
		printf("%d\n", rmq(x,y));
	}
	return 0;
}
