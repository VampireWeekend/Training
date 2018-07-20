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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll sum[maxn],dp[maxn],q[maxn],pos[maxn]; 

ll returnx(ll j,ll k) {
	return j-k;
}

ll returny(ll j,ll k) {
	return sum[j]-sum[k];
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j,l,h,t;
		char c;
		scanf("%d%d",&n,&l);
		getchar();
		sum[0]=dp[0]=0;
		for (i=1;i<=n;i++) {
			scanf("%c",&c);
			sum[i]=sum[i-1]+c-'0';
		}
		h=1;t=0;q[0]=0;
		mem0(q);
		for (i=l;i<=n;i++) {
			while (t+1<h&&(sum[i]-sum[q[t+1]])*(i-q[t])>=(sum[i]-sum[q[t]])*(i-q[t+1]))
			    t++;
			dp[i]=sum[i]-sum[q[t]];
			pos[i]=q[t];
			while (t+1<h&&(returny(q[h-1],q[h-2])*returnx(i-l+1,q[h-1])>=returny(i-l+1,q[h-1])*returnx(q[h-1],q[h-2]))) 
				h--;
			q[h]=i-l+1;
			h++;
		}
		ll ans=l;
		for (i=l+1;i<=n;i++) {
			if (dp[i]*(ans-pos[ans])>dp[ans]*(i-pos[i])||
			(dp[i]*(ans-pos[ans])==dp[ans]*(i-pos[i])&&i-pos[i]<ans-pos[ans]))
			ans=i;
		}
		printf("%lld %lld\n",pos[ans]+1,ans);
	}
	return 0;
}

