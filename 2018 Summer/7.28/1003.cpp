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
ll dp[75][2][150],num[100];

ll dfs(ll len,ll last,ll sum,bool HaveLimit,bool zero) {
	if (!len)
	    if (!zero) return 0; else return abs(sum);
	if (!HaveLimit&&dp[len][last][sum+64]!=-1&&zero)
	    return dp[len][last][sum+64];

	int limit,i,ext;
	if (HaveLimit) limit=num[len]; else limit=1;
	ll ans=0;
	for (i=0;i<=limit;i++) {
		if (!zero) ext=0; else if (i==last) ext=1; else ext=-1;
		ans+=dfs(len-1,i,sum+ext,HaveLimit&&i==limit,zero|i);
		ans%=mod;
	}
	if (!HaveLimit&&zero) dp[len][last][sum+64]=ans;
	return ans;
}

ll solve(ll limit) {
	if (limit==-1) return 0;
	ll k=limit,cnt=0;
	while (k>0) {
		cnt++;
		num[cnt]=k%2;
		k/=2;
	}
	ll ans=0;
	ans=dfs(cnt,2,0,1,0);
	return ans;
}

int main() {
	int cas;
	scanf("%d",&cas);
	memset(dp,-1,sizeof(dp));
	while (cas--) {
		ll n;
		scanf("%lld",&n);
		ll ans=solve(n);
		printf("%lld\n",ans);
	}
	return 0;
}
