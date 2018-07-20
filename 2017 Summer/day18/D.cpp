#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],visit[maxn];
ll t[maxn];
int m,num;

struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,int dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

void dfs(int now,ll tim) {
	visit[now]=1;
	ll e=inf;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		if (!visit[edge[i].to]) e=min(e,edge[i].dist);
	}
	if (e==inf) {
		t[++m]=tim;
		return;
	}
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) dfs(to,tim+(edge[i].dist-e)*2+e);
	}
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		memset(head,-1,sizeof(head));
		int n,q,x,y,i;
		ll p;
		scanf("%d",&n);
		num=m=0;
		for (i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			addedge(i+1,x,y);
		}
		mem0(visit);
		dfs(1,0);
		sort(t+1,t+m+1);
		scanf("%d",&q);
		for (i=1;i<=q;i++) {
			scanf("%lld",&p);
			int pos=upper_bound(t+1,t+m+1,p)-t;
			printf("%d\n",pos-1); 
		}
	}
	return 0;
}

