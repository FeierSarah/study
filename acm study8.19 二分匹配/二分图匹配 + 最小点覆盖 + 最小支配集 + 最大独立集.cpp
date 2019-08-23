#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
/******************************************************
 * 二分图匹配(匈牙利算法得邻接矩阵+dfs实现)
 * 初始化：g[][]两边顶点的划分情况
 * 建立g[i][j]表示i->j的有向边就可以了，是左边向右边的匹配
 * g 没有边相连则初始化为0
 * //un是匹配左边的顶点数，vn是匹配右边的顶点数
 * 调用：res = hungray():输出最大匹配
 * 优点：适用于稠密图，dfs找增广路，实现简洁易于理解
 * 时间复杂度：O(V,E)。
 * 顶点编号从0开始
const int maxn = 500 + 5;
int un, vn;//二分图中u, v的数目，使用前必须赋值
int g[maxn][maxn];
int linker[maxn];//每个结点的匹配结点
bool used[maxn];         

bool dfs(int u) {
    for(int v = 0; v < vn; v ++) {
        if(g[u][v] && !used[v]) {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    int res = 0;
    memset(linker, -1, sizeof linker);
    for(int u = 0; u < un; u ++) {
        memset(used, false, sizeof used);
        if(dfs(u)) res ++;
    }
    return res;
}
 * ***************************************************/

/******************************************************
 * 匈牙利算法链式前向星实现
 * 使用前init()进行初始化，给un赋值
 * 加边使用函数addedge(u, v)

const int maxn = 5000 + 5;//点数的最大值
const int maxm = 50000 + 5;//边数的最大值
struct Edge {
    int to, next;
} edge[maxm];
int head[maxn], tot;
int linker[maxn];//每个结点的匹配结点
bool used[maxn];
int un;//匹配u结点的个数

void init() {
    tot = 0;
    memset(head, -1, sizeof head);
}

void addedge(int u, int v) {//添加边的时候记得要让左侧匹配结点u的编号为[0, un)
    edge[tot].to = v; edge[tot].next = head[u];
    head[u] = tot ++;
}

bool dfs(int u) {
    for(int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if(!used[v]) {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    int res = 0;
    memset(linker, -1, sizeof linker);
    for(int u = 0; u < un; u ++) {
        memset(used, false, sizeof used);
        if(dfs(u)) res ++;
    }
    return res;
}
 * ****************************************************/

/*******************************************************
 * 二分图匹配（Hopcroft-Karp算法）
 * 复杂度：O(sqrt(n) * E)
 * 邻接表存图， vector实现
 * vector先初始化，然后加边
 * un为左端的顶点数，使用前赋值(点编号0开始)

const int maxn = 3000 + 5;
const int inf = 0x3f3f3f3f;
vector <int> G[maxn];
int un;
int mx[maxn], my[maxn];
int dx[maxn], dy[maxn];
int dis;
bool used[maxn];
bool searchp() {
    queue <int> que;
    dis = inf;
    memset(dx, -1, sizeof dx);
    memset(dy, -1, sizeof dy);
    for(int i = 0; i < un; i ++) {
        if(mx[i] == -1) {
            que.push(i);
            dx[i] = 0;
        }
    }
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        if(dx[u] >dis) break;
        int sz = G[u].size();
        for(int i = 0; i < sz; i ++) {
            int v = G[u][i];
            if(dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if(my[v] == -1) dis = dy[v];
                else {
                    dx[my[v]] = dy[v] + 1;
                    que.push(my[v]);
                }
            }
        }
    }
    return dis != inf;
}

bool dfs(int u) {
    int sz = G[u].size();
    for(int i = 0; i < sz; i ++) {
        int v = G[u][i];
        if(!used[v] && dy[v] == dx[u] + 1) {
            used[v] = true;
            if(my[v] != -1 && dy[v] == dis) continue;
            if(my[v] == -1 || dfs(my[v])) {
                my[v] = u;
                mx[u] = v;
                return true;
            }
        }
    }
    return false;
}

int maxmatch() {
    int res = 0;
    memset(mx, -1, sizeof mx);
    memset(my, -1, sizeof my);
    while(searchp()) {
        memset(used, false, sizeof used);
        for(int i = 0; i < un; i ++) {
            if(mx[i] == -1 && dfs(i))
                res ++;
        }
    }
    return res;
}
 * ****************************************************/

/*******************************************************
 * 二分多重匹配

const int maxn = 1000 + 5;
const int maxm = 500 + 5;
int un, vn;
int g[maxn][maxn];
int linker[maxm][maxn];
bool used[maxm];
int num[maxm];//右边最大的匹配数

bool dfs(int u) {
    for(int v = 0; v < vn; v ++) {
        if(g[u][v] && !used[v]) {
            used[v] = true;
            if(linker[v][0] < num[v]) {
                linker[v][++ linker[v][0]] = u;
                return true;
            }
            for(int i = 1; i <= num[v]; i ++) {
                if(dfs(linker[v][i])) {
                    linker[v][i] = u;
                    return true;
                }
            }
        }
    }
    return false;
}

int hungary() {
    int res = 0;
    for(int i = 0; i < vn; i ++)
        linker[i][0] = 0;
        for(int u = 0; u < un; u ++) {
            memset(used, false, sizeof used);
            if(dfs(u)) res ++;
        }
    return res;
}
 * *****************************************************/

/********************************************************
 * KM算法
 * 复杂度 O(nx * nx * ny)
 * 求最大权匹配
 * 若最小权匹配，可将权值取相反数，结果取相反数
 * 点的编号从0开始

const int maxn = 300 + 5;
const int inf = 0x3f3f3f3f;
int nx, ny;
int g[maxn][maxn];
int linker[maxn], lx[maxn], ly[maxn];// y中个点匹配状态，x， y中的点标号
int slack[maxn];
bool visx[maxn], visy[maxn];

bool dfs(int x) {
    visx[x] = true;
    for(int y = 0; y < ny; y ++) {
        if(visy[y]) continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if(tmp == 0) {
            visy[y] = true;
            if(linker[y] == -1 || dfs(linker[y])) {
                linker[y] = x;
                return true;
            }
        }
        else if(slack[y] > tmp)
            slack[y] = tmp;
    }
    return false;
}

int km() {
    memset(linker, -1, sizeof linker);
    memset(ly, 0, sizeof ly);
    for(int i = 0; i < nx; i ++) {
        lx[i] = -inf;
        for(int j = 0; j < ny; j ++) 
            if(g[i][j] > lx[i])
                lx[i] = g[i][j];
    }
    for(int x = 0; x < nx; x ++) {
        for(int i = 0; i < ny; i ++)
            slack[i] = inf;
        while(true) {
            memset(visx, false, sizeof visx);
            memset(visy, false, sizeof visy);
            if(dfs(x)) break;
            int d = inf;
            for(int i = 0; i < ny; i ++)
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            for(int i = 0; i < nx; i ++)
                if(visx[i])
                    lx[i] -= d;
            for(int i = 0; i < ny; i ++) {
                if(visy[i]) ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < ny; i ++) 
        if(linker[i] != -1)
            res += g[linker[i]][i];
    return res;
}
* *****************************************************/

/*******************************************************
 * 最小支配集
const int maxn = 1000 + 5;
int pre[maxn];//存储父节点
bool visit[maxn];//DFS标记数组
int newpos[maxn];//遍历序列
int now;
int n, m;

int head[maxn];//链式前向星
struct Node {int to; int next;};
Node edge[maxn];

void DFS(int x) {
    newpos[now ++] = x;//记录遍历序列
    for(int k = head[x]; k != -1; k = edge[k].next) {
        if(!visit[ edge[k].to ]) {
            visit[ edge[k].to ] = true;
            pre[edge[k].to] = x;//记录父节点
            DFS(edge[k].to);
        }
    }
}

int MDS() {
    bool s[maxn] = {0};
    bool set[maxn] = {0};
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {//逆序进行贪心
        int t = newpos[i];
        if(!s[t]) { //如果当前点没被覆盖
            if(! set[ pre[t] ]) {//当前点的父节点不属于支配集
                set[ pre[t] ] = true;//当前点的父节点加入支配集
                ans ++;  //支配集节点个数加 1
            }
            s[t] = true; //标记当前点已被覆盖
            s[ pre[t] ] = true;// 标记当前点的父节点被覆盖
            s[ pre[ pre[t] ] ] = true;//标记当前点的父节点的父节点被覆盖
        }
    }
    return ans;
}

void solve() {
    memset(visit, false, sizeof(visit));//初始化
    now = 0;
    visit[1] = true;
    pre[1] = 1;
    DFS(1);//从根节点开始寻摘遍历序列
    MDS();
}
 * ****************************************************/

/*******************************************************
 * 最小点覆盖
const int maxn = 1000 + 5;
int pre[maxn];//存储父节点
bool visit[maxn];//DFS标记数组
int newpos[maxn];//遍历序列
int now;
int n, m;

int head[maxn];//链式前向星
struct Node {int to; int next;};
Node edge[maxn];

void DFS(int x) {
    newpos[now ++] = x;//记录遍历序列
    for(int k = head[x]; k != -1; k = edge[k].next) {
        if(!visit[ edge[k].to ]) {
            visit[ edge[k].to ] = true;
            pre[edge[k].to] = x;//记录父节点
            DFS(edge[k].to);
        }
    }
}

int MVC() {
    bool s[maxn] = {0};
    bool set[maxn] = {0};
    int ans = 0;
    for(int i = n - 1; i >= 1; i--) {//逆序进行贪心,排除掉其根节点
        int t = newpos[i];
        if(!s[t] && !s[ pre[t] ]) {//如果当前节点和其父节点都不属于顶点覆盖集合
            set[ pre[t] ] = true;//把其父节点加入到顶点覆盖集合
            ans ++; //集合内顶点个数加 1
            s[t] = true;//标记当前节点被覆盖
            s[ pre[t] ] = true;//标记其父节点被覆盖
        }        
    }
    return ans;
}

void solve() {
    memset(visit, false, sizeof(visit));//初始化
    now = 0;
    visit[1] = true;
    pre[1] = 1;
    DFS(1);//从第一个根节点开始寻找遍历序列
    MVC();
}
 *  * ****************************************************/

/*******************************************************
 * 最大独立集

const int maxn = 1000 + 5;
int pre[maxn];//存储父节点
bool visit[maxn];//DFS标记数组
int newpos[maxn];//遍历序列
int now;
int n, m;

int head[maxn];//链式前向星
struct Node {int to; int next;};
Node edge[maxn];

void DFS(int x) {
    newpos[now ++] = x;//记录遍历序列
    for(int k = head[x]; k != -1; k = edge[k].next) {
        if(!visit[ edge[k].to ]) {
            visit[ edge[k].to ] = true;
            pre[edge[k].to] = x;//记录父节点
            DFS(edge[k].to);
        }
    }
}

int MIS() {
    bool s[maxn] = {0};
    bool set[maxn] = {0};
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {//按照DFS遍历序列的逆序进行贪心
        int t = newpos[i];
        if(!s[t]) {//如果当前节点没有被覆盖
            set[t] = true;//把当前节点加入到独立集
            ans ++;//独立集中点的个数加 1
            s[t] = true;//标记当前点已经被覆盖
            s[ pre[t] ] = true;//标记当前点的父节点已经被覆盖
        }        
    }
    return ans;
}

void solve() {
    memset(visit, false, sizeof(visit));//初始化
    now = 0;
    visit[1] = true;
    pre[1] = 1;
    DFS(1);//从第一个根节点开始寻找遍历序列
    MIS();
}
 *  * ***************************************************/


int main() {

    return 0;
}
