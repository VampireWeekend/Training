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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7; 
const ld pi=acos(-1.0L);
ll a[maxn],dp[maxn][2];

int main() {
	freopen("azerah.in","r",stdin);
	freopen("azerah.out","w",stdout);
    int cas;
    scanf("%d",&cas);
	while (cas--) {
		int n,i;
		scanf("%d",&n);
		ll ans=0;
		dp[0][0]=dp[0][1]=0;
		for (i=1;i<=n;i++) {
			scanf("%I64d",&a[i]);
			if (a[i]%2==1) {
				dp[i][0]=dp[i-1][1]+dp[i-1][0]+1;
				dp[i][1]=dp[i-1][0]+dp[i-1][1];
				dp[i][0]%=mod;
				dp[i][1]%=mod;
			} else {
				dp[i][1]=2*dp[i-1][1]+1;
				dp[i][0]=2*dp[i-1][0];
				dp[i][1]%=mod;
				dp[i][0]%=mod;
			}
		}
		printf("%I64d\n",dp[n][1]);
	}
	return 0;
}

