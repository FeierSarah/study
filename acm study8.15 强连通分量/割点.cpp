#include <bits/stdc++.h>
using namespace std;
#define maxn 1000100
struct node{
	int u,v;
	int next;
}edge[maxn];
int dfn[maxn],low[maxn];
int head[maxn];
int cnt,total;
void init(){
	memset(head,-1,sizeof head);
	cnt=total=0;
}
void add(int u,int v){
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void tarjan(int u,int fa){
	dfn[u]=low[u]=++total;
	int k=0;
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(!dfn[v]){
			k++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if((u!=fa&&dfn[u]<=low[v])||(u==fa&&k>1)){
				cout<<u<<endl;
			}
		}else if(fa!=v){
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int n,m;
int main(){
	int u,v;
	scanf("%d %d", &n, &m);
	init();
	for(int i=0;i<m;i++){
		scanf("%d %d", &u, &v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,i);
	return 0;
}
