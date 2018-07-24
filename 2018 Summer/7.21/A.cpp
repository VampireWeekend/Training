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
const int maxn=100005,inf=0x3f3f3f3f,mod=1e9+7;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll dp[maxn][2];

int main() {
	int q,k,i;
	scanf("%d%d",&q,&k);
	dp[0][0]=0;dp[0][1]=1;
	for (i=1;i<=100000;i++) {
		if (i>=k) {
			dp[i][0]=dp[i-k][1];
		}
		dp[i][1]=dp[i-1][0]+dp[i-1][1];
		dp[i][0]%=mod;dp[i][1]%=mod;
	}
	dp[0][1]=0;
	for (i=2;i<=100000;i++) {
		dp[i][0]=(dp[i][0]+dp[i-1][0])%mod;
		dp[i][1]=(dp[i][1]+dp[i-1][1])%mod;
	}
	while (q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		ll ans=(dp[r][0]-dp[l-1][0]+mod)%mod;
		ans+=(dp[r][1]-dp[l-1][1]+mod)%mod;
		ans%=mod; 
		printf("%lld\n",ans);
	}
	return 0;
}
