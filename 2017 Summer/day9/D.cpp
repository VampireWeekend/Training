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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int dist[maxn],visit[maxn],head[maxn],path[maxn];
int current[maxn];
int num;

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

void bfs() {
	queue<int> q;
	q.push(1);
	mem0(visit);
	visit[1]=1;
	dist[1]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop(); 
		for (int i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (!visit[to]) {
				q.push(to);
				dist[to]=dist[now]+1;
				visit[to]=1;
			}
		}
	}
}

bool FindPath() {
	int i,step,k;
	step=0;
	k=1;
	path[0]=1;
	memcpy(current,head,sizeof(head));
	while (1) {
		int p=0;
		for (i=current[k];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			current[k]=edge[i].pre;
			if (dist[to]==dist[k]+1){
				k=to;
				p=1;
				path[++step]=to;
				break;
			}
		}
		if (p==0) 
				for (i=dist[k]-2;i>=0;i-=2) {
					if (current[path[i]]!=-1) {
						k=path[i];
						step=i;
						p=1;
						break;
					}
				}
				if (p==0) {
					if (dist[k]%2) return true; else return false;
				}
	}
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int n,m,i,j,x,y;
    scanf("%d%d",&n,&m);
    num=0;
    memset(head,-1,sizeof(head));
    for (i=1;i<=m;i++) {
    	scanf("%d%d",&x,&y);
    	addedge(x,y);
    }
    bfs();
    mem0(visit);
    if (FindPath()) printf("Vladimir\n"); else printf("Nikolay\n");
	return 0;
}
