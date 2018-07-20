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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=1e18;   
const ld pi=acos(-1.0L);  

ll sqr(ll r) {
	return r*r;
}

int main() {
	ll a,b,n,i,ans=0,k;
	scanf("%lld%lld%lld",&k,&a,&b);
	for (i=1;i<=1539;i++) {
		ll p=k*i,sum=0;
		if (p>llinf) break;
		if (p<a||p>b) continue;
		while (p) {
		    sum+=sqr(p%10);
		    p/=10;
		}
		if (sum==i) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

