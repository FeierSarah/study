/*
DFS建树 + 普通搜索
思路：
建树：找到根节点，
然后记录每个节点的父亲节点
和该节点的的深度，
搜索：从两个节点开始向上找，
一直找的两个节点重合为止
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 10010
vector<int> tree[maxn];
int fa[maxn];
int deep[maxn];
bool find_root[maxn];
int root,n,q;
void dfs(int x){
	for(int i=0;i<tree[x].size();i++){
		int y=tree[x][i];
		deep[y]=deep[x]+1;
		fa[y]=x;
		dfs(y);
	}
}
void init(){
	for(int i=1;i<=n;i++){
		if(!find_root[i]){
			root=i;
			break;
		}
	}
	deep[root]=1;
	fa[root]=root;
	dfs(root);
}
int lca(int x,int y){
	while(deep[x]>deep[y]) x=fa[x];
	while(deep[x]<deep[y]) y=fa[y];
	while(x!=y){
		x=fa[x];
		y=fa[y];
	}
	return x;
}
int main(){
	scanf("%d %d", &n, &q);
	memset(find_root,false,sizeof find_root);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		find_root[v]=true;
	}
	init();
	while(q--){
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u,v));
	}
	return 0;
}


