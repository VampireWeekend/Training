#include<cstdio>
#include<algorithm>
#include <iostream>
#include<set>
using namespace std;
typedef pair<int,int>P;
const int N=1000010,M=8000000;
int n,m,i,j,x,y;long long ans;
struct E{
    int p,r,c;
}a[N];
P b[N];
int root,l[N],r[N],tot;
set<P>T[N];
int g[2][N],nxt[2][M],v[2][M],ed,f[N],q[N],t,vis[N],ban[N];
inline void add(int x,int y){
    v[0][++ed]=y;nxt[0][ed]=g[0][x];g[0][x]=ed;
    v[1][ed]=x;nxt[1][ed]=g[1][y];g[1][y]=ed;
}
inline void ADD(int x,int y){
    v[1][++ed]=y;nxt[1][ed]=g[1][x];g[1][x]=ed;
    cout << x << ' ' << y << endl;
}
int build(int a,int b){
    int x;
    if(a==b)x=::b[a].second;
    else x=++tot;
    if(a==b)return x;
    int mid=(a+b)>>1;
    l[x]=build(a,mid);
    r[x]=build(mid+1,b);
    add(x,l[x]);         //线段树连边
    add(x,r[x]);
    return x;
}
void ins(int x,int a,int b,int c,int d,int p){      //单个节点i->区间
    if(c<=a&&b<=d){
        add(p,x);
        return;
    }
    int mid=(a+b)>>1;
    if(c<=mid)ins(l[x],a,mid,c,d,p);
    if(d>mid)ins(r[x],mid+1,b,c,d,p);
}
inline int askl(int x){//min >=x
    int l=1,r=n,mid,t;
    while(l<=r){
        mid=(l+r)>>1;
        if(b[mid].first>=x)r=(t=mid)-1;else l=mid+1;
    }
    return t;
}
inline int askr(int x){//max <=x
    int l=1,r=n,mid,t;
    while(l<=r){
        mid=(l+r)>>1;
        if(b[mid].first<=x)l=(t=mid)+1;else r=mid-1;
    }
    return t;
}
void dfs1(int x){
    vis[x]=1;
    for(int i=g[0][x];i;i=nxt[0][i])if(!vis[v[0][i]])dfs1(v[0][i]);
    q[++t]=x;
}
void dfs2(int x,int y){
    vis[x]=0;f[x]=y;
    for(int i=g[1][x];i;i=nxt[1][i])if(vis[v[1][i]])dfs2(v[1][i],y);
}
void dfs3(int x){
    if(ban[x])return;
    ban[x]=1;
    for(int i=g[1][x];i;i=nxt[1][i])dfs3(v[1][i]);
}
inline void solve(int x){
    if(vis[x])return;
    vis[x]=1;
    for(int i=g[1][x];i;i=nxt[1][i])dfs3(v[1][i]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d%d%d",&a[i].p,&a[i].r,&a[i].c),b[i]=P(a[i].p,i);
    sort(b+1,b+n+1);
    tot=n;
    root=build(1,n);
    for(i=1;i<=n;i++){
        int l=askl(a[i].p-a[i].r);
        int r=askr(a[i].p+a[i].r);
        ins(root,1,n,l,r,i);
    }
    for(t=0,i=1;i<=tot;i++)if(!vis[i])dfs1(i);
    for(i=tot;i;i--)if(vis[q[i]])dfs2(q[i],q[i]);
    ed=0;
	
    for(i=1;i<=tot;i++)g[1][i]=0;
    for(i=1;i<=tot;i++)for(j=g[0][i];j;j=nxt[0][j])if(f[i]!=f[v[0][j]])ADD(f[i],f[v[0][j]]);
	
	
    for(i=1;i<=n;i++)solve(f[i]);
    for(i=1;i<=n;i++)if(!ban[f[i]])T[f[i]].insert(P(a[i].c,i));
    for(i=1;i<=tot;i++)if(!ban[i]&&f[i]==i)ans+=T[i].begin()->first;
	
    while(m--){
        scanf("%d%d",&x,&y);
        if(!ban[f[x]]){
            ans-=T[f[x]].begin()->first;
            T[f[x]].erase(P(a[x].c,x));
            T[f[x]].insert(P(a[x].c=y,x));
            ans+=T[f[x]].begin()->first;
        }
        printf("%lld\n",ans);
    }
}
