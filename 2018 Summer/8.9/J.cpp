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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int up[maxn],pre[maxn][62],rpre[62],pos[maxn],nl[maxn];
char s[maxn][maxn];
vector<int> pos[maxn],nl[maxn];
int num=0;

struct Tree {
	int lc,rc,l,r,sum,tag,max,min;
};
Tree tree[4*maxn];

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=-1;
	tree[now].max=tree[now].min=tree[now].sum=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
}

void pushdown(int now) {
	if (tree[now].tag==-1) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].tag=tree[r].tag=tree[now].tag;
	tree[l].sum=tree[now].tag*(tree[l].r-tree[l].l+1);
	tree[r].sum=tree[now].tag*(tree[r].r-tree[r].l+1);
	tree[l].max=tree[r].max=tree[l].min=tree[r].min=tree[now].tag;
	tree[now].tag=-1;
}

void pushup(int now) {
	tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	tree[now].max=max(tree[tree[now].lc].max,tree[tree[now].rc].max);
	tree[now].min=min(tree[tree[now].lc].min,tree[tree[now].rc].min);
}

void modify (int now,int pos,int c) {
	if (tree[now].l==tree[now].r&&tree[now].l==pos) {
		tree[now].sum=tree[now].tag=tree[now].min=tree[now].max=c;
	} else {
		pushdown(now);
		if (pos<=(tree[now].l+tree[now].r)/2) 
		    modify(tree[now].lc,pos,c);
		if (pos>(tree[now].l+tree[now].r)/2)
		    modify(tree[now].rc,pos,c);
		pushup(now);
	}
}

void update (int now,int l,int r,int c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].tag 
//		 << ' ' << tree[now].max << ' ' << tree[now].min << ' ' << tree[now].sum << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		if (tree[now].min>=c) {
			tree[now].sum=c*(tree[now].r-tree[now].l+1);
			tree[now].tag=c; 
			tree[now].min=tree[now].max=c;
		} else {
			if (tree[now].l==tree[now].r) return;
			pushdown(now);
			if (tree[tree[now].lc].max>c) update(tree[now].lc,l,r,c);
			if (tree[tree[now].rc].max>c) update(tree[now].rc,l,r,c);
            pushup(now);
		}
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		pushup(now);
	}
}

int findsum(int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		pushdown(now);
		int f=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    f+=findsum(tree[now].rc,l,r);
		pushup(now);
		return f;
	}
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
	}
/*	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) 
			if ((i+j)%52>=26) s[i][j]=(char)('A'+(i+j)%52-26); else s[i][j]=(char)('a'+(i+j)%52);
	}*/
	ll ans=0;
	int id;
	for (int i=1;i<=n;i++) {
		mem0(rpre);
		int last=0;
		num=1;
		build(1,1,m);
		for (int j=1;j<=m;j++) {
			if (s[i][j]<='Z') id=s[i][j]-'A'; else id=s[i][j]-'a'+26;
			up[j]=max(up[j],pre[j][id]);
			pre[j][id]=i;
			modify(1,j,i-up[j]);
			last=max(last,rpre[id]);
			update(1,1,j,i-up[j]);
			int sz=pos[j].size();
			for (int k=0;k<sz;k++) update(1,1,pos[j][k],nl[j][k]);
			ans+=(ll)findsum(1,last+1,j);
			if (rpre[id]) {
				pos[j].pb(rpre[id]);
				nl[j].pb(i);
			}
			rpre[id]=j;
//			cout << ans << endl;
		}
	}
	printf("%lld\n",ans);
	return 0;
}