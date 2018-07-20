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
const int maxn=333,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll a[100005];
ll l[maxn],r[maxn],mul[maxn],kuai[maxn],flag[maxn],po[maxn];
int num,block;

ll fastpower(ll base,ll index) {
	ll ans,now;
	if (index<=0) return 1;
	if (index==1) return base;
	ans=1;
	now=base;
	ll k=index;
	while (k) {
		if (k%2) ans=ans*now;
		ans%=mod;
		now=now*now;
		now%=mod;
		k/=2;
	}
	return ans;
}

void divide (int n) {                 //建块 
	block=sqrt(n);
	num=(n/block)+(n%block!=0);
	int i;
	for (i=1;i<=num;i++){               //第i个块的左界、右界 
		l[i]=(i-1)*block+1;
		r[i]=i*block;
		mul[i]=flag[i]=po[i]=1;
	}
	r[num]=n;
	for (i=1;i<=n;i++){                 //第i个元素属于第kuai[i]个块 
		kuai[i]=(i-1)/block+1;
		mul[kuai[i]]=(mul[kuai[i]]*a[i])%mod;
	}
}

void clear(int pos) {
	for (int i=l[pos];i<=r[pos];i++) {
		a[i]=fastpower(a[i],po[pos]);
		a[i]=(a[i]*flag[pos])%mod;
	}
	po[pos]=flag[pos]=1;
}

void upmul(int lc,int rc,ll k) {
	int i;
	if (kuai[lc]==kuai[rc]) {
		clear(kuai[lc]);
		for (i=lc;i<=rc;i++) {
			a[i]*=k;mul[kuai[i]]*=k;
			a[i]%=mod;mul[kuai[i]]%=mod;
		}
	} else {
		clear(kuai[lc]);clear(kuai[rc]);
		for (i=lc;i<=r[kuai[lc]];i++) {
			a[i]*=k;mul[kuai[i]]*=k;
			a[i]%=mod;mul[kuai[i]]%=mod;
		}
		for (i=l[kuai[rc]];i<=rc;i++) {
			a[i]*=k;mul[kuai[i]]*=k;
			a[i]%=mod;mul[kuai[i]]%=mod;
		}
		ll u=fastpower(k,r[i]-l[i]+1);
		for (i=kuai[lc]+1;i<=kuai[rc]-1;i++) {
			mul[i]*=u;flag[i]*=k;
			mul[i]%=mod;flag[i]%=mod;
		} 
	}
}

void uppow(int lc,int rc,ll k) {
	int i;
	if (kuai[lc]==kuai[rc]) {           //同块直接暴力，不同块左右两块暴力，中间二分 
		clear(kuai[lc]);
		for (i=lc;i<=rc;i++) {
			ll u=fastpower(a[i],k-1);
			a[i]*=u;mul[kuai[i]]*=u;
			a[i]%=mod;mul[kuai[i]]%=mod;
		}
	} else {
		clear(kuai[lc]);clear(kuai[rc]);
		for (i=lc;i<=r[kuai[lc]];i++) {
			ll u=fastpower(a[i],k-1);
			a[i]*=u;mul[kuai[i]]*=u;
			a[i]%=mod;mul[kuai[i]]%=mod;
		}
		for (i=l[kuai[rc]];i<=rc;i++) {
			ll u=fastpower(a[i],k-1);
			a[i]*=u;mul[kuai[i]]*=u;
			a[i]%=mod;mul[kuai[i]]%=mod;
		}
		for (i=kuai[lc]+1;i<=kuai[rc]-1;i++) {
			mul[i]=fastpower(mul[i],k);
			flag[i]=fastpower(flag[i],k);
			po[i]*=k;
		} 
	}
}

ll query(int lc,int rc) {
	ll ans=1;int i;
	if (kuai[lc]==kuai[rc]) {
		clear(kuai[lc]);
		for (i=lc;i<=rc;i++) {
			ans=(ans*a[i])%mod;
		}
	} else {
		clear(kuai[lc]);clear(kuai[rc]);
		for (i=lc;i<=r[kuai[lc]];i++) {
			ans=(ans*a[i])%mod;
		}
		for (i=l[kuai[rc]];i<=rc;i++) {
			ans=(ans*a[i])%mod;
		}
		for (i=kuai[lc]+1;i<=kuai[rc]-1;i++) {
			ans=(ans*mul[i])%mod;
		} 
	}
	return ans;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,q,i,L,R,o;
		scanf("%d%d",&n,&q);
		for (i=1;i<=n;i++) scanf("%lld",&a[i]);
		divide(n);
		ll k;
		for (i=1;i<=q;i++) {
			scanf("%d",&o);
			if (o==1) {
				scanf("%d%d%lld",&L,&R,&k);
				upmul(L,R,k);
			}
			if (o==2) {
				scanf("%d%d%lld",&L,&R,&k);
				uppow(L,R,k);
			}
			if (o==3) {
				scanf("%d%d",&L,&R);
				ll ans=query(L,R);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
