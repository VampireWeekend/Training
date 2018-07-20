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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define push_back pb
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn],x[maxn],y[maxn];
ll z[maxn];
ll dist[maxn][2];
bool visit[maxn];
int num=0;

struct Edge{
	int from,to,pre;
	ll dist;
};
Edge edge[maxn*2];

void addedge(int x,int y,ll z){
	edge[num].from=x;edge[num].to=y;
	edge[num].pre=head[x];
	edge[num].dist=z;head[x]=num++;
	edge[num].to=x;edge[num].from=y;
	edge[num].pre=head[y];
	edge[num].dist=z;head[y]=num++;
}

struct node {
	int id;ll dist;
	node(int id,ll dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};
priority_queue<node> pq;

ll dij(int n,int s,int t,int q) {
	int j,i;
	mem0(visit);
	priority_queue<node> pq;
	visit[s]=1;
	for (j=head[s];j!=-1;j=edge[j].pre)
		if (j%2==q) pq.push(node(j,edge[j].dist));
	dist[s][q]=0;
	for (int k=1;k<n;k++) {
		while (!pq.empty()) if (visit[edge[pq.top().id].to]) pq.pop(); else break;
		if (pq.empty()) break;
		i=pq.top().id;
		int to=edge[i].to;
		if (visit[to]) continue;
		visit[to]=1;
		dist[to][q]=pq.top().dist;
		pq.pop();
		for (j=head[to];j!=-1;j=edge[j].pre)
			if (!visit[edge[j].to]&&j%2==q)
				pq.push(node(j,dist[to][q]+edge[j].dist));
	}
	return dist[t][q];
}

int dfn[maxn],low[maxn],color[maxn];
bool inst[maxn],use[maxn],bri[maxn];
stack<int> st;
int cnum;


void tarjan(int now, int fa, int u)
{
	dfn[now] = low[now] = ++num;
	for (int i = head[now]; i != -1; i = edge[i].pre) {
		int from = edge[i].from, to = edge[i].to;
		if (i % 2) continue;
		if (dist[from][0] + dist[to][1] + edge[i].dist != u) continue;
		if (!dfn[to])
		{
			tarjan(to, now, u);
			low[now] = min(low[now], low[to]);
			if (low[to] >= dfn[now])
				bri[i / 2 + 1] = 1;
		}
		else if (dfn[to] < dfn[now])
		{
			low[now] = min(low[now], dfn[to]);
		}
	}
}


int main() {
	int n,m,i;
	num=0;memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		scanf("%d%d%lld",&x[i],&y[i],&z[i]);
		addedge(x[i],y[i],z[i]);
	}
	meminf(dist);
	ll w=dij(n,1,2,0);
	dij(n,2,1,1);
	mem0(dfn); mem0(low); mem0(color); mem0(inst); num = cnum = 0; mem0(use); mem0(bri);
	for (i=1;i<=n;i++)
		if (!color[i]) tarjan(i,0,w);
	for (i=1;i<=m;i++){
		ll sum=dist[x[i]][1]+dist[y[i]][0]+z[i];
		if (sum<w) printf("HAPPY\n"); else
			if (sum>w&&(bri[i]&&dist[x[i]][0]+dist[y[i]][1]+z[i]==w)) printf("SAD\n"); else printf("SOSO\n");
	}
//	system("pause");
	return 0;
}
