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
int head[maxn],down[maxn],visit[maxn],dist[maxn];
int num,p;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

void dfs(int now,int step) {
	visit[now]=1;
	down[now]=0;
	int m1,m2;
	m1=m2=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to,step+1);
			down[now]=max(down[now],down[to]+1);
			if (down[to]+1>m1) {
				m2=m1;m1=down[to]+1;
			} else if (down[to]+1>m2) {
				m2=down[to]+1;
			}
		}
	}
	p=max(p,m1+m2);
}

int main() {
	int n,k,i,j,x,y;
	scanf("%d%d",&n,&k);
	num=0;
	memset(head,-1,sizeof(head));
	for (i=1;i<=k;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	mem0(visit);
	int m=0;
	int ans=0;
	for (i=0;i<n;i++) {
		if (!visit[i]) {
			p=0;
			dfs(i,0);
			dist[++m]=p;
			ans=max(ans,p);
		}
	}
	sort(dist+1,dist+m+1);
	if (m>=2) ans=max(ans,(dist[m]+1)/2+(dist[m-1]+1)/2+1);
	if (m>=3) ans=max(ans,(dist[m-2]+1)/2+(dist[m-1]+1)/2+2);
	cout << ans;
	return 0;
}
