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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int x[maxn],y[maxn],head[maxn],dep[maxn],path[maxn];
bool visit[maxn],del[maxn],rt[maxn];
int num=0;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
//	cout << num-1 << ' ' << from << ' ' << to << endl;
}

void dfs(int now,int depth,int low) {
	path[depth]=now;
	visit[now]=1;dep[now]=depth;
	int rem=-1,mylow=low,po;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		if (rt[edge[i].to]) {
			rem=i;break; 
		} 
	}
	if (rem!=-1) {
		for (int i=low+1;i<=depth;i++) {
			rt[path[i]]=1;
		}
		del[rem]=1;
		mylow=depth;
	}
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			del[i]=1;
			dfs(to,depth+1,mylow);
			if (rt[now]) mylow=depth;
		}
	}
	if (rem==-1) {
		
	}
}

int main() {
	int cas;
	scanf("%d",&cas);
	memset(head,-1,sizeof(head));
	mem0(visit);mem0(del);mem0(rt);
	while (cas--) {
		int n,m;
		scanf("%d%d",&n,&m);
		num=1;
		for (int i=1;i<=m;i++) {
			scanf("%d%d",&x[i],&y[i]);
			addedge(x[i],y[i]);
			del[i]=0;
		}
		rt[1]=1;
		dfs(1,1,1);
		int cnt=0;
		for (int i=1;i<=n;i++) {
			assert(rt[i]);
		}
		for (int i=1;i<=m;i++) {
			if (!del[i]) {
				printf("%d %d\n",x[i],y[i]);
				cnt++;
			}
			if (m-cnt==2*n) break;
		}
		assert(m-cnt==2*n);
		for (int i=1;i<=n;i++) head[i]=-1,visit[i]=rt[i]=0;
	}
	return 0;
}
