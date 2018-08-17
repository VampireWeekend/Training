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
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1000000007;
const ld pi=acos(-1.0L);
ll dp[maxn][maxn],p[maxn],sco[maxn],cinv[maxn];

ll fastpow(ll base,ll index) {  
    ll sum=base,ans=1;  
    ll i=index;  
    while (i) {  
        if (i%2) ans=(ans*sum)%mod;  
        sum*=sum;  
        sum=sum%mod;  
        i/=2;  
    }  
    return ans;  
}  

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	dp[0][0]=1;
	for (int i=1;i<=n;i++) {
		scanf("%lld",&p[i]);
		sco[i]=fastpow(i,m)%mod;
	}
    cinv[n]=fastpow(2,n);
	ll inv=fastpow(100,mod-2),sum=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=i;j++) {
			dp[i][j]=((dp[i-1][j-1]*p[i])%mod)*inv%mod;
			ll cost=(dp[i-1][j]*(100-p[i])%mod)*inv%mod;
			dp[i][0]+=cost;
			dp[i][0]%=mod;
			sum+=(cost*cinv[n]%mod)*sco[j]%mod;
			sum%=mod;
		}
		dp[i][0]+=(dp[i-1][0]*(100-p[i])%mod)*inv%mod;
		dp[i][0]%=mod;
	}
	for (int j=1;j<=n;j++) sum+=(dp[n][j]*cinv[n]%mod)*sco[j]%mod,sum%=mod;
	ll pinv=fastpow(2,n);
	pinv=fastpow(pinv,mod-2);
	sum=sum*pinv%mod;
	printf("%lld\n",sum);
	return 0;
}
