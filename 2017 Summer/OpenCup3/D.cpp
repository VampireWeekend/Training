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
int du[maxn],head[maxn],size[maxn],col[maxn];
bool visit[maxn],mark[maxn];
int num,cnum;

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

void dfs(int now) {
	visit[now]=1;
	size[cnum]++;
	col[now]=cnum;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) dfs(to);
	}
}

int main() {
	int n,m,d,i,j,x,y;
	scanf("%d%d%d",&n,&m,&d);
	memset(head,-1,sizeof(head));
	mem0(du);
	num=cnum=0;
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
		du[x]++;du[y]++;
	}
	mem0(visit);mem0(mark);
	queue<int> q;
	for (i=1;i<=n;i++) {
		if (du[i]<d) q.push(i),mark[i]=visit[i]=1;
	}
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			du[to]--;
			if (du[to]<d&&!visit[to]) q.push(to),mark[to]=visit[to]=1;
		}
	}
	for (i=1;i<=n;i++) {
		if (!visit[i]) {
			cnum++;size[cnum]=0;
			dfs(i);
		}
	}
	if (cnum==0) {
		printf("NIE\n");
		return 0;
	}
	int ans=1,tot=size[1];
	for (i=2;i<=cnum;i++) {
		if (size[i]>tot) tot=size[i],ans=i;
	}
	printf("%d\n",tot);
	for (i=1;i<=n;i++) {
    	if (!mark[i]&&col[i]==ans) printf("%d ",i);
   	}
	return 0;
}
