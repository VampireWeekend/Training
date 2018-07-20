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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],b[maxn],c[maxn];
int num;

struct node{
	int val,id;
};
node d[maxn*3];

bool cmp2(node a,node b) {
	return a.val<b.val;
}

struct Tree {
	int lc,rc,l,r,max,tag;
};
Tree tree[1000005];

bool cmp(Tree a,Tree b) {
	if (a.max+a.tag>b.max+b.tag) return true; else return false;
}

void pushup(int now) {
	if (cmp(tree[tree[now].lc],tree[tree[now].rc])) 
		tree[now].max=tree[tree[now].lc].max+tree[tree[now].lc].tag;
	 else 
		tree[now].max=tree[tree[now].rc].max+tree[tree[now].rc].tag;
}

void pushdown(int now) {
	if (tree[now].tag==0) return;
	tree[tree[now].lc].tag+=tree[now].tag;
	tree[tree[now].rc].tag+=tree[now].tag;
	tree[now].max+=tree[now].tag;
	tree[now].tag=0;
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		pushup(now);
	} else tree[now].max=0;
}

void update (int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag++;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r);
		pushup(now);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int findmax (int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].max+tree[now].tag;
	} else {
		pushdown(now);
		int ans=-inf;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans=max(ans,findmax(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=max(ans,findmax(tree[now].rc,l,r));
		return ans;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int main() {
	int cas,ca=0;
	scanf("%d",&cas);
	while (cas--) {
		ca++;
		num=1;
		int n,m,i,j,ans,cnt=0;
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++) {
			scanf("%d%d",&a[i],&b[i]);
			d[++cnt].val=a[i];
			d[cnt].id=i;
			d[++cnt].val=b[i];
			d[cnt].id=i+n;
		}
		for (i=1;i<=m;i++) {
			scanf("%d",&c[i]);
			d[++cnt].val=c[i];
			d[cnt].id=i+n*2;
		}
		sort(d+1,d+cnt+1,cmp2);
		d[0].val=0;int ct=0;
		for (i=1;i<=cnt;i++) {
//			cout << d[i].val << ' ' << d[i].id << endl;
			if (d[i].val!=d[i-1].val) ct++;
			if (d[i].id<=n) a[d[i].id]=ct; else 
			    if (d[i].id>2*n) c[d[i].id-2*n]=ct; else b[d[i].id-n]=ct; 
		}
		build(1,1,ct);
		for (i=1;i<=n;i++) {
			update(1,a[i],b[i]);
		}
		ans=0;
		int flag=0;
		for (i=1;i<=m;i++) {
			int p=findmax(1,c[i],c[i]);
			if (p==0) {
				printf("Case #%d: IMPOSSIBLE!\n",ca);
				flag=1;break;
			}
			ans=max(ans,n-p+1);
		}
		if (flag) continue;
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}
/*
1
2 3
1 10
1 10
1 10
2 3 4
*/

