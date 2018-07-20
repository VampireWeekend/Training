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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
int head[maxn],num,son[maxn],depth[maxn],sum[maxn];
ll tot;
bool visit[maxn];

struct Edge{
	int to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){from,head[to]};
	head[to]=num++;
}

int dfs(int now,int step) {
	visit[now]=1;
	son[now]=1;
	depth[now]=step;
	tot+=step;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) son[now]+=dfs(to,step+1);
	}
	return son[now];
}

ll solve(int now) {
	visit[now]=1;
	
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j,x,y;
		ll ans;
		num=0;
		memset(head,-1,sizeof(head));
		scanf("%d",&n);
		for (i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		mem0(visit);
		tot=0;
		n=dfs(1,0);
		mem0(visit);
		ans=tot-solve(1);
		printf("%lld\n",ans);
	}
	return 0;
}
