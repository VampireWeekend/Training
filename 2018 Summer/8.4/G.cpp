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
int head[maxn];
__int128 size[maxn];
__int128 val[maxn],dp[maxn];
bool visit[maxn];
int num=0;
__int128 n;

void scan(__int128 &x)//输入
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}
void _print(__int128 x)
{
    if(x > 9) _print(x/10);
    putchar(x%10 + '0');
}
void print(__int128 x)//输出
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    _print(x);
}

struct Edge {
	int from,to,pre; 
	__int128 dist;
};
Edge edge[maxn*2];

void addedge(int from,int to,__int128 dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to],dist};
	head[to]=num++;
}

void dfs(int now) {
	visit[now]=1;
	size[now]=1;dp[now]=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to);
			size[now]+=size[to];
			dp[now]+=size[to]*edge[i].dist+dp[to];
		}
	}
}

void dfs2(int now,int fa) {
	visit[now]=1;
	size[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dp[to]+=dp[now]-dp[to]-edge[i].dist*size[to]+edge[i].dist*(n-size[to]);
			dfs2(to,now);
		}
	}
}

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
    getchar();
	while (cas--) {
		scan(n);
		memset(head,-1,sizeof(head));
		num=0;
		__int128 x,y;__int128 z;
		for (int i=1;i<n;i++) {
			scan(x);scan(y);scan(z);
			addedge(x,y,z);
		}
		mem0(visit);
		dfs(1);
		mem0(visit);
		dfs2(1,0);
		sort(dp+1,dp+n+1);
		__int128 ans=0;
		for (__int128 i=1;i<n;i++) {
			ans+=dp[i]*(n-i);
		}
		cnt++;
		printf("Case #%d: ",cnt);
		print(ans);
		printf("\n");
	}
	return 0;
}
