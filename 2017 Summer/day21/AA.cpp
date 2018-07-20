#include <cstdio>
#include <iostream>
#include <string.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
const int maxn=5005,maxk=20005;
int head[maxn],headi[maxn];
bool visit[maxn];
int num,cnt,inum;

struct Edge {
	int from,to,pre;
};
Edge edge[maxk],edgei[maxk];

void addedge(int from,int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edgei[inum]=(Edge){to,from,headi[to]};
	headi[to]=inum++;
}

void dfs(int now) {
	cnt++;
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		if (!visit[edge[i].to]) dfs(edge[i].to);
	}
}

void dfs2(int now) {
	cnt++;
	visit[now]=1;
	for (int i=headi[now];i!=-1;i=edgei[i].pre) {
		if (!visit[edgei[i].to]) dfs2(edgei[i].to);
	}
}

int main() {
	int a,b,n,m,i,j,x,y,ansa,ansb;
	scanf("%d%d%d%d",&a,&b,&n,&m);
	memset(head,-1,sizeof(head));
	memset(headi,-1,sizeof(headi));
	num=0;
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		x++;y++;
		addedge(x,y);
	}
	ansa=ansb=0;
	for (i=1;i<=n;i++) {
		cnt=0;
		mem0(visit);
		dfs(i);
		cnt=n-cnt+1;
		if (cnt<=a) ansa++;
		if (cnt<=b) ansb++;
	} 
	cout << ansa << endl;
	cout << ansb << endl;
	int ans=0;
	for (i=1;i<=n;i++) {
		cnt=0;
		mem0(visit);
		dfs2(i);
		if (cnt>b) ans++;
	}
	cout << ans << endl;
	return 0;
}

