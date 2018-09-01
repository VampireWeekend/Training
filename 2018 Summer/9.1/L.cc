#define SUBMIT
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
const int maxn=100005,maxk=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll dist[maxn],dp[maxn][11];
int head[maxn],kk,n,m;
bool visit[maxn][11];
int num=0;

struct Edge {
    int from,to,pre;
	ll dist;
};
Edge edge[maxk*2];

void addedge(int s,int t,ll dist) {
    edge[num]=(Edge){s,t,head[s],dist};
    head[s]=num++;
}

struct node {
	int id,cnt;ll dist;
	node(int id,int cnt,ll dist):id(id),cnt(cnt),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};
priority_queue<node> pq;

void dij(int s,int t) {
	int j,i;
	mem0(visit);
	priority_queue<node> pq;
	meminf(dist);dist[s]=0;meminf(dp);
    for (int i=0;i<=kk;i++) dp[s][i]=0,pq.push(node(s,i,0ll));
	while (!pq.empty()) {
//		if (pq.top().dist>ans) break;    可能优化
        int l=pq.top().cnt,from=pq.top().id;ll dist=pq.top().dist;
        if (visit[from][l]) {
            pq.pop();continue;
        }
        visit[from][l]=1;
        pq.pop();
        for (j=head[from];j!=-1;j=edge[j].pre) {
            int to=edge[j].to;
            if (l!=0) {
                dp[to][l-1]=min(dist,dp[to][l-1]);
                if (!visit[to][l-1]) {
                    pq.push(node(to,l-1,dp[to][l-1]));
                }
            }
            dp[to][l]=min(dp[to][l],dist+edge[j].dist);
            if (!visit[to][l]) {
                pq.push(node(to,l,dp[to][l]));
            }
        }
	}
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        num=0;memset(head,-1,sizeof(head));
        scanf("%d%d%d",&n,&m,&kk);
        int x,y;
        ll z;
        for (int i=1;i<=m;i++) {
            scanf("%d%d%lld",&x,&y,&z);
            addedge(x,y,z);
        }
        dij(1,n);
        ll ans=llinf;
/*        for (int i=1;i<=n;i++) {
            for (int j=0;j<=kk;j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }*/
        for (int i=0;i<=kk;i++) {
            ans=min(ans,dp[n][i]);
        }
        assert(ans!=llinf);
        printf("%lld\n",ans);
    }
	return 0;
}
