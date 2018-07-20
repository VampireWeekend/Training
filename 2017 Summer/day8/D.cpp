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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=505,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[maxn][maxn],dp[maxn][maxn],visit[maxn][maxn];
char s[maxn];

struct node {
	int x,y;
	node(int x,int y):x(x),y(y) {}
};

int main() {
	int n,m,i,j;
	scanf("%d%d\n",&n,&m);
	queue<node> q;
	meminf(dp);
	for (i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (j=1;j<=m;j++) {
			a[i][j]=s[j]-'0';
		}
	}
	q.push(node(1,1));
	mem0(visit);
	visit[1][1]=1;
	dp[1][1]=0;
	while (!q.empty()) {
		int nowx=q.front().x,nowy=q.front().y;
		q.pop();
		if (a[nowx][nowy]!=0) {
		if (nowx+a[nowx][nowy]>0&&nowx+a[nowx][nowy]<=n) {
			if (!visit[nowx+a[nowx][nowy]][nowy]) {
				visit[nowx+a[nowx][nowy]][nowy]=1;
				q.push(node(nowx+a[nowx][nowy],nowy));
				dp[nowx+a[nowx][nowy]][nowy]=dp[nowx][nowy]+1;
			}
		}
		if (nowx-a[nowx][nowy]>0&&nowx-a[nowx][nowy]<=n) {
			if (!visit[nowx-a[nowx][nowy]][nowy]) {
				visit[nowx-a[nowx][nowy]][nowy]=1;
				q.push(node(nowx-a[nowx][nowy],nowy));
				dp[nowx-a[nowx][nowy]][nowy]=dp[nowx][nowy]+1;
			}
		}
		if (nowy+a[nowx][nowy]>0&&nowy+a[nowx][nowy]<=m) {
			if (!visit[nowx][nowy+a[nowx][nowy]]) {
				visit[nowx][nowy+a[nowx][nowy]]=1;
				q.push(node(nowx,nowy+a[nowx][nowy]));
				dp[nowx][nowy+a[nowx][nowy]]=dp[nowx][nowy]+1;
			}
		}
		if (nowy-a[nowx][nowy]>0&&nowy-a[nowx][nowy]<=m) {
			if (!visit[nowx][nowy-a[nowx][nowy]]) {
				visit[nowx][nowy-a[nowx][nowy]]=1;
				q.push(node(nowx,nowy-a[nowx][nowy]));
				dp[nowx][nowy-a[nowx][nowy]]=dp[nowx][nowy]+1;
			}
		}
    	}
	}
	if (dp[n][m]==inf) printf("IMPOSSIBLE\n"); else cout << dp[n][m] << endl;
	return 0;
}
