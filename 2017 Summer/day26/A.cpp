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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int head[maxn],match[maxn];
int num,ans;
bool visit[maxn],mark[maxn];

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

bool dfs(int now) {
	visit[now]=1;
	match[now]=0;
	if (mark[now]) match[now]++;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			match[now]+=dfs(to);
		}
	}
	if (match[now]==1) return true;
	if (match[now]==0) return false;
	ans++;
	return false;
}

int main() {
	freopen("athletic.in","r",stdin);	
	freopen("athletic.out","w",stdout);	
	num=0;mem0(visit);
	memset(head,-1,sizeof(head));
	ans=0;
	int n,m,i,x,y;
	scanf("%d",&n);
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	scanf("%d",&m);
	mem0(mark);
	for (i=1;i<=m;i++) {
		scanf("%d",&x);
		mark[x]=1;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}

