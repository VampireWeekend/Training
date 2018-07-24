#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int x[maxn],y[maxn],head[maxn],ans[maxn];
ll z[maxn];
ll n,m,num=0;
//original graph
struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,ll dist) {
	edge[num].from = from; edge[num].to = to;
	edge[num].pre = head[from]; edge[num].dist = dist;
	head[from]=num++;
	edge[num].from = to; edge[num].to = from;
	edge[num].pre = head[to]; edge[num].dist = dist;
	head[to]=num++;
}
//shortest path
struct node {
	int id;ll dist;
	node(int id,ll dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};
priority_queue<node> pq;

ll dist[maxn];
bool visit[maxn];
void dij(int n,int s) {
	int j,i;
	mem0(visit);
	priority_queue<node> pq;
	visit[s]=1;
	for (j=head[s];j!=-1;j=edge[j].pre) 
		pq.push(node(j,edge[j].dist));
	meminf(dist);dist[s]=0;
	for (int k=1;k<n;k++) {
		while (visit[edge[pq.top().id].to]&&!pq.empty()) pq.pop();
		if (pq.empty()) break;
		i=pq.top().id;
		int to=edge[i].to;
		if (visit[to]) continue;
		visit[to]=1;
		dist[to]=pq.top().dist;
		pq.pop();
		for (j=head[to];j!=-1;j=edge[j].pre) 
			if (!visit[edge[j].to]) 
				pq.push(node(j,dist[to]+edge[j].dist));
	}
}
//new graph
#define N maxn
struct eg{ int dt,nx; }e[N];
int tim,tot;
int h[N],iw[N],li[N],fa[N],sdom[N],idom[N],du[maxn],re[maxn];
int fo[N],vo[N];
vector<int> pre[N],bkt[N],v[maxn];
void init() {
	tim = tot = 0;
	for(int i=1;i<=n;i++) h[i] = iw[i] = 0, fo[i] = vo[i] = i, pre[i].clear(), bkt[i].clear();
}
inline void link(int a,int b,int id)
{
	e[++tot].dt = b, e[tot].nx = h[a], h[a] = tot;
	pre[b].push_back(a);
	du[b]++;re[b]=id;
}
//construct new graph
void CNG(int m) {
	for (int i=1;i<=m;i++) {
		if (dist[x[i]]==dist[y[i]]+z[i]) link(y[i],x[i],i); else
			if (dist[y[i]]==dist[x[i]]+z[i]) link(x[i],y[i],i);
	}
}
//dominator tree
int findf(int p)
{
	if(fo[p]==p) return p;
	int r = findf(fo[p]);
	if(sdom[vo[fo[p]]]<sdom[vo[p]]) vo[p] = vo[fo[p]];
	return fo[p] = r;
}
inline int eval(int p)
{ 
	findf(p); 
	return vo[p]; 
}
void dfs(int p)
{
	li[iw[p]=++tim] = p, sdom[p] = iw[p];
	for(int pt=h[p];pt;pt=e[pt].nx) if(!iw[e[pt].dt])
		dfs(e[pt].dt), fa[e[pt].dt] = p;
}
void work()
{
	int i,p;
	dfs(1);
	for(int i=tim;i>=2;i--)
	{
		p = li[i];
		for(int k : pre[p]) if(iw[k]) sdom[p] = min(sdom[p],sdom[eval(k)]);
		bkt[li[sdom[p]]].push_back(p);
		int fp = fa[p]; fo[p] = fa[p];
		for(int v : bkt[fp])
		{
			int u = eval(v);
			idom[v] = sdom[u]==sdom[v]?fp:u;
		}
		bkt[fp].clear();
	}
	for(int i=2;i<=tim;i++) p = li[i], idom[p] = idom[p]==li[sdom[p]]?idom[p]:idom[idom[p]];
	for(int i=2;i<=tim;i++) p = li[i], sdom[p] = li[sdom[p]];
}

int dp[maxn];
void getans(int now) {
	int size=v[now].size();
	dp[now]=1;
	for (int i=0;i<size;i++) {
		getans(v[now][i]);
		dp[now]+=dp[v[now][i]];
	}
	if (du[now]==1) ans[re[now]]=dp[now];
}

int main() {
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for (int i=1;i<=m;i++) {
		scanf("%d%d%lld",&x[i],&y[i],&z[i]);
		addedge(x[i],y[i],z[i]);
	}
	dij(n,1);
	init();
	CNG(m);
	work();
	for (int i=2;i<=n;i++) {
		v[idom[i]].pb(i);
	}
	getans(1);
	for (int i=1;i<=m;i++) {
		if (du[y[i]]>1) printf("0\n"); else printf("%d\n",ans[i]);
	}
//	system("pause");
	return 0;
}
