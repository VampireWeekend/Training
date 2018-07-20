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
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int num[20];
ll dp[20][2];

ll dfs(int len,bool pre,bool HaveLimit) {
	if (len==0) return 1;
	if (dp[len][pre]!=-1&&!HaveLimit) 
	    return dp[len][pre];
	
	int l=HaveLimit?num[len]:9;
	ll ans=0;
	for (int i=0;i<=l;i++) {
	    if (i==3&&pre) continue;
	    ans+=dfs(len-1,i==1,HaveLimit&&i==num[len]);
	}
	if (!HaveLimit) dp[len][pre]=ans;
	return ans;
}

ll solve(ll n) {
	ll k=n;
	int i=0;
	while (k) {
		num[++i]=k%10;
		k/=10;
	} 
	ll ans=dfs(i,0,1);
	return ans-1;
}

int main() {
//	freopen("hotel.in","r",stdin);
//	freopen("hotel.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	memset(dp,-1,sizeof(dp));
	while (cas--) {
		ll n,i,l,r,mid;
		scanf("%lld",&n);
		l=1;r=15e17;
		while (l<=r) {
			mid=(l+r)/2;
			ll f=solve(mid);
	//		cout << mid << ' ' << f << endl;
			if (f>=n) r=mid-1; else 
			    if (f<n) l=mid+1;
		}
		while (solve(mid-1)>=n) mid--;
		while (solve(mid)<n) mid++;
		printf("%lld\n",mid);
	}
	return 0;
}

