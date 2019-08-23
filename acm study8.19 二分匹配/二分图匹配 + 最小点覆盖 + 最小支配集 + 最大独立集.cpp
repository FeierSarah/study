#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
/******************************************************
 * ����ͼƥ��(�������㷨���ڽӾ���+dfsʵ��)
 * ��ʼ����g[][]���߶���Ļ������
 * ����g[i][j]��ʾi->j������߾Ϳ����ˣ���������ұߵ�ƥ��
 * g û�б��������ʼ��Ϊ0
 * //un��ƥ����ߵĶ�������vn��ƥ���ұߵĶ�����
 * ���ã�res = hungray():������ƥ��
 * �ŵ㣺�����ڳ���ͼ��dfs������·��ʵ�ּ���������
 * ʱ�临�Ӷȣ�O(V,E)��
 * �����Ŵ�0��ʼ
const int maxn = 500 + 5;
int un, vn;//����ͼ��u, v����Ŀ��ʹ��ǰ���븳ֵ
int g[maxn][maxn];
int linker[maxn];//ÿ������ƥ����
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
 * �������㷨��ʽǰ����ʵ��
 * ʹ��ǰinit()���г�ʼ������un��ֵ
 * �ӱ�ʹ�ú���addedge(u, v)

const int maxn = 5000 + 5;//���������ֵ
const int maxm = 50000 + 5;//���������ֵ
struct Edge {
    int to, next;
} edge[maxm];
int head[maxn], tot;
int linker[maxn];//ÿ������ƥ����
bool used[maxn];
int un;//ƥ��u���ĸ���

void init() {
    tot = 0;
    memset(head, -1, sizeof head);
}

void addedge(int u, int v) {//��ӱߵ�ʱ��ǵ�Ҫ�����ƥ����u�ı��Ϊ[0, un)
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
 * ����ͼƥ�䣨Hopcroft-Karp�㷨��
 * ���Ӷȣ�O(sqrt(n) * E)
 * �ڽӱ��ͼ�� vectorʵ��
 * vector�ȳ�ʼ����Ȼ��ӱ�
 * unΪ��˵Ķ�������ʹ��ǰ��ֵ(����0��ʼ)

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
 * ���ֶ���ƥ��

const int maxn = 1000 + 5;
const int maxm = 500 + 5;
int un, vn;
int g[maxn][maxn];
int linker[maxm][maxn];
bool used[maxm];
int num[maxm];//�ұ�����ƥ����

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
 * KM�㷨
 * ���Ӷ� O(nx * nx * ny)
 * �����Ȩƥ��
 * ����СȨƥ�䣬�ɽ�Ȩֵȡ�෴�������ȡ�෴��
 * ��ı�Ŵ�0��ʼ

const int maxn = 300 + 5;
const int inf = 0x3f3f3f3f;
int nx, ny;
int g[maxn][maxn];
int linker[maxn], lx[maxn], ly[maxn];// y�и���ƥ��״̬��x�� y�еĵ���
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
 * ��С֧�伯
const int maxn = 1000 + 5;
int pre[maxn];//�洢���ڵ�
bool visit[maxn];//DFS�������
int newpos[maxn];//��������
int now;
int n, m;

int head[maxn];//��ʽǰ����
struct Node {int to; int next;};
Node edge[maxn];

void DFS(int x) {
    newpos[now ++] = x;//��¼��������
    for(int k = head[x]; k != -1; k = edge[k].next) {
        if(!visit[ edge[k].to ]) {
            visit[ edge[k].to ] = true;
            pre[edge[k].to] = x;//��¼���ڵ�
            DFS(edge[k].to);
        }
    }
}

int MDS() {
    bool s[maxn] = {0};
    bool set[maxn] = {0};
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {//�������̰��
        int t = newpos[i];
        if(!s[t]) { //�����ǰ��û������
            if(! set[ pre[t] ]) {//��ǰ��ĸ��ڵ㲻����֧�伯
                set[ pre[t] ] = true;//��ǰ��ĸ��ڵ����֧�伯
                ans ++;  //֧�伯�ڵ������ 1
            }
            s[t] = true; //��ǵ�ǰ���ѱ�����
            s[ pre[t] ] = true;// ��ǵ�ǰ��ĸ��ڵ㱻����
            s[ pre[ pre[t] ] ] = true;//��ǵ�ǰ��ĸ��ڵ�ĸ��ڵ㱻����
        }
    }
    return ans;
}

void solve() {
    memset(visit, false, sizeof(visit));//��ʼ��
    now = 0;
    visit[1] = true;
    pre[1] = 1;
    DFS(1);//�Ӹ��ڵ㿪ʼѰժ��������
    MDS();
}
 * ****************************************************/

/*******************************************************
 * ��С�㸲��
const int maxn = 1000 + 5;
int pre[maxn];//�洢���ڵ�
bool visit[maxn];//DFS�������
int newpos[maxn];//��������
int now;
int n, m;

int head[maxn];//��ʽǰ����
struct Node {int to; int next;};
Node edge[maxn];

void DFS(int x) {
    newpos[now ++] = x;//��¼��������
    for(int k = head[x]; k != -1; k = edge[k].next) {
        if(!visit[ edge[k].to ]) {
            visit[ edge[k].to ] = true;
            pre[edge[k].to] = x;//��¼���ڵ�
            DFS(edge[k].to);
        }
    }
}

int MVC() {
    bool s[maxn] = {0};
    bool set[maxn] = {0};
    int ans = 0;
    for(int i = n - 1; i >= 1; i--) {//�������̰��,�ų�������ڵ�
        int t = newpos[i];
        if(!s[t] && !s[ pre[t] ]) {//�����ǰ�ڵ���丸�ڵ㶼�����ڶ��㸲�Ǽ���
            set[ pre[t] ] = true;//���丸�ڵ���뵽���㸲�Ǽ���
            ans ++; //�����ڶ�������� 1
            s[t] = true;//��ǵ�ǰ�ڵ㱻����
            s[ pre[t] ] = true;//����丸�ڵ㱻����
        }        
    }
    return ans;
}

void solve() {
    memset(visit, false, sizeof(visit));//��ʼ��
    now = 0;
    visit[1] = true;
    pre[1] = 1;
    DFS(1);//�ӵ�һ�����ڵ㿪ʼѰ�ұ�������
    MVC();
}
 *  * ****************************************************/

/*******************************************************
 * ��������

const int maxn = 1000 + 5;
int pre[maxn];//�洢���ڵ�
bool visit[maxn];//DFS�������
int newpos[maxn];//��������
int now;
int n, m;

int head[maxn];//��ʽǰ����
struct Node {int to; int next;};
Node edge[maxn];

void DFS(int x) {
    newpos[now ++] = x;//��¼��������
    for(int k = head[x]; k != -1; k = edge[k].next) {
        if(!visit[ edge[k].to ]) {
            visit[ edge[k].to ] = true;
            pre[edge[k].to] = x;//��¼���ڵ�
            DFS(edge[k].to);
        }
    }
}

int MIS() {
    bool s[maxn] = {0};
    bool set[maxn] = {0};
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {//����DFS�������е��������̰��
        int t = newpos[i];
        if(!s[t]) {//�����ǰ�ڵ�û�б�����
            set[t] = true;//�ѵ�ǰ�ڵ���뵽������
            ans ++;//�������е�ĸ����� 1
            s[t] = true;//��ǵ�ǰ���Ѿ�������
            s[ pre[t] ] = true;//��ǵ�ǰ��ĸ��ڵ��Ѿ�������
        }        
    }
    return ans;
}

void solve() {
    memset(visit, false, sizeof(visit));//��ʼ��
    now = 0;
    visit[1] = true;
    pre[1] = 1;
    DFS(1);//�ӵ�һ�����ڵ㿪ʼѰ�ұ�������
    MIS();
}
 *  * ***************************************************/


int main() {

    return 0;
}
