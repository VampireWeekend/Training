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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int l[maxn],r[maxn],q[maxn],f[maxn];
bool vis[maxn],z[maxn];
pp b[maxn];
set<pp> s[maxn];
vector<int> v[maxn],vi[maxn],v1[maxn];
int n,num,cnt,c;

struct node{
	int p,r,c;
};
node a[maxn];

int findl(int pos) {
	int l=1,r=n,mid,ans=-1;
	while (l<=r) {
		mid=(l+r)/2;
		if (b[mid].first<pos) l=mid+1; else ans=mid,r=mid-1;
	}
	return ans;
}
int findr(int pos) {
	int l=1,r=n,mid,ans=-1;
	while (l<=r) {
		mid=(l+r)/2;
		if (b[mid].first>pos) r=mid-1; else ans=mid,l=mid+1;
	}
	return ans;
}

void addedge(int x,int y) {
	v[x].pb(y);
	v1[y].pb(x);
}

void newedge(int x,int y) {
	vi[x].pb(y);
//	cout << x << ' ' << y << endl;
}

int build(int lc,int rc) {
	if (lc==rc) {
		return b[lc].second;
	}
	int now=++num;
	l[now]=build(lc,(lc+rc)/2);
	r[now]=build((lc+rc)/2+1,rc);
	addedge(now,l[now]);
	addedge(now,r[now]);
	return now;
}

void buildedge(int now,int lc,int rc,int f,int nl,int nr) {
	if (nl>=lc&&rc>=nr) {
		addedge(f,now);
		return;
	}
	int mid=(nl+nr)/2;
	if (lc<=mid) buildedge(l[now],lc,rc,f,nl,mid);
	if (rc>mid) buildedge(r[now],lc,rc,f,mid+1,nr);
}

void dfs1(int now) {
	vis[now]=1;
	int size=v[now].size();
	for (int i=0;i<size;i++) {
		if (!vis[v[now][i]]) dfs1(v[now][i]);
	}
	q[++cnt]=now;
}

void dfs2(int now) {
	vis[now]=0;f[now]=c;
	int size=v1[now].size();
	for (int i=0;i<size;i++) {
		if (vis[v1[now][i]]) dfs2(v1[now][i]);
	}
}

void dfs3(int now) {
	z[now]=1;
	int size=vi[now].size();
	for (int i=0;i<size;i++) {
		if (!z[vi[now][i]]) dfs3(vi[now][i]);
	}
}

int main() {
	int qn,i,j;
	scanf("%d%d",&n,&qn);
	num=n;
	for (i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i].p,&a[i].r,&a[i].c);
		b[i]=pp(a[i].p,i);
	}
	sort(b+1,b+n+1);
	int root=build(1,n);
	for (i=1;i<=n;i++) {
		int ll=findl(a[i].p-a[i].r);
		int rr=findr(a[i].p+a[i].r);
		buildedge(root,ll,rr,i,1,n);
	}
	cnt=c=0;
	for (i=1;i<=num;i++) 
		if (!vis[i]) dfs1(i);
	for (i=num;i;i--) 
		if (vis[q[i]]) c++,dfs2(q[i]);
	for (i=1;i<=num;i++) {
		int size=v[i].size();
		for (j=0;j<size;j++) {
			if (f[i]!=f[v[i][j]]) newedge(f[i],f[v[i][j]]);
		}
	}
	for (i=1;i<=n;i++) {
		if (!vis[f[i]]){
			vis[f[i]]=1;
			int size=vi[f[i]].size();
			for (j=0;j<size;j++) {
				if (!z[vi[f[i]][j]]) dfs3(vi[f[i]][j]);
			}
		}
	}
	for (i=1;i<=n;i++) 
		if (!z[f[i]]) s[f[i]].insert(pp(a[i].c,i));
	ll ans=0;
	for (i=1;i<=c;i++) 
		if (!z[i]&&!s[i].empty()) ans+=(ll)s[i].begin()->first;
	int x,y;
	for (i=1;i<=qn;i++) {
		scanf("%d%d",&x,&y);
		if (z[f[x]]) {
			printf("%lld\n",ans);
			continue;
		}
		ans-=(ll)s[f[x]].begin()->first;
		s[f[x]].erase(pp(a[x].c,x));
		a[x].c=y;
		s[f[x]].insert(pp(y,x));
		ans+=(ll)s[f[x]].begin()->first;
		printf("%lld\n",ans);
	}
	return 0;
}
