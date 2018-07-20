#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
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
const int maxn=25005,maxk=112505,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int num;
int head[maxn],dist[maxn],current[maxn],visit[maxn];
char mp[155][155];

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
	int cas,n,m,i,j,k;
	int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	scanf("%d",&cas);
	while (cas--) {
		num=0;
		scanf("%d%d",&n,&m);
		int final=n*m+1;
		memset(head,-1,sizeof(head));
		for (i=1;i<=n;i++) 
			scanf("%s",mp[i]+1);
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				int now=(i-1)*m+j;
				if (mp[i][j]=='.') {
					if (i==1||i==n||j==1||j==m) 
						addedge(0,now,(i==1)+(i==n)+(j==1)+(j==m));
					for (k=0;k<4;k++) {
						int nowx=i+dir[k][0],nowy=j+dir[k][1];
						if (nowx>0&&nowx<=n&&nowy>0&&nowy<=m)
						if (mp[nowx][nowy]!='X') 
							addedge(now,(nowx-1)*m+nowy,1);
					}
				}
				if (mp[i][j]=='D') {
					if (i==1||i==n||j==1||j==m) 
						addedge(0,final,(i==1)+(i==n)+(j==1)+(j==m));
					addedge(now,final,4-((i==1)+(i==n)+(j==1)+(j==m)));
					for (k=0;k<4;k++) {
						int nowx=i+dir[k][0],nowy=j+dir[k][1];
						if (nowx>0&&nowx<=n&&nowy>0&&nowy<=m)
						if (mp[nowx][nowy]!='X') 
							addedge(now,(nowx-1)*m+nowy,1);
					}
				}
			}
		}
/*		for (i=0;i<num;i++) {
			cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].flow << endl;
		}*/
		int ans=dinic(final);
		printf("%d\n",ans); 
	}
	return 0;
}
