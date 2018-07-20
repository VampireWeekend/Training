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
const int maxn=10555,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ll n,m;
	ll x,y;
	ll k;
while (scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&k,&x,&y)!=EOF) {
	ll ans;
	if (n==1) {
		if (k<=m) ans=1; else ans=(k-1)/m+1;
		printf("%I64d ",ans);
		ans=k/m;
		printf("%I64d ",ans);
		if (k<y) ans=0; else ans=(k-y)/m+1;
		printf("%I64d\n",ans);
		continue;
	}
	if (n==2) ans=(k-1)/(m*2)+1; else
	if (k<=n*m) ans=1; else {
		ans=(k-1-n*m)/((n-1)*m)+2;
	}
	printf("%I64d ",ans);
	if (k<n*m) ans=0; else {
		ans=(k-n*m)/(2*(n-1)*m)+1;
	}
	printf("%I64d ",ans);
	if (x==n) {
	    if (k<y+(n-1)*m) ans=0; else 
		    ans=(k-y-(n-1)*m)/(2*(n-1)*m)+1;
	} else if (x==1) {
		if (k<y) ans=0; else 
		    ans=(k-y)/(2*(n-1)*m)+1;
	} else {
		ll u=k/((n-1)*m);
		k=k-u*(n-1)*m;
		if (u%2) {
			if (k>=(n-x)*m+y) ans=u+1; else ans=u;
		} else {
			if (k>=(x-1)*m+y) ans=u+1; else ans=u;
		}
	}
	printf("%I64d\n",ans);
}
	return 0;
}

