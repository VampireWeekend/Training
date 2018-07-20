#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int cnt[maxn],head[maxn];
int num,n,nume;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
	edge[nume]=(Edge){from,to,head[from]};
	head[from]=nume++;
}

struct Tree {
	int lc,rc,l,r,min,num,tag;
};
Tree tree[4*maxn];

bool cmp(Tree a,Tree b) {
	if (a.min-a.tag<b.min-b.tag||(a.min-a.tag==b.min-b.tag&&a.num>b.num)) 
	return true; else return false;
}

void pushup(int now) {
	if (cmp(tree[tree[now].lc],tree[tree[now].rc])) {
		tree[now].num=tree[tree[now].lc].num;
		tree[now].min=tree[tree[now].lc].min-tree[tree[now].lc].tag;
	} else {
		tree[now].num=tree[tree[now].rc].num;
		tree[now].min=tree[tree[now].rc].min-tree[tree[now].rc].tag;
	}
}

void pushdown(int now) {
	if (tree[now].tag==0) return;
	tree[tree[now].lc].tag+=tree[now].tag;
	tree[tree[now].rc].tag+=tree[now].tag;
	tree[now].min-=tree[now].tag;
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
	} else tree[now].min=cnt[l],tree[now].num=l;
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << endl;
}

void update (int now,int l,int r,int c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].min << ' ' << tree[now].tag << ' ' << tree[now].num << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag+=c;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		pushup(now);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].min << ' ' << tree[now].tag << ' ' << tree[now].num << endl;
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
    	int m,i,x,y;
    	scanf("%d%d",&n,&m);
    	memset(head,-1,sizeof(head));
    	nume=0;
    	for (i=1;i<=n;i++) {
    		cnt[i]=i-1;
    	}
    	for (i=1;i<=m;i++) {
    		scanf("%d%d",&x,&y);
    		addedge(x,y);
    		cnt[y]--;
    	}
    	num=1;
    	build(1,1,n);
    	for (i=1;i<=n;i++) {
    		int ans=tree[1].num;
    		printf("%d ",ans);
    		update(1,ans,ans,-inf);
    		if (ans!=n) update(1,ans+1,n,1);
    		for (int j=head[ans];j!=-1;j=edge[j].pre) {
    			update(1,edge[j].to,edge[j].to,-1);
    		}
    	}
    	printf("\n");
    }
	return 0;
}
