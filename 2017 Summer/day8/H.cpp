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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ll dp[maxn];

struct wave {
	int t,w;
	ll v;
};
wave a[maxn];

bool cmp(wave a,wave b) {
	return a.t<b.t;
}

int main() {
	int n,i,j,k;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d%lld%d",&a[i].t,&a[i].v,&a[i].w);
	}
	mem0(dp);
	sort(a+1,a+n+1,cmp);
	k=1;
	ll ans=0;
	for (i=1;i<=1000000;i++) {
		dp[i]=max(dp[i],dp[i-1]);
		while (a[k].t==i&&k<=n) {
			if (i+a[k].w<=1000000) dp[i+a[k].w]=max(dp[i+a[k].w],dp[i]+a[k].v);
			ans=max(ans,dp[i]+a[k].v);
			k++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
