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
const int maxn=505,maxk=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
bool vis[maxn];
int dist[maxn];
int n,s,t;
ll ans=0;
int nedge=-1,p[maxk*2],c[maxk*2],cc[maxk*2],nex[maxk*2],head[maxn];
ll C[maxn][maxn];
inline void addedge(int x,int y,int z,ll zz){
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
	int n,k,T;
	scanf("%d%d%d",&n,&k,&T);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=k+1;j++) {
			scanf("%lld",&C[i][j]);
		}
	}
	ll mx=-llinf;
	vector<int> chk;
	for (int Q=1;Q<=n;Q++) {
		s=0;t=505;
		ans=0;
		memset(head,-1,sizeof(head));
		memset(nex,-1,sizeof(nex));
		nedge=-1;
		for (int i = 1; i <= n; i++)
        {
            addedge(s, i, 1, 0);addedge(i,s,0,0);
            for (int j = 1; j <= k + 1; j++)
            {
                addedge(i, 128 + j, 1, C[i][j]);addedge( 128 + j, i,0, -C[i][j]);
            }
        }
        for (int j = 1; j <= k; j++)
        {
            if (j == T) addedge(128 + j, t, Q, 0),addedge(t,128 + j, 0, 0);
            else addedge(128 + j, t, Q - 1, 0),addedge(t,128 + j,  0, 0);
        }
        addedge(128 + k + 1, t, inf, 0);addedge(t,128 + k + 1,  0, 0);
        int flow=costflow();
        if (ans<mx)
        {
            mx=ans;
            chk.clear();
            for (int i = 1; i <= n; i++)
            {
                int ch = 0;
                for (int e = head[i]; e != -1; e =nex[e])
                    if (p[e] > 128 && c[e] == 1)
                    {
                        ch = p[e] - 128;
                        break;
                    }
                chk.pb(ch);
            }
        }
	}
	printf("%lld\n",mx);
	int sz=chk.size();
	for (int i=0;i<sz;i++) {
		printf("%d ",chk[i]);
	}
}
