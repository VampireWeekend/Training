#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
typedef long long ll;
const int maxn=105;
const ll mod=1000000009;
using namespace std;
ll dp[maxn][maxn],c[maxn][maxn];
char s1[maxn],s2[maxn];

int main() {
	int n,k,m,i,j,cnt,l;
	for (i=0;i<=100;i++) {
		for (j=0;j<=100;j++) {
			c[i][j]=1;
		}
	}
	for (i=2;i<=100;i++) {
		for (j=1;j<=i-1;j++) {
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=mod;
		}
	}
	while(scanf("%d%d%d",&n,&k,&m)!=EOF) {
	    scanf("%s",s1);
		scanf("%s",s2);
		cnt=0;
		for (i=0;i<n;i++) if (s1[i]!=s2[i]) cnt++;
		memset(dp,0,sizeof(dp));
		dp[0][cnt]=1;
		for (i=0;i<k;i++) {
			for (j=0;j<=n;j++) {
				for (l=0;l<=m;l++) {
					if ((j+m-2*l)>=0&&(j+m-2*l)<=n&&abs(l)<=j&&(n-j)>=(m-l)) {
					dp[i+1][j-l+m-l]+=(((dp[i][j]*c[j][l])%mod)*c[n-j][m-l])%mod;
					dp[i+1][j+m-l-l]%=mod;
				    }
				}
			}
		}
		printf("%lld\n",dp[k][0]);
	}
	return 0;
}
