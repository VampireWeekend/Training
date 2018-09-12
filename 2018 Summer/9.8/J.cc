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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn],dep[maxn],in[maxn],out[maxn];
ll f[maxn],cnt[maxn],sz[maxn];
bool visit[maxn];
vector<int> v[maxn],l;
int size,num=0,dfn=0;

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

void dfs(int now,int step) {
	visit[now]=1;
	dep[now]=step;
	in[now]=out[now]=++dfn;
	v[step].pb(dfn);
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to,step+1);
			out[now]=dfn;
		}
	}
}

int lowbit(int a) {
    return (a&(-a));
}

ll getsum(int tt) {
    ll sum=0;
    for (int t=tt;t;t-=lowbit(t))
        sum+=f[t];
    return sum;
}

void update(int tt,ll c,int n) {
    int t=tt;
    for (int t=tt;t<=n;t+=lowbit(t))
        f[t]+=c;
}

int main() {
	int n,q;
	ll x,y,z;
	scanf("%d%d",&n,&q);
	size=sqrt(n);
	num=0;memset(head,-1,sizeof(head));
	for (int i=1;i<n;i++) {
		scanf("%lld%lld",&x,&y);
		addedge(x,y);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) {
		sz[i]=v[i].size();
		if (sz[i]>=size) l.pb(i);
	}
	int m=l.size();
	for (int T=1;T<=q;T++) {
		scanf("%lld",&x);
		if (x==1) {
			scanf("%lld%lld",&x,&y);
			if (sz[x]>=size) {
				cnt[x]+=y;
			} else {
				for (int i=0;i<sz[x];i++) {
					update(v[x][i],y,n);
				}
			}
		} else {
			scanf("%lld",&x);
			ll ans=getsum(out[x])-getsum(in[x]-1);
			for (int i=0;i<m;i++) {
				if (l[i]>=dep[x]) {
					int L,R;
					R=lower_bound(v[l[i]].begin(),v[l[i]].end(),out[x])-v[l[i]].begin();
					if (v[l[i]][R]==out[x]) R++;
					L=lower_bound(v[l[i]].begin(),v[l[i]].end(),in[x])-v[l[i]].begin();
					assert(R>=L);
					ans+=cnt[l[i]]*(ll)(R-L);
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
