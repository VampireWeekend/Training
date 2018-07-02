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
const int maxn=1005,maxk=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn],dist[maxn],path[maxn],rflow[maxn];
bool inque[maxn];
vector<int> x[maxn],y[maxn];
int num=0; 

struct Edge {  
    int from,to,cost,flow,pre;  
};  
Edge edge[maxk*2];  
  
void addedge(int s,int t,int cost,int flow) {  
    edge[num]=(Edge){s,t,-cost,flow,head[s]};  
    head[s]=num++;  
    edge[num]=(Edge){t,s,cost,0,head[t]};  
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
    int f,sum=0,now,fsum=0;  
    while (f=spfa(s,t)) {  
        now=path[t];  
        while (now!=-1) {     
            edge[now].flow-=rflow[t];  
            edge[now^1].flow+=rflow[t];  
            now=path[edge[now].from];  
        }  
        sum+=f*rflow[t];  
		fsum+=rflow[t];
    }  
//	assert(fsum==t/2);
    return sum;  
}

int main() {
	int n,z;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		for (int j=0;j<4;j++) {
			scanf("%d",&z);
			x[i].pb(z);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<4;j++) {
			scanf("%d",&z);
			y[i].pb(z);
		}
	}
	num=0;memset(head,-1,sizeof(head));
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			int cnt=0;
			for (int k=0;k<4;k++) {
				for (int l=0;l<4;l++) {
					if (x[i][k]==y[j][l]) cnt++;
				}
			}
			assert(cnt<=4);
			addedge(i,j+n,cnt,1);
		}
	}
	for (int j=1;j<=n;j++) {
		addedge(j+n,2*n+1,0,1);
	}
	for (int j=1;j<=n;j++) {
		addedge(0,j,0,1);
	}
	int ans=mincostmaxflow(0,2*n+1);
	ans=-ans;
	ans=4*n-ans;
	printf("%d\n",ans);
	return 0;
}
