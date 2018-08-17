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
int sum[maxn],mx[maxn],a[maxn];
int l[maxn],r[maxn],pans[maxn],be[maxn];
int num=0;

struct Tree {
	int lc,rc,l,r,max,min;
};
Tree tree[4*maxn];

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		tree[now].max=max(tree[tree[now].lc].max,tree[tree[now].rc].max);
		tree[now].min=min(tree[tree[now].lc].min,tree[tree[now].rc].min);
	} else tree[now].max=tree[now].min=a[l];
}

int findmax (int now,int l,int r,int val) {
	if (r>l) return inf;
	if (tree[now].l>=l&&tree[now].r<=r&&tree[now].min>val) {
		return tree[now].l;
	} else {
		int ans=0;
		if (l<=(tree[now].l+tree[now].r)/2&&tree[tree[now].lc].max>val) {
			ans=findmax(tree[now].lc,l,r,val);
			if (ans!=inf) return ans;
		}
		if (r>(tree[now].l+tree[now].r)/2&&tree[tree[now].rc].max>val) {
			ans=findmax(tree[now].rc,l,r,val);
			if (ans!=inf) return ans;
		}
		return inf;
	}
}

int main() {
	int cas;
	scanf("%d",&cas);
	a[0]=pans[0]=0;
	while (cas--) {
		int n,m,p,q;
		scanf("%d%d",&n,&m);
		mx[0]=0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);mx[i]=max(mx[i-1],a[i]);
		}
		num=1;
		build(1,1,n);
		int size=sqrt(n),knum=n/size;
		if (n%size) knum++;
		for (int i=1;i<=knum;i++) {
			l[i]=(i-1)*size+1;
			if (i==knum) r[i]=n; else r[i]=i*size;
			int last=a[l[i]-1],cnt=0;
			for (int j=l[i];j<=r[i];j++) {
				if (a[j]>last) last=a[j],cnt++;
				be[j]=i;
			}
			pans[i]=cnt+pans[i-1];
		}
		sum[0]=0;sum[1]=1;int last=a[1];
		for (int i=2;i<=n;i++) {
			sum[i]=0;
			if (a[i]>last) last=a[i],sum[i]++;
			sum[i]+=sum[i-1];
		}
		int ans;
		for (int i=1;i<=m;i++) {
			scanf("%d%d",&p,&q);
			if (q<=mx[p-1]) {
				if (a[p]<=q) printf("%d\n",sum[n]); else {
					int pos=findmax(1,p+1,n,mx[p-1]);
					if (pos==inf||p==n) {
						printf("%d\n",sum[p-1]);
					} else {
						int cnt=1,last=a[pos];
						for (int j=pos+1;j<=r[be[pos]];j++) {
							if (a[j]>last) last=a[j],cnt++;
						}
						int p2=findmax(1,p+1,n,mx[p-1]);
						ans=sum[p-1]+cnt+pans[knum]-pans[be[pos]];
						printf("%d\n",ans);
					}
				}
			} else {
				int pos=findmax(1,p+1,n,q);
				if (pos==inf||p==n) ans=sum[p-1]+1; else {
					ans=sum[p-1]+2+sum[n]-sum[pos];
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
