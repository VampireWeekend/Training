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
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int dp[maxn][maxn][6];
int a[maxn][maxn][2];
int p[1005][2];

int main() {
	int cas,i,k,j;
	mem0(p);
	for (i=1;i<=1000;i++) {
		k=i;
		while (k%2==0) {
			p[i][0]++;
			k/=2;
		}
		while (k%3==0) {
			p[i][1]++;
			k/=3;
		}
	}
	scanf("%d",&cas);
	while (cas--) {
		int n,m,x;
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				scanf("%d",&x);
				a[i][j][0]=p[x][0];
				a[i][j][1]=p[x][1];
			}
		}
		mem0(dp);
		dp[1][1][0]=dp[1][1][2]=dp[1][1][4]=a[1][1][0];
		dp[1][1][1]=dp[1][1][3]=dp[1][1][5]=a[1][1][1];
		for (i=2;i<=m;i++) {
			dp[1][i][0]=dp[1][i][2]=dp[1][i][4]=dp[1][i-1][0]+a[1][i][0];
			dp[1][i][1]=dp[1][i][3]=dp[1][i][5]=dp[1][i-1][1]+a[1][i][1];
//			cout << 1 << ' ' << i << ' ' << dp[1][j][0] << ' ' << dp[1][j][1]<< endl;
		}
		for (i=2;i<=n;i++) {
			dp[i][1][0]=dp[i][1][2]=dp[i][1][4]=dp[i-1][1][0]+a[i][1][0];
			dp[i][1][1]=dp[i][1][3]=dp[i][1][5]=dp[i-1][1][1]+a[i][1][1];
//			cout << i << ' ' << 1 << ' ' << dp[i][1][0] << ' ' << dp[i][1][1]<< endl;
		}
		for (i=2;i<=n;i++) {
			for (j=2;j<=m;j++) {
				if (min(dp[i][j-1][0]+a[i][j][0],dp[i][j-1][1]+a[i][j][1])>
				min(dp[i-1][j][0]+a[i][j][0],dp[i-1][j][1]+a[i][j][1])) {
					dp[i][j][0]=dp[i][j-1][0]+a[i][j][0];
					dp[i][j][1]=dp[i][j-1][1]+a[i][j][1];
				} else {
					dp[i][j][0]=dp[i-1][j][0]+a[i][j][0];
					dp[i][j][1]=dp[i-1][j][1]+a[i][j][1];
				}
				if (min(dp[i][j-1][2]+a[i][j][0],dp[i][j-1][3]+a[i][j][1])>min(dp[i][j][0],dp[i][j][1])) {
					dp[i][j][0]=dp[i][j-1][2]+a[i][j][0];
					dp[i][j][1]=dp[i][j-1][3]+a[i][j][1];
				}
				if (min(dp[i-1][j][2]+a[i][j][0],dp[i-1][j][3]+a[i][j][1])>min(dp[i][j][0],dp[i][j][1])) {
					dp[i][j][0]=dp[i-1][j][2]+a[i][j][0];
					dp[i][j][1]=dp[i-1][j][3]+a[i][j][1];
				}
				if (min(dp[i][j-1][4]+a[i][j][0],dp[i][j-1][5]+a[i][j][1])>min(dp[i][j][0],dp[i][j][1])) {
					dp[i][j][0]=dp[i][j-1][4]+a[i][j][0];
					dp[i][j][1]=dp[i][j-1][5]+a[i][j][1];
				}
				if (min(dp[i-1][j][4]+a[i][j][0],dp[i-1][j][5]+a[i][j][1])>min(dp[i][j][0],dp[i][j][1])) {
					dp[i][j][0]=dp[i-1][j][4]+a[i][j][0];
					dp[i][j][1]=dp[i-1][j][5]+a[i][j][1];
				}
				
				if (dp[i][j-1][2]+a[i][j][0]>dp[i-1][j][2]+a[i][j][0]) {
					dp[i][j][2]=dp[i][j-1][2]+a[i][j][0];
					dp[i][j][3]=dp[i][j-1][3]+a[i][j][1];
				} else {
					dp[i][j][2]=dp[i-1][j][2]+a[i][j][0];
					dp[i][j][3]=dp[i-1][j][3]+a[i][j][1];
				}
				
				if (dp[i][j-1][5]+a[i][j][1]>dp[i-1][j][5]+a[i][j][1]) {
					dp[i][j][4]=dp[i][j-1][4]+a[i][j][0];
					dp[i][j][5]=dp[i][j-1][5]+a[i][j][1];
				} else {
					dp[i][j][4]=dp[i-1][j][4]+a[i][j][0];
					dp[i][j][5]=dp[i-1][j][5]+a[i][j][1];
				}
	//			cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1]<< endl;
			}
		}
		int ans=min(dp[n][m][0],dp[n][m][1]);
		printf("%d\n",ans);
	}
	return 0;
}

