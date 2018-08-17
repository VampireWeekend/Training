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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=500005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
bool vis[100005];
int dist[100005];
int n,m,s,t;
ll ans=0;
int nedge=-1,p[maxn],c[maxn],cc[maxn],nex[maxn],head[100005];
int C[50005],D[50005],M[50005],P[50005],e[50005],R[50005],E[50005];
inline void addedge(int x,int y,int z,int zz){
    p[++nedge]=y;c[nedge]=z;cc[nedge]=zz;nex[nedge]=head[x];head[x]=nedge;
}
inline bool spfa(int s,int t){
    for(int i=0;i<=n;i++)dist[i]=1e9,vis[i]=0;
	dist[t]=0;vis[t]=1;
    deque<int>q;q.push_back(t);
    while(!q.empty()){
        int now=q.front();q.pop_front();
        for(int k=head[now];k>-1;k=nex[k])if(c[k^1]&&dist[p[k]]>dist[now]-cc[k]){
            dist[p[k]]=dist[now]-cc[k];
            if(!vis[p[k]]){
                vis[p[k]]=1;
                if(!q.empty()&&dist[p[k]]<dist[q.front()])q.push_front(p[k]);else q.push_back(p[k]);
            }
        }
        vis[now]=0;
    }
    return dist[s]<1e9;
}
inline int dfs(int x,int low){
    if(x==t){vis[t]=1;return low;}
    int used=0,a;vis[x]=1;
    for(int k=head[x];k>-1;k=nex[k])if(!vis[p[k]]&&c[k]&&dist[x]-cc[k]==dist[p[k]]){
        a=dfs(p[k],min(c[k],low-used));
        if(a)ans+=(ll)a*(ll)cc[k],c[k]-=a,c[k^1]+=a,used+=a;
        if(used==low)break;
    }
    return used;
}
inline int costflow(){
    int flow=0;
    while(spfa(s,t)){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof vis);
            flow+=dfs(s,1e9);
        }
    }
    return flow;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		scanf("%d",&n);
		s=0;t=n*2+1;
		ans=0;
		for (int i=0;i<=n*2+1;i++) {
			nex[i]=-1;head[i]=-1;
		}
		nedge=-1;
		int sum=0;
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d%d",&C[i],&D[i],&M[i],&P[i]);
			sum+=D[i];
			addedge(0,i,inf,C[i]);addedge(i,0,0,-C[i]);
			addedge(i,i+n,P[i],M[i]);addedge(i+n,i,0,-M[i]);
			addedge(n+i,2*n+1,D[i],0);addedge(2*n+1,n+i,0,0);
		}
		for (int i=1;i<n;i++) {
			scanf("%d%d%d",&e[i],&R[i],&E[i]);
			addedge(i,i+1,inf,R[i]);addedge(i+1,i,0,-R[i]);
			addedge(n+i,n+i+1,e[i],E[i]);addedge(n+i+1,n+i,0,-E[i]);
		}
		n=2*n+1;
		int maxflow=costflow();
		if (maxflow==sum) {
			printf("%lld\n",ans);
		} else {
			printf("%d\n",-1);
		}
	}
	return 0;
}