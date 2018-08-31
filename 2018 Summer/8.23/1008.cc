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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn],in[maxn],out[maxn],a[maxn],lc[maxn],rc[maxn];
long double len[maxn];
ll w[maxn],f[maxn];
bool visit[maxn];
int num=1,dfn=0;

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
	a[++dfn]=now;
	in[now]=out[now]=dfn;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to,step+1);
			out[now]=dfn;
			a[dfn]=now;
		}
	}
}

int lowbit(int a) {
	return (a&(-a));
}

ll getsum(int tt) {
	ll sum=0;
	for (int t=tt;t;t-=lowbit(t)) {
		sum+=f[t];
	}
	return sum;
}

void update(int tt,ll c,int n) {
	int t=tt;
	for (int t=tt;t<=n;t+=lowbit(t))
		f[t]+=c;
}

int main() {
    int n,k,l,r;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n+1;i++) {
        scanf("%lld",&w[i]);
    }
    num=0;memset(head,-1,sizeof(head));
    for (int i=1;i<=n;i++) {
        scanf("%Lf%d%d",&len[i],&l,&r);
        if (l>0) addedge(i,l),lc[i]=l; else addedge(i,-l+n),lc[i]=n-l;
        if (r>0) addedge(i,r),rc[i]=r; else addedge(i,-r+n),rc[i]=n-r;
    }
    dfs(1,1);
    for (int i=n+1;i<=2*n+1;i++) {
        update(in[i],w[i-n],n*2+1);
    }
/*	for (int i=1;i<=2*n+1;i++) {
		cout << lc[i]  << ' ' << rc[i] << endl;
	}*/
	ll W;
    for (int i=1;i<=k;i++) {
        scanf("%d",&l);
        if (l==1) {
            scanf("%d%lld",&r,&W);
            update(in[r+n],W-w[r],n*2+1);
            w[r]=W;
        } else {
            scanf("%d",&r);
            ll rsum=getsum(out[rc[r]])-getsum(in[rc[r]]-1),lsum=getsum(out[lc[r]])-getsum(in[lc[r]]-1);
            ld ans=len[r]*(ld)rsum/(ld)(lsum+rsum);
            printf("%.20Lf\n",ans);
        }
    }
	return 0;
}
