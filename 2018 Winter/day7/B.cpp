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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll rem[maxn],a[maxn],p[maxn],cp[maxn];
char s[maxn];
map<char,int> mp;

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
    } else return p[n]*(fastpow((p[m]*p[n-m])%mod,mod-2)%mod)%mod;  
}  

int main() {
	ll n=0,i,j,k;
	p[0]=1;
	for (i=1;i<=100;i++) p[i]=(p[i-1]*i)%mod;
	mp['A']=1;mp['J']=11;mp['Q']=12;mp['K']=13;
	for (i=2;i<=9;i++) mp[(char)('1'+i-1)]=i;
	string ss;
while (getline(cin,ss)) {
mem0(rem);mem0(a);mem0(cp);
	ll ans=0,len=ss.length();
	for (i=1;i<=len;i++) {
		s[i]=ss[i-1];
	}n=0;
	for (i=1;i<=len;i++) {
		n++;
		if (s[i]=='1') {
			if (s[i+1]=='0') {
				i++;
				a[n]=10;
				rem[10]++;
				continue;
			}
		}
		rem[mp[s[i]]]++;
		a[n]=mp[s[i]];
	}
	ll tot=0,fuck,flag=1;
	for (i=1;i<=13;i++) {
		rem[i]=4-rem[i];
		cp[i]=rem[i];
		tot+=rem[i];
	}
	if (tot<n) {
		int flag=0;
		for (i=1;i<=tot;i++) {
			cp[a[i]]--;
			if (cp[a[i]]<0) flag=1;
		}
		if (!flag) ans++;
	}
	for (i=1;i<=n;i++) {
		ll sum=0;
		for (j=1;j<a[i];j++) {
			if (rem[j]<=0) continue;
			ll na=1,q=tot-1;
			rem[j]--;
			for (k=1;k<=13;k++) {
				na*=lukas(q,rem[k]);
				na%=mod;
				q-=rem[k];
			}
			rem[j]++;
			ans+=na;
			ans%=mod;
		}
		tot--;rem[a[i]]--;
		if (rem[a[i]]<0)
			break;
	}
	printf("%lld\n",ans);
}
return 0;
}

