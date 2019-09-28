/*
欧拉序+ST表
最近公共祖先是在该序列上两个点第一次出现的区间内深度最小的那个点
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 10010
vector<int> tree[maxn];
struct node{
	int deep;
	int m;
}a[maxn<<2],num[maxn<<2][25];//a存的是欧拉序，num是ST表
int first[maxn];//存每个节点第一次出现的cnt
int deep[maxn];//深度
bool find_root[maxn];
int root,n,q;
int cnt;
node calc(node a,node b){
	if(a.deep<b.deep) return a;
	return b;
}
void dfs(int x){
	first[x]=cnt;
	if(tree[x].size()==0){
		a[cnt].m=x;
		a[cnt++].deep=deep[x];
	}
	for(int i=0;i<tree[x].size();i++){
		int y=tree[x][i];
		deep[y]=deep[x]+1;
		a[cnt].m=x;
		a[cnt++].deep=deep[x];
		dfs(y);
	}
}
void ST(){
	int l=int(log((double)cnt)/log(2.0));
	for(int j=1;j<=l;j++){
		for(int i=1;i+(1<<(j-1))-1<=cnt;i++){
			num[i][j]=calc(num[i][j-1], num[i+(1<<(j-1))][j-1]);
		}
	}
}
void init(){
	for(int i=1;i<=n;i++){
		if(!find_root[i]){
			root=i;
			break;
		}
	}
	cnt=1;
	deep[root]=1;
	dfs(root);
	cnt--;
	for(int i=1;i<=cnt;i++){
		num[i][0]=a[i];
	}
	ST();
}
int rmq(int l,int r){
	l=first[l];
	r=first[r];
	if(l>r) swap(l,r);
	int k=int(log((double)(r-l+1))/log(2.0));
	return calc(num[l][k],num[r-(1<<k)+1][k]).m;
}
int main(){
	int x,y;
	scanf("%d %d", &n, &q);
	memset(find_root,false,sizeof find_root);
	for(int i=1;i<n;i++){
		scanf("%d %d", &x, &y);
		tree[x].push_back(y);
		find_root[y]=true;
	}
	init();
	while(q--){
		scanf("%d %d", &x, &y);
		printf("%d\n", rmq(x,y));
	}
	return 0;
}

