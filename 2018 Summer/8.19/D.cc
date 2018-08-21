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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int w[maxn],dfn[maxn];
ll fac[maxn],inv[maxn];

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
//组合数公式
ll lukas(ll n,ll m){  
    if (n<m) {  
        return 0;  
    } else return fac[n]*(fastpow((fac[m]*fac[n-m])%mod,mod-2)%mod)%mod;  
}  

int main() {
	fac[1]=1;
	for (i=2;i<=200000;i++) {
		fac[i]=(fac[i-1]*i)%mod;
	}
	inv[n]=fastpow(fac[n],mod-2);  
    for (i=200000-1;i>=0;i--) {  
        inv[i]=inv[i+1]*(i+1);  
        inv[i]%=mod;  
    }  
    int cas;
	scanf("%d",&cas);
while (cas--) {
	ll n,op,m=0,cnt=0,l,r,y;
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&op);
		if (op==1) {
			scanf("%lld",&y);
			w[++m]=y;dfn[m]=cnt;
		} else if (op==2){ 
			cnt++;
		} else {
			ll ans=0;
			scanf("%lld%lld",&l,&r);
			for (int j=1;j<=m;j++) {
				ans+=
			}
			printf("%lld\n",ans);
		}
	}
}
	return 0;
}