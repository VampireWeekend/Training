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
const int maxn=100005,maxk=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int num=0;

struct node {
	int l,r,v;
};
node a[maxk];

bool cmp(node a,node b) {
	return a.v>b.v;
}

unsigned x,w,y,z;
unsigned prand() {
	x=x^(x<<11);
	x=x^(x>>4);
	x=x^(x<<5);
	x=x^(x>>14);
	w=x^y^z;
	x=y;y=z;z=w;
	return z;
}

struct Tree {
	int lc,rc,l,r,max,tag;
};
Tree tree[4*maxn];

void build(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].lc << ' ' << tree[now].rc << endl;
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=0;
	tree[now].max=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].lc << ' ' << tree[now].rc << endl;
}

void update (int now,int l,int r,int c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].max=max(c,tree[now].max);
	} else {
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
	}
}

ll findans (int now) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << endl;
	if (tree[now].l==tree[now].r) {
		return (ll)tree[now].l*(ll)tree[now].max;
	} else {
		tree[tree[now].lc].max=max(tree[tree[now].lc].max,tree[now].max);
		tree[tree[now].rc].max=max(tree[tree[now].rc].max,tree[now].max);
		ll ans=findans(tree[now].lc);
		ans^=findans(tree[now].rc);
		return ans;
	}
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m;
		scanf("%d%d",&n,&m);
		unsigned threshold;
		if (m<5000) {
			threshold=-1;
		} else if (m<10000) {
			threshold=5e8;
		} else if (m<100000) {
			threshold=9e8;
		} else if (m<1000000) {
			threshold=1020000000;
		} else threshold=1060000000;
		unsigned f1,f2,l,r,v;
		scanf("%u%u%u",&x,&y,&z);
		int cnt=0;
		for (int i=1;i<=m;i++) {
			f1=prand();f2=prand();
			l=min(f1%n+1,f2%n+1);
			r=max(f1%n+1,f2%n+1);
			v=prand()%(1<<30);
			if (v>threshold||(l<=100||r+100>=n)) {
				a[++cnt].l=l;a[cnt].r=r;a[cnt].v=v;
			} 
		}
		num=1;
		build(1,1,n);
		for (int i=1;i<=cnt;i++) {
			update(1,a[i].l,a[i].r,a[i].v);
		}
		ll ans=findans(1);
		printf("%lld\n",ans);
	}
	return 0;
}
