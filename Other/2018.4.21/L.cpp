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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int size[maxn],d[maxn][2];
int ans=0,k,n;
vector<int> v[maxn];

void addedge(int from, int to) {
    v[from].push_back(to);
    v[to].push_back(from);
}

void dfs(int now,int fa) {
    size[now]=1;
    for (int i=0;i<v[now].size();i++) {
        int to=v[now][i];
        if (to!=fa) 
            dfs(to,now),size[now]+=size[to];
    }
    d[now][0]=d[now][1]=-1;
    int u=-1;
    for (int i=0;i<v[now].size();i++) {
        int to=v[now][i];
        if (to!=fa) {
            if (d[to][0]!=-1) {
                if (d[to][0]+1>d[now][0]) d[now][0]=d[to][0]+1;
            }
            if (u!=-1&&d[to][0]!=-1) ans=max(ans,u+d[to][0]+2);
            u=max(u,d[to][0]);
        } 
    }
    if (size[now]>=k&&d[now][0]==-1) d[now][0]=0;
}

void dfs2(int now,int fa) {
    for (int i=0;i<v[now].size();i++) {
        int to=v[now][i];
        if (to!=fa) {
            if (n-size[to]>=k) 
                if (d[to][0]!=-1)
                    ans=max(ans,d[to][0]+1);
            dfs2(to,now);
        }
    }
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int i,j,x,y;
        scanf("%d%d",&n,&k);
        for (i=1;i<=n;i++) v[i].clear();
        for (i=1;i<n;i++) {
            scanf("%d%d",&x,&y);
            addedge(x,y);
        }
        ans=0;
        dfs(1,0);
        dfs2(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
