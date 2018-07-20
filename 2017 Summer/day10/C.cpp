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
const int maxn=10005,maxk=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int head[maxn],dist[maxn],visit[maxn];
ll path[maxn];
int num;

struct Edge {
	int from,to,pre,dist;
};
Edge edge[maxk];

void addedge (int from,int to,int dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
}

struct node {
	int id,dist;
	node(int id,int dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};

void dijstra (int s,int t) {
	meminf(dist);
	mem0(path);
	mem0(visit);
	dist[s]=0;
	visit[s]=1;
	path[s]=1;
	int i;
	priority_queue<node> pq;
	for (i=head[s];i!=-1;i=edge[i].pre) {
		pq.push(node(i,edge[i].dist));
	}
	while (!pq.empty()) {
		int now=pq.top().id;
		pq.pop();
		int to=edge[now].to;
		if (dist[edge[now].from]+edge[now].dist<dist[to]) {
			dist[to]=dist[edge[now].from]+edge[now].dist;
			path[to]=path[edge[now].from];
			if (!visit[to]) {
				for (i=head[to];i!=-1;i=edge[i].pre) {
			    	pq.push(node(i,edge[i].dist+dist[to]));
		    	}
		    	visit[to]=1;
			}
		} else if (dist[edge[now].from]+edge[now].dist==dist[to]) {
			path[to]+=path[edge[now].from];
		}
	}
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,m,i,x,y,j,s,t;
	num=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&t);
		addedge(x,y,t);
	}
	scanf("%d%d",&s,&t);
	dijstra(s,t);
	printf("%d\n",path[t]);
	return 0;
}
