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
const int maxn=1005,maxk=10005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn],dist[maxn],path[maxn],rflow[maxn];
int x[maxn],y[maxn],a[maxn],w[maxn];
bool inque[maxn];
int num=0;

struct Edge {
    int from,to,cost,flow,pre;
};
Edge edge[maxk*2];

void addedge(int s,int t,int cost,int flow) {
    edge[num]=(Edge){s,t,cost,flow,head[s]};
    head[s]=num++;
    edge[num]=(Edge){t,s,-cost,0,head[t]};
    head[t]=num++;
}

int spfa(int s,int t) {
    mem0(inque);meminf(dist);
    memset(path,-1,sizeof(path));
    memset(rflow,-1,sizeof(rflow));
    queue<int> q;
    q.push(s);
    inque[s]=1;
    int i;
    dist[s]=0;
    rflow[s]=inf;
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        inque[now]=0;
        for (i=head[now];i!=-1;i=edge[i].pre) {
            int to=edge[i].to;
            if (edge[i].flow>0&&dist[now]+edge[i].cost<dist[to]) {
                dist[to]=dist[now]+edge[i].cost;
                path[to]=i;
                rflow[to]=min(rflow[now],edge[i].flow);
                if (!inque[to]) {
                    inque[to]=1;
                    q.push(to);
                }
            }
        }
    }
    if (dist[t]==inf) return 0; else return dist[t];
}

int mincostmaxflow(int s,int t) {
    int f,sum=0,now;
    while (f=spfa(s,t)) {
        now=path[t];
        while (now!=-1) {
//          int i=now;
//          cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;
            edge[now].flow-=rflow[t];
            edge[now^1].flow+=rflow[t];
            now=path[edge[now].from];
//          cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;
        }
        sum+=f*rflow[t];
    }
    return sum;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		num=0;memset(head,-1,sizeof(head));
		int n,m,k;
		scanf("%d%d%d",&n,&k,&m);
		for (int i=1;i<=m;i++) {
			scanf("%d%d%d",&x[i],&y[i],&w[i]);
			a[i*2-1]=x[i];a[i*2]=y[i];
		}
		sort(a+1,a+m*2+1);
		int nn=unique(a+1,a+m*2+1)-a;
		int s=0,t=nn+2;
		for (int i=1;i<=m;i++) {
			x[i]=lower_bound(a+1,a+nn+1,x[i])-a;
			y[i]=lower_bound(a+1,a+nn+1,y[i])-a;
			addedge(x[i],y[i]+1,-w[i],1);
		}
		for (int i=1;i<=nn+2;i++) addedge(i-1,i,0,k);
		int ans=mincostmaxflow(s,t);
		ans=-ans;
		printf("%d\n",ans);
	}
	return 0;
}
