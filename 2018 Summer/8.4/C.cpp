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
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=998244353;
const ld pi=acos(-1.0L);
ll p[1000005],inv[maxn];

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
	ll n,m,ans,cas;
	scanf("%lld",&cas);
	p[0]=1;
	for (ll i=1;i<=1000000;i++) {
		p[i]=(p[i-1]*i)%mod;
	}
	int cnt=0;
	inv[n]=fastpow(fac[n],mod-2);  
    for (i=n-1;i>=0;i--) {  
        inv[i]=inv[i+1]*(i+1);  
        inv[i]%=mod;  
    }  
while (cas--) {
	scanf("%lld%lld",&n,&m);
	ll base=m%mod;
	n%=mod;m%=mod;
	ans=0;
	for (ll i=1;i<=min(m,n);i++) {
		ans+=base*inv[i-1]%mod;
		ans%=mod;
		base=(base*((n-i+mod)%mod))%mod;
		base=(base*((m-i+mod)%mod))%mod;
	}
	cnt++;
	printf("Case #%d: %lld\n",cnt,ans);
}
	return 0;
}
