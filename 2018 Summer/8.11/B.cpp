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
#define N 300005
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
ll p[N],inv[N],po[N];

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
	ll n,ans=0,sum=0;po[0]=1;
	p[0]=1;
	scanf("%lld",&n);
    n--;
	for (ll i=1;i<=n;i++) {
		p[i]=(p[i-1]*i)%mod;
		po[i]=(po[i-1]*2)%mod;
	}
	int cnt=0;
	inv[n]=fastpow(p[n],mod-2);  
    for (ll i=n-1;i>=0;i--) {  
        inv[i]=inv[i+1]*(i+1);  
        inv[i]%=mod;  
    }  
	for (ll i=1;i<=n;i++) {
		ans=p[n]*p[n]%mod;
		ans*=(po[i]*inv[i]%mod)*inv[n-i]%mod;
		ans%=mod;
		ans*=(inv[i-1]%mod)*inv[n-i+1]%mod;
		ans%=mod;
		sum+=ans;
		sum%=mod;
 //       cout << ans << endl;
	}
    sum = sum * fastpow(n, mod-2);
    sum%=mod;
    if (n==0) sum=1;
	printf("%lld\n",sum);
	return 0;
}