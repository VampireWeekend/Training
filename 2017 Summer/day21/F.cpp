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
const int maxn=2505,maxk=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int head[maxn],dist[maxn],current[maxn];
char s[55][55];
int num;

struct Edge {
	int from,to,flow,pre;
};
Edge edge[maxk];

void addedge(int from,int to,int flow) {
	edge[num]=(Edge){from,to,flow,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,0,head[to]};
	head[to]=num++;
}

bool bfs (int n) {
	queue<int> q;
	q.push(0);
	memset(dist,-1,sizeof(dist));
	dist[0]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[to]==-1&&edge[i].flow>0) {
				dist[to]=dist[now]+1;
				q.push(to);
			}
		}
	}
	return dist[n]!=-1;
}

int dfs(int now,int flow,int n) {
	int f;
	if (now==n) return flow;
	for (int i=current[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		current[now]=i;
		if (dist[now]+1==dist[to]&&edge[i].flow>0&&
		(f=dfs(to,min(flow,edge[i].flow),n))) {
			edge[i].flow-=f;
			edge[i^1].flow+=f;
			return f;
		}
	}
	return 0;
}

int dinic(int n) {
	int sum=0,f;
	while (bfs(n)) {
		memcpy(current,head,sizeof(head));
		while (f=dfs(0,inf,n)) sum+=f;
	}
	return sum;
}

int main() {
	memset(head,-1,sizeof(head));
	num=0;
	int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	int n,m,a,b,i,j,k;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for (j=1;j<=m;j++) {
			if (s[i][j]=='.') addedge(0,(i-1)*n+j,b);
			    else addedge((i-1)*n+j,n*m+1,b);
		}
	}
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			for (k=0;k<4;k++) {
				int x=i+dir[k][0],y=j+dir[k][1];
				if (x>0&&x<=n&&y>0&&y<=m) {
					addedge((i-1)*n+j,(x-1)*n+y,a);
				}
			}
		}
	}
	int ans=dinic(m*n+1);
	printf("%d\n",ans);
	return 0;
}

