/*
DFS+�����Ż�
�뱩�����Ա�:
����һ��һ��������Ѱ�Ҹ��׽ڵ㣬��������Ѱ��
˼·��
����˼�룺�κ����ֶ�����ת��Ϊ�����ƣ�
��ô�Ҵ�ÿһ���ڵ�Ķ����ݴ�λ���ȣ�
�ǲ�����Ҫ�Ǹ��ڵ�ĵڶ������ȿ��Ժܿ��ѯ����
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 10010
vector<int> tree[maxn];
int anc[maxn][25];
int fa[maxn];
int deep[maxn];
bool find_root[maxn];
int root,n,q;
void dfs(int x){
	anc[x][0]=fa[x];
	for(int i=1;i<=22;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];//���ֱ���
	}
	for(int i=0;i<tree[x].size();i++){
			int y=tree[x][i];
			fa[y]=x;
			deep[y]=deep[x]+1;
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
int lca(int x,int y) {
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=22;i>=0;i--) {
        if (deep[y]<=deep[anc[x][i]]) {
            x=anc[x][i];
        }
    }
    if (x==y) return x;
    for (int i=22;i>=0;i--){
        if (anc[x][i]!=anc[y][i]) {
            x=anc[x][i];
            y=anc[y][i];
        }
    }
    return anc[x][0];//ע��ڶ���IF����������
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

