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
ll num[105];

ll convert(ll n,ll k) {
	if (n==0) return 0;
	ll i=n,len=0,cnt=0,l;
	while (i) {
		num[len++]=i%k;
		i/=k;
	}
	ll p=0,sum=1,base=k;
	for (i=1;i<len;i++) {
		cnt+=base-sum;
		if (i%2==0) {
			sum=base;
			base*=k;
		}
	}
	for (i=len-1;i>=len/2;i--) {
		p=p*k+num[i];
	}
	l=p;
	ll o;
	if (len%2) o=len/2+1; else o=len/2;
	for (i=o;i<len;i++) {
		p=p*k+num[i];
	}
	if (p>n) cnt+=l-sum; else cnt+=l-sum+1;
	return cnt*(k-1)+n;
}

int main() {
	int cas,q=0;
	scanf("%d",&cas);
	while (cas--) {
		ll l,r,k,p,i,j;
		q++;
		ll sum=0;
		scanf("%lld%lld%lld%lld",&l,&r,&k,&p);
		for (i=k;i<=p;i++) {
			sum+=convert(r,i);
			sum-=convert(l-1,i);
		}
		printf("Case #%d: %lld\n",q,sum);
	}
	return 0;
}

