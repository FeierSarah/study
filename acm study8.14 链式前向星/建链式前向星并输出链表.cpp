#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1005, maxm = 2005;
int m, n, cnt, head[maxn];
struct Edge
{
	int to, next;
}edge[maxm];
inline void init()
{
	cnt = 0;
	memset(head, -1, sizeof head);
}
inline void addedge(int u, int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
int main()
{
	int u, v;
	init();
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		addedge(u, v);
	}
	for (int i = 1; i <=n; i++)
	{
		for (int j = head[i]; ~j; j = edge[j].next)
		{
			printf("%d %d\n", i, edge[j].to);
		}
	}
	return 0;
}
