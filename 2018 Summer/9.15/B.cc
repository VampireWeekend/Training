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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll dp[maxn][6],dp2[maxn][6];
ll a[maxn];
char s[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		ll n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		for (int i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
		}
		scanf("%s",s+1);
		for (int i=0;i<=n;i++) {
			for (int j=0;j<=m;j++) dp[i][j]=-1e18-1;dp2[i][j]=1e18+1;
		}
		dp[0][0]=k;dp2[0][0]=k;
		for(ll i=1;i<=n;i++) {
			for (ll j=0;j<=min(i,m);j++) {
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				if (j!=0) {
					if (s[j]=='+') dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]); else
					if (s[j]=='-') dp[i][j]=max(dp[i][j],dp[i-1][j-1]-a[i]); else
					if (s[j]=='*') dp[i][j]=max(dp[i][j],dp[i-1][j-1]*a[i]); else
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]/a[i]);
					if (s[j]=='+') dp[i][j]=max(dp[i][j],dp2[i-1][j-1]+a[i]); else
					if (s[j]=='-') dp[i][j]=max(dp[i][j],dp2[i-1][j-1]-a[i]); else
					if (s[j]=='*') dp[i][j]=max(dp[i][j],dp2[i-1][j-1]*a[i]); else
						dp[i][j]=max(dp[i][j],dp2[i-1][j-1]/a[i]);
					if (s[j]=='+') dp2[i][j]=min(dp2[i][j],dp2[i-1][j-1]+a[i]); else
 					if (s[j]=='-') dp2[i][j]=min(dp2[i][j],dp2[i-1][j-1]-a[i]); else
 					if (s[j]=='*') dp2[i][j]=min(dp2[i][j],dp2[i-1][j-1]*a[i]); else
 						dp2[i][j]=min(dp2[i][j],dp2[i-1][j-1]/a[i]);
					if (s[j]=='+') dp2[i][j]=min(dp2[i][j],dp[i-1][j-1]+a[i]); else
	 				if (s[j]=='-') dp2[i][j]=min(dp2[i][j],dp[i-1][j-1]-a[i]); else
	 				if (s[j]=='*') dp2[i][j]=min(dp2[i][j],dp[i-1][j-1]*a[i]); else
	 					dp2[i][j]=min(dp2[i][j],dp[i-1][j-1]/a[i]);
				}
			}
		}
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}
