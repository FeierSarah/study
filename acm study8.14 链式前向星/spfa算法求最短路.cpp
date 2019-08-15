//最短路算法之 Bellman-Ford 。
//该算法是基于松弛操作运行的，每条边都松弛 v – 1 次，从而
//求得源点到每个结点的最短路径。
//SPFA 算法的基本思路与 Bellman-Ford 算法相同，即每个节
//点都被用作松弛其相邻节点的备选节点。相较于 Bellman-Ford
//算法， SPFA 算法的提升在于它并不盲目尝试所有节点，而是维
//护一个备选节点队列，并且仅有节点被松弛后才会放入队列中。
//整个流程不断重复直至没有节点可以被松弛。

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=505;
const int maxm=2525;
const int inf=0x3f3f3f3f;
struct Edge
{
	int to,next,cost;
}edge[maxm];
int head[maxn];
int cnt;
void init()
{
	memset(head,-1,sizeof head);
	cnt=0;
}
void addedge(int u,int v,int cost)
{
	edge[cnt].to=v;
	edge[cnt].cost=cost;
	edge[cnt].next=head[u]; 
	head[u]=cnt++;
}
bool vis[maxn];//判断是否在队列 
//int num[maxn];
//int pre[maxn];
double dist[maxn];//记录到起始点的最短长度 
bool spfa(int b)
{
	memset(vis,false,sizeof vis);//在队列标志 
//	memset(num,0,sizeof num);//每个结点入队的次数 
//	memset(pre,-1,sizeof pre);//每个结点在最短路径树中的父亲结点 
	fill(dist,dist+maxn,inf);
	int flag=0;
	vis[b]=true;
	dist[b]=1;
//	num[b]=1;
	queue<int> que;
	while(!que.empty()) 
	que.pop();
	que.push(b);
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		vis[u]=false;
		int i;
		for(i=head[u];~i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dist[v]>dist[u]+edge[i].cost)
			{
				flag=1;
				dist[v]=dist[u]+edge[i].cost;
//				pre[v]=u;
				if(!vis[v])
				{
					vis[v]=true;
					que.push(v);
					if(v==b&&dist[v]<0) return true;//存在负环 
				}
			}
		}
	}
	return false;
}
int main()
{
	int f;
	cin>>f;
	while(f--)
	{
		init();
		int n,v,w;
		cin>>n>>v>>w;
		while(v--)
		{
			int s,e,cost;
			cin>>s>>e>>cost;
			addedge(s,e,cost);
			addedge(e,s,cost);
		}
		while(w--)
		{
			int s,e,cost;
			cin>>s>>e>>cost;
			addedge(s,e,-cost);
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(spfa(i))
			{
				flag=1;
			}
		}
		if(flag)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
