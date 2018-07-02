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
int sz[maxn],son[maxn],fa[maxn][20],top[maxn],dep[maxn],dfn[maxn],head[maxn];
bool visit[maxn];
int num=0;

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from, int to) {
	edge[num].from = from; edge[num].to = to; edge[num].pre = head[from];
	head[from]=num++;
	edge[num].from = to; edge[num].to = from; edge[num].pre = head[to];
	head[to]=num++;
}

struct query{
	int x,y,lca,len;
};
query a[maxn];

bool sortcmp(query aa,query bb) {
	return dep[aa.lca] < dep[bb.lca] || (dep[aa.lca] == dep[bb.lca] && aa.len > bb.len);
}

int dfs(int now,int step) {  
    visit[now]=1;son[now]=-1;sz[now]=1;dep[now]=step;  
    int i;  
    for (i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!visit[to]) {  
            fa[to][0]=now;  
            sz[now]+=dfs(to,step+1);  
            if (son[now]==-1||sz[to]>sz[son[now]]) son[now]=to;  
        }  
    }  
    return sz[now];  
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

int findlca(int a,int b) {    
    int x=a,y=b,i;  
    if (dep[x]>dep[y]) swap(x,y);  
    for (i=18;i>=0;i--)
        if (dep[fa[y][i]]>=dep[x]) y=fa[y][i];  
    if (y==x) return x;  
    for (i=18;i>=0;i--)
        if (fa[y][i]!=fa[x][i]&&fa[x][i]!=0&&fa[y][i]!=0)
            x=fa[x][i],y=fa[y][i];  
    return fa[x][0];  
}  

struct Tree {
	int lc,rc,l,r,max,tag,min;
};
Tree tree[4*maxn];

bool cmp(Tree a,Tree b) {
	if (a.max+a.tag>b.max+b.tag) return true; else return false;
}

bool cmp2(Tree a,Tree b) {
	if (a.min+a.tag<b.min+b.tag) return true; else return false;
}

void pushup(int now) {
	if (cmp(tree[tree[now].lc],tree[tree[now].rc])) 
		tree[now].max=tree[tree[now].lc].max+tree[tree[now].lc].tag;
	 else 
		tree[now].max=tree[tree[now].rc].max+tree[tree[now].rc].tag;
	if (cmp2(tree[tree[now].lc],tree[tree[now].rc])) 
		tree[now].min=tree[tree[now].lc].min+tree[tree[now].lc].tag;
	 else 
		tree[now].min=tree[tree[now].rc].min+tree[tree[now].rc].tag;
}

void pushdown(int now) {
	if (tree[now].tag==0) return;
	tree[tree[now].lc].tag+=tree[now].tag;
	tree[tree[now].rc].tag+=tree[now].tag;
	tree[now].max+=tree[now].tag;tree[now].min+=tree[now].tag;
	tree[now].tag=0;
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=0;
	tree[now].max=tree[now].min=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
	}
}

void update (int now,int l,int r,int c) {
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
}

int findmax (int now,int l,int r) {
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
}

int findmin (int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].min+tree[now].tag;
	} else {
		//deleted pushdown
		int ans=inf;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    ans=min(ans,findmin(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].rc,l,r));
		return ans;
	}
}

void modify(int u,int v,int val) {  
    int x=top[u],y=top[v];  
    while (x!=y) {  
        if (dep[x]<dep[y]) swap(x,y),swap(u,v);  
        update(1,dfn[x],dfn[u],val);  
        u=fa[x][0];  
        x=top[u];  
    }  
    if (dep[u]<dep[v]) swap(u,v);  
    update(1,dfn[v],dfn[u],val);  
}  

bool search(int u,int v) {
	int x=top[u],y=top[v];  
	int mx,mn;mx=-1;mn=inf;
    while (x!=y) {  
        if (dep[x]<dep[y]) swap(x,y),swap(u,v);  
        mx=max(mx,findmax(1,dfn[x],dfn[u]));  
		mn=min(mn,findmin(1,dfn[x],dfn[u])); 
        u=fa[x][0];  
        x=top[u];  
    }  
    if (dep[u]<dep[v]) swap(u,v);  
    mx=max(mx,findmax(1,dfn[v],dfn[u]));  
	mn=min(mn,findmin(1,dfn[v],dfn[u])); 
	return mx==mn;
}

int main() {
	int n,q,x,y;
	scanf("%d%d",&n,&q);
	num=0;memset(head,-1,sizeof(head));
	for (int i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	num=0;
	fa[1][0]=0;dep[0]=-1;
	dfs(1,1);num=0;
	for (int j=1;j<=18;j++) 
		for (int i=1;i<=n;i++) 
			fa[i][j]=fa[fa[i][j-1]][j-1];
	mem0(visit);dfs2(1,1);
	for (int i=1;i<=q;i++) {
		scanf("%d%d",&x,&y);
		a[i].x=x;a[i].y=y;
		a[i].lca=findlca(x,y);
		a[i].len=dep[x]+dep[y]-2*dep[a[i].lca];
	}
	num=1;
	build(1,1,n);
	sort(a+1,a+q+1,sortcmp);
	for (int i=1;i<=q;i++) {
		if (!search(a[i].x,a[i].y)) {
			printf("No\n");return 0;
		}
		modify(a[i].x,a[i].y,1);
	}
	printf("Yes\n");
	system("pause");
	return 0;
}