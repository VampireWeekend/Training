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
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=100005,inf=0x3f3f3f3f;
const ld pi=acos(-1.0L);
int head[maxn];
int size[maxn],son[maxn],fa[maxn],top[maxn],dep[maxn],dfn[maxn];
bool visit[maxn];
int num;

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

//Decomposition Part
int dfs(int now,int step) {
    visit[now]=1;son[now]=-1;size[now]=1;dep[now]=step;
    int i;
    for (i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (!visit[to]) {
            fa[to]=now;
            size[now]+=dfs(to,step+1);
            if (son[now]==-1||size[to]>size[son[now]]) son[now]=to;
        }
    }
    return size[now];
}

void dfs2(int now,int gr) {
    top[now]=gr;
    dfn[now]=++num;
    visit[now]=1;
    if (son[now]==-1) return;
    dfs2(son[now],gr);
    int i;
    for (i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (!visit[to]) dfs2(to,to);
    }
}

//Segment Tree Part
struct Tree {
	int lc,rc,l,r,inv;
	ull tag,sum,mul;
};
Tree tree[4*maxn];

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=0;
	tree[now].mul=1;
	tree[now].inv=1;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	} else tree[now].sum=0;
}

void pushdown(int now) {
	int l=tree[now].lc;
	int r=tree[now].rc;
	tree[l].tag=tree[l].tag*tree[now].mul+tree[now].tag;
	tree[r].tag=tree[r].tag*tree[now].mul+tree[now].tag;
	tree[l].mul*=tree[now].mul;
	tree[r].mul*=tree[now].mul;
	tree[l].sum*=tree[now].mul;
	tree[l].sum+=tree[now].tag*(ull)(tree[l].r-tree[l].l+1);
	tree[r].sum*=tree[now].mul;
	tree[r].sum+=tree[now].tag*(ull)(tree[r].r-tree[r].l+1);
	tree[now].tag=0;tree[now].mul=1;
	if (tree[now].inv==1) return;
	tree[l].inv*=tree[now].inv;tree[r].inv*=tree[now].inv;
	tree[now].inv=1;
	tree[now].sum=~tree[now].sum;
}

void add(int now,int l,int r,ull c) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag+=c;
		tree[now].sum+=c*(ull)(tree[now].r-tree[now].l+1);
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2)
			add(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    add(tree[now].rc,l,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
}

void multiply(int now,int l,int r,ull c) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag*=c;
		tree[now].mul*=c;
		tree[now].sum*=c;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2)
			multiply(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
			multiply(tree[now].rc,l,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
}

void invert(int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].inv*=-1;
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2)
			invert(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
			invert(tree[now].rc,l,r);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
}

ull findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << ' ' << tree[now].mul << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		if (tree[now].inv==-1)
			return ~tree[now].sum;
		else
			return tree[now].sum;
	} else {
		pushdown(now);
		ull f=0;
		if (l<=(tree[now].l+tree[now].r)/2)
			f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
			f+=findsum(tree[now].rc,l,r);
		return f;
	}
}
//Tree Modify Part
void TreeAdd(int u,int v,ull val) {
    int x=top[u],y=top[v];
    while (x!=y) {
        if (dep[x]<dep[y]) swap(x,y),swap(u,v);
    	add(1,dfn[x],dfn[u],val);
        u=fa[x];
        x=top[u];
    }
    if (dep[u]<dep[v]) swap(u,v);
    add(1,dfn[v],dfn[u],val);
}

void TreeMultiply(int u,int v,ull val) {
    int x=top[u],y=top[v];
    while (x!=y) {
        if (dep[x]<dep[y]) swap(x,y),swap(u,v);
    	multiply(1,dfn[x],dfn[u],val);
        u=fa[x];
        x=top[u];
    }
    if (dep[u]<dep[v]) swap(u,v);
    multiply(1,dfn[v],dfn[u],val);
}

void TreeInvert(int u,int v) {
    int x=top[u],y=top[v];
    while (x!=y) {
        if (dep[x]<dep[y]) swap(x,y),swap(u,v);
    	invert(1,dfn[x],dfn[u]);
        u=fa[x];
        x=top[u];
    }
    if (dep[u]<dep[v]) swap(u,v);
    invert(1,dfn[v],dfn[u]);
}

ull TreeFindsum(int u,int v) {
    int x=top[u],y=top[v];
	ull ans=0;
    while (x!=y) {
        if (dep[x]<dep[y]) swap(x,y),swap(u,v);
    	ans+=findsum(1,dfn[x],dfn[u]);
        u=fa[x];
        x=top[u];
    }
    if (dep[u]<dep[v]) swap(u,v);
    ans+=findsum(1,dfn[v],dfn[u]);
	return ans;
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		num=0;memset(head,-1,sizeof(head));
		int x,y,q,op,u,v;
		for (int i=1;i<n;i++) {
			scanf("%d",&x);
			addedge(i+1,x);
		}
		num=1;build(1,1,n);
		mem0(visit);dfs(1,1);
		num=0;mem0(visit);dfs2(1,1);
		scanf("%d",&q);
		ull val;
		for (int T=1;T<=q;T++) {
			scanf("%d",&op);
			if (op==1) {
				scanf("%d%d%llu",&u,&v,&val);
				TreeMultiply(u,v,val);
			} else if (op==2) {
				scanf("%d%d%llu",&u,&v,&val);
				TreeAdd(u,v,val);
			} else if (op==3) {
				scanf("%d%d",&u,&v);
				TreeInvert(u,v);
			} else {
				scanf("%d%d",&u,&v);
				ull ans=TreeFindsum(u,v);
				printf("%llu\n",ans);
			}
		}
	}
	return 0;
}
