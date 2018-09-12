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
int a[maxn],p[maxn],ans[maxn];
int num;

struct Tree {
	int lc,rc,l,r,max,min;
};
Tree tree[4*maxn];

void pushup(int now) {
	tree[now].max=max(tree[tree[now].lc].max,tree[tree[now].rc].max);
	tree[now].min=min(tree[tree[now].lc].min,tree[tree[now].rc].min);
}

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
		pushup(now);
	} else tree[now].max=tree[now].min=a[l];
}

void update (int now,int pos) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l==tree[now].r&&tree[now].l==pos) {
		tree[now].max=tree[now].min=inf;
	} else {
		if (pos<=(tree[now].l+tree[now].r)/2)
		    update(tree[now].lc,pos);
		if (pos>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,pos);
		pushup(now);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int findbig(int now,int l,int r,int val) {
	if (tree[now].l==tree[now].r) {
		return tree[now].l;
	} else {
		if (l<=(tree[now].l+tree[now].r)/2&&tree[tree[now].lc].min<=val)
		    return findbig(tree[now].lc,l,r,val);
		if (r>(tree[now].l+tree[now].r)/2&&tree[tree[now].rc].min<=val)
		    return findbig(tree[now].rc,l,r,val);
	}
}

int findmin (int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].min;
	} else {
		int ans=inf;
		if (l<=(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].rc,l,r));
		return ans;
	}
}

int main() {
	int n,m,low,q,x,k=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	num=1;
	build(1,1,n);
	int rem=0,cnt=0,last;
	while ((low=findmin(1,1,n))!=inf) {
		cnt+=(low-rem)/m;
		rem+=(low-rem)/m*m;
		if (rem<low) rem+=m,cnt++;
		int pos=findbig(1,1,n,rem);
		rem-=a[pos];
		update(1,pos);
		p[++k]=cnt;ans[k]=rem;
		if (pos==n) continue;
		last=pos;
		while ((low=findmin(1,last+1,n))<=rem) {
			int pos=findbig(1,last+1,n,rem);
			rem-=a[pos];
			update(1,pos);
			p[++k]=cnt;ans[k]=rem;
			if (pos==n) break;
			last=pos;
		}
	}
/*	for (int i=1;i<=n;i++) {
		cout << p[i] << ' ' << ans[i] << endl;
	}*/
	scanf("%d",&q);
	for (int i=1;i<=q;i++) {
		scanf("%d",&x);
		if (x>=p[n]) {
			printf("%d %d\n",n,ans[n]);
			continue;
		}
		int pos=upper_bound(p+1,p+n+1,x)-p;
		printf("%d %d\n",pos-1,(x-p[pos-1])*m+ans[pos-1]);
	}
	return 0;
}
