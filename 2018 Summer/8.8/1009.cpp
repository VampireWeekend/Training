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
#include <stack>
#include <assert.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,maxk=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L); 
int color[maxn*2],head[maxn*2],dfn[maxn*2];
int color2[maxn*2],dfn2[maxn*2];
char s[maxn];
int num;
 
struct Edge {
    int from,to,pre;
};
Edge edge[maxk*2];
 
void addedge(int from,int to) {
    edge[num]=(Edge){from,to,head[from]};
    head[from]=num++;
}
 
bool dfs(int now) {
    if (color[now]==1) return true;
    if (color[now]==2) return false;
    color[now]=1;
    color[now^1]=2;
    dfn[++num]=now;
    for (int i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (!dfs(to)) return false;
    }
    return true;
}

bool dfs2(int now) {
    if (color2[now]==1) return true;
    if (color2[now]==2) return false;
    color2[now]=1;
    color2[now^1]=2;
    dfn2[++num]=now;
    for (int i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (!dfs2(to)) return false;
    }
    return true;
}
 
int main() {
    int cas;
    scanf("%d",&cas);
while (cas--) {
    int n,i,j,x;
    num=0;
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d%s",&x,s);
        x--;
        if (s[0]=='w') addedge(i*2,x*2+1),addedge(x*2,i*2+1);
         else addedge(i*2,x*2),addedge(x*2+1,i*2+1);
    }
    mem0(color);
    for (i=0;i<n;i++) {
            if (!color[i*2]) {
                num=0;
                if (!dfs(i*2)) {
                    for (j=1;j<=num;j++) 
                        color[dfn[j]]=color[dfn[j]^1]=0;
                    bool flag=dfs(i*2+1);
                    assert(flag);
                }
            }
        }
    mem0(color2);
    for (i=0;i<n;i++) {
            if (!color2[i*2+1]) {
                num=0;
                if (!dfs2(i*2+1)) {
                    for (j=1;j<=num;j++) 
                        color2[dfn2[j]]=color2[dfn2[j]^1]=0;
                    bool flag=dfs2(i*2);
                    assert(flag);
                }
            }
        }
    int ans1,ans2;
    ans1=ans2=0;
    for (i=0;i<n;i++) {
        if (color[i*2]==color2[i*2]) {
            if (color[i*2]==1) ans1++; else ans2++;
        }
    }
    printf("%d %d\n",ans1,ans2);
}
    return 0;
}
