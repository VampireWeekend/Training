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
int head[maxn],h[maxn],in[maxn],a[maxn],dep[maxn],b[maxn],ro[maxn];
int mfa[maxn][20],st[maxn];
ll md[maxn],val[maxn],sum[maxn];
bool visit[maxn],red[maxn];
int num,dfn,n;
ll ans;

struct Edge {
    int from,to,pre;
    ll dist;
};
Edge edge[maxn*2],e[maxn*2];

void addedge(int from,int to,ll dist) {
    edge[num]=(Edge){from,to,head[from],dist};
    head[from]=num++;
    edge[num]=(Edge){to,from,head[to],dist};
    head[to]=num++;
}

void adde(int from,int to) {
    if (from==to) return;
    e[num]=(Edge){from,to,h[from]};
    h[from]=num++;
    e[num]=(Edge){to,from,h[to]};
    h[to]=num++;
}

bool cmp(int a,int b) {
    return in[a]<in[b];
}

void dfs(int now,ll dist,int fa,int step,int minred) {
	mfa[now][0]=fa;
	for (int i=1;(1<<i)<=n;i++)
		mfa[now][i]=mfa[mfa[now][i-1]][i-1];
    visit[now]=1;
    a[++dfn]=now;dep[now]=step;
    in[now]=dfn;
    md[now]=dist;
	val[minred]=max(val[minred],dist);
	ro[now]=minred;
    for (int i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (!visit[to]) {
			sum[to]=sum[now]+edge[i].dist;
			if (red[to])
            	dfs(to,0,now,step+1,to);
			else
				dfs(to,edge[i].dist+dist,now,step+1,minred);
        }
    }
}

int findlca(int a,int b) {
    int x=a,y=b;
    int i;
    if (dep[x]>dep[y]) swap(x,y);
    for (i=18;i>=0;i--) {
    	if (dep[mfa[y][i]]>=dep[x]) y=mfa[y][i];
    }
    if (y==x) return x;
    for (i=18;i>=0;i--) {
    	if (mfa[y][i]!=mfa[x][i]&&mfa[x][i]!=0&&mfa[y][i]!=0) {
    		x=mfa[x][i];y=mfa[y][i];
    	}
    }
    return mfa[x][0];
}

int In[maxn],Out[maxn],Order[maxn];
ll Premax[maxn],Sufmax[maxn],Far[maxn];
void makedp(int now,int fa) {
	In[now]=Out[now]=++dfn;
	Premax[dfn]=Sufmax[dfn]=md[now];
	Order[dfn]=now;
	Far[now]=0;
    for (int i=h[now];i!=-1;i=e[i].pre) {
        int to=e[i].to;
        if (to!=fa) {
            makedp(to,now);
			Far[now]=max(Far[now],Far[to]+sum[to]-sum[now]);
			Out[now]=dfn;
        }
    }
//	cout << now << ' ' << ans << endl;
    h[now]=-1;
}

void build() {
    int n,j,i,k,root=0;
	ll sec=0;
    scanf("%d",&k);
	ans=0;
    for (i=1;i<=k;i++) {
		scanf("%d",&b[i]);
		if (root==0) root=ro[b[i]]; else
		if (val[ro[b[i]]]>val[root]) sec=max(sec,val[root]),root=ro[b[i]]; else
			if (root!=ro[b[i]]) sec=max(sec,val[ro[b[i]]]);
//		cout << sec << endl;
	}
	n=0;
	for (i=1;i<=k;i++) {
		if (ro[b[i]]==root&&b[i]!=root) b[++n]=b[i];
	}
	k=n;
	if (k==0) {
		printf("0\n");return;
	}
    sort(b+1,b+k+1,cmp);
    num=0;
    n=1;
    for (i=2;i<=k;i++)
        if (findlca(b[n],b[i])!=b[n]) b[++n]=b[i];
    int top=0;
    st[++top]=root;
    for (i=1;i<=n;i++) {
        int now=b[i],f=findlca(now,st[top]);
        while (true) {
            if (dep[f]>=dep[st[top-1]]) {
                adde(f,st[top--]);
                if (st[top]!=f) st[++top]=f;
                break;
            }
            adde(st[top-1],st[top]);
            top--;
        }
        if (st[top]!=now) st[++top]=now;
    }
    while (--top) adde(st[top],st[top+1]);
	dfn=0;
	makedp(root,0);
	Premax[0]=Premax[dfn+1]=Sufmax[0]=Sufmax[dfn+1]=0;
	ans=llinf;
//	cout << root << endl;
	for (int i=2;i<=dfn+1;i++) Premax[i]=max(Premax[i-1],Premax[i]);
	for (int i=dfn-1;i>=0;i--) Sufmax[i]=max(Sufmax[i+1],Sufmax[i]);
/*	for (int i=1;i<=dfn;i++) {
		 cout << Order[i] << ' ' << Far[Order[i]] << ' ' << Premax[In[Order[i]]-1] << ' ' << Sufmax[Out[Order[i]]+1] << endl;
	}*/
	for (int i=1;i<=dfn;i++) ans=min(ans,max(Far[Order[i]],max(Premax[In[Order[i]]-1],Sufmax[Out[Order[i]]+1])));
	ans=max(ans,sec);
    printf("%lld\n",ans);
}

int main() {
int T;
scanf("%d",&T);
while (T--) {
    int i,x,y,d,q,m;
    scanf("%d%d%d",&n,&m,&q);
    num=dfn=0;memset(head,-1,sizeof(head));
	mem0(red);
	for (int i=1;i<=m;i++) {
		scanf("%d",&x);
		red[x]=1;
	}
    for (i=1;i<n;i++) {
        scanf("%d%d%d",&x,&y,&d);
        addedge(x,y,(ll)d);
    }
    mem0(visit);mem0(val);
    sum[0]=0;
    dfs(1,0,0,1,1);
    memset(h,-1,sizeof(h));
    for (i=1;i<=q;i++)
        build();
}
    return 0;
}
