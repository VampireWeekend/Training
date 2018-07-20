#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int dp[205][205];

int dfs(int n,int m) {
	if (dp[n][m]!=-1) return dp[n][m];
	int visit[1024];
	memset(visit,0,sizeof(visit));
	int i;
	for (i=2;i<=n-i;i++) {
		dp[i][m]=dfs(i,m);
		dp[n-i][m]=dfs(n-i,m);
		visit[dp[i][m]^dp[n-i][m]]=1;
	}
	for (i=2;i<=m-i;i++) {
		dp[n][i]=dfs(n,i);
		dp[n][m-i]=dfs(n,m-i);
		visit[dp[n][i]^dp[n][m-i]]=1;
	}
	for (i=0;;i++) 
	    if(!visit[i]) return dp[n][m]=i;
}

int main() {
	int i,n,m;// 0 lose 1 win
	memset(dp,-1,sizeof(dp));
	while (scanf("%d%d",&n,&m)!=EOF) {
		if (dfs(n,m)) printf("WIN\n"); else printf("LOSE\n");
	}
	return 0;
}
