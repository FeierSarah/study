//强连通分量：找到一个最大的图，使这个图中每个两点都能够互相到达。这个最大的图称为强连通分量，同时一个点也属于强连通分量。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
#define maxn 100010
struct node{
	int u, v;
	int next;
}edge[maxn];
int dfn[maxn], low[maxn];
int head[maxn];
int cnt, total;
stack<int> st;
void init(){
	while (!st.empty()) st.pop();
	memset(head, -1, sizeof head);
	cnt = 0;
	total = 0;
}
void add(int u, int v){
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
void tarjan(int u){
	dfn[u] = low[u] = ++total;
	st.push(u);
	for (int i = head[u]; ~i; i = edge[i].next){
		int v = edge[i].v;
		if (!dfn[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);//回溯
		}
		else {
			low[u] = min(low[u], dfn[v]);//更新，记录v可以不通过u而到达u的祖先节点
		}
	}
	if (low[u] == dfn[u]){
		while (1){
			int t = st.top();
			st.pop();
			cout << t << " ";
			if (t == u) break;
		}
		cout << endl;
	}
	return;
}
int n, m;
int main(){
	int u, v;
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i<m; i++){
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	return 0;
}
