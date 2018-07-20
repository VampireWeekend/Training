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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=600005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=998244353;   
const ld pi=acos(-1.0L);
int d[maxn],head[maxn];
bool va[maxn];
int num;
ll s1,s0;

struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,ll dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

void dfs(int now,int p) {
	ll ans=0;
	va[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		if (edge[i].dist==0) continue;
		if (p==0) {
			s0*=edge[i].dist;s0%=mod; 
		} else {
			s1*=edge[i].dist;s1%=mod; 
		}
		edge[i].dist=edge[i^1].dist=0;
		dfs(edge[i].to,p^1);
		return;
	}
}

int main() {
	int cas;
	scanf("%d",&cas);
while (cas--) {
    int i,j,k,y;
	ll n,e,tot=1,m;
	scanf("%lld",&n);
	mem0(d);
	num=0;
	memset(head,-1,sizeof(head));
	for (i=1;i<=n;i++) {
		scanf("%d%lld",&y,&e);
		d[i]=2;d[y+n]++;
		addedge(i,y+n,e);
		scanf("%d%lld",&y,&e);
		d[y+n]++;
		addedge(i,y+n,e);
	}
	queue<int> q;
	mem0(va);
	m=0;
	for (i=n+1;i<=2*n;i++) {
		if (d[i]==1) {
			q.push(i);
			va[i]=1;
			for (j=head[i];j!=-1;j=edge[j].pre) {
				if (!va[edge[j].to]) q.push(edge[j].to);
				va[edge[j].to]=1;
				tot*=edge[j].dist;
				tot%=mod;
				edge[j].dist=edge[j^1].dist=0;
			}
		}
	}
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (j=head[now];j!=-1;j=edge[j].pre) {
			if (edge[j].dist==0) continue;
			edge[j].dist=edge[j^1].dist=0;
			int to=edge[j].to;
			d[to]--;
			if (d[to]==1&&!va[to]) {
				q.push(to);
				va[to]=1;
				for (k=head[to];k!=-1;k=edge[k].pre) {
					if (edge[k].dist==0) continue;
					if (!va[edge[k].to]) q.push(edge[k].to);
					va[edge[k].to]=1;
					tot*=edge[k].dist;
					tot%=mod;
					edge[k].dist=edge[k^1].dist=0;
				}
			}
		}
	}
	for (i=1;i<=n;i++) {
		if (!va[i]) {
			s1=s0=1;
			dfs(i,0);
			tot*=s1+s0;
			tot%=mod;
		}
	}
	printf("%lld\n",tot);
}
	return 0;
}
