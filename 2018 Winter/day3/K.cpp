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
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
int size[maxn],son[maxn],fa[maxn],top[maxn],dep[maxn],dfn[maxn];  
ll a[maxn];
bool visit[maxn];  
int num;  
vector<int> v[maxn];  

void addedge(int from,int to) {  
    v[from].push_back(to);  
    v[to].push_back(from);  
}  
  
int dfs(int now,int step) {  
    visit[now]=1;son[now]=-1;dep[now]=step;size[now]=1;  
    for (int i=0;i<v[now].size();i++) {  
        int to=v[now][i];  
        if (!visit[to]) {  
            fa[to]=now;  
            size[now]+=dfs(to,step+1);  
            if (son[now]==-1||size[to]>size[son[now]]) son[now]=to;  
        }  
    }  
    return size[now];  
}  
  
void dfs2(int now,int t) {  
    visit[now]=1;top[now]=t;dfn[now]=++num;  
    if (son[now]!=-1) dfs2(son[now],t);  
    for (int i=0;i<v[now].size();i++) {  
        int to=v[now][i];  
        if (!visit[to])   
            dfs2(to,to);  
    }  
}  

struct Tree {
	int lc,rc,l,r,sum,tag;
};
Tree tree[4*maxn];

void build(int now,int l,int r,int c) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=-1;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2,c);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	} else tree[now].sum=a[l]>=c?1:0;
}

void pushdown(int now) {
	if (tree[now].tag==-1) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].tag=tree[now].tag;
	tree[r].tag=tree[now].tag;
	tree[l].sum=tree[now].tag*(tree[l].r-tree[l].l+1);
	tree[r].sum=tree[now].tag*(tree[r].r-tree[r].l+1);
	tree[now].tag=-1;
}

void update (int now,int l,int r,int c) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].sum=c*(tree[now].r-tree[now].l+1);
		tree[now].tag=c; 
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
}

int findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
	pushdown(now);
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		int f=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    f+=findsum(tree[now].rc,l,r);
		return f;
	}
}

ll findval(int u) {  
    int x=top[u],ans=1;  
    while (x!=1) {  
        ans*=findsum(1,dfn[x]-1,dfn[u]-1);  
        ans%=mod;
        u=fa[x];x=top[u];  
    }  
    ans*=findsum(1,dfn[son[x]]-1,dfn[u]-1);  
    ans%=mod;
    return ans;  
}  

int main() {
	int n,i,x,y;
	scanf("%d",&n);
	num=0;
	for (i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		x++;y++;
		addedge(x,y);
	}
	mem0(visit);  
    dfs(1,0);  
    num=0;  
    mem0(visit);  
    dfs2(1,1);  
	for (i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	mem0(visit);
	return 0;
}
