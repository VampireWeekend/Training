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
int head[maxn],dist[maxn];
int num,k,n,m;
bool inque[maxn];

struct Edge {
	int from,to,pre,dist,wis;
};
Edge edge[maxn*2];

void addedge (int from,int to,int dist,int wis) {
	edge[num]=(Edge){from,to,head[from],dist,wis};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist,wis};
	head[to]=num++;
}

bool find(int n,int maxd,int mwis) {
	queue<int> q;
	q.push(1);
	meminf(dist);
	mem0(inque);
	dist[1]=0;inque[1]=1;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[now]+edge[i].dist<dist[to]&&dist[now]+edge[i].dist<k&&edge[i].wis<=mwis) {
				dist[to]=dist[now]+edge[i].dist;
				if (to==n) return true;
				if (!inque[to]) {
					inque[to]=1;
					q.push(to);
				}
			}
		}
	}
	return false;
}

int solve(int n) {
	int l,r,mid,ans=-1;
	l=1;r=1e9;
	while (l<=r) {
		mid=(l+r)/2;
		if (find(n,k,mid)) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	return ans;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		num=0;
		scanf("%d%d%d",&n,&m,&k);
		int i,j,x,y,w,d;
		memset(head,-1,sizeof(head));
		for (i=1;i<=m;i++) {
			scanf("%d%d%d%d",&x,&y,&d,&w);
			addedge(x,y,d,w);
		}
		int ans=solve(n);
		printf("%d\n",ans);
	}
	return 0;
}

