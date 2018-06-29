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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const ld pi=acos(-1.0L);
ll a[maxn],dp[maxn][maxn][2];

ll getsum(ll n,ll rem) {
	if (rem==0) return 0;
	if (rem>a[n]/2)
		return dp[n][n-1][0]+getsum(n-1,rem-a[n]/2);
	else 
		return getsum(n-1,rem);
}

int main() {
	ll m;
	a[1]=1;
	for (int i=2;i<=100;i++) {
		a[i]=a[i-1]*2;
		if (a[i]>1e18) {
			m=i;break;
		}
	}
	dp[2][1][0]=dp[2][1][1]=1;dp[2][2][0]=dp[2][2][1]=2;
	for (int i=3;i<=m;i++) {
		dp[i][1][0]=(i-1)%mod;
		dp[i][1][1]=(i-1)%mod;
		for (int j=2;j<=i-1;j++) {
			for (int k=0;k<2;k++) {
				dp[i][j][k]=(dp[i-2][j-1][k]+dp[i][j-1][k])%mod;
			}
		}
		dp[i][i][0]=dp[i][i][1]=(dp[i][i-1][0]+dp[i][i-1][1])%mod;
	}
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		ll n,ans,p=-1;
		scanf("%lld",&n);
		for (int i=m;i;i--) {
			if (n>=a[i]) {
				ans+=dp[i][i-1][0]+dp[i][i-1][1];
				ans%=mod;
				n-=a[i];
				p=max(p,(ll)i);
			}
		}
		ans+=getsum(p+1,n);ans%=mod;
		printf("%lld\n",ans);
	}
	return 0;
}
