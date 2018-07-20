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
typedef unsigned long long ll;
typedef long double ld;
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);

ll gcd(ll a,ll b) {
	ll x,y,z;
	x=a;y=b;
	if (y>x) {
		z=y;y=x;x=z;
	}
	while (y) {
		z=y;y=x%y;x=z;
	}
	return x;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int i;
		ll n,m,u;
		cin >> n >> m;
		ll l=n+m,p=n;
		u=gcd(l,p);
		l/=u;p/=u;
		ll totl,totp;
		totl=l;totp=p;
		for (i=2;i<=m;i+=2) {
			l*=(n+m-i)*(n+m-i+1);
			p*=(m-i+1)*(m-i+2);
			ll u=gcd(l,p);
			l/=u;
			p/=u;
			ll t=gcd(l,totl);
			totl=totl/t*l;
			totp*=(l/t);
    		totp+=(p*totl/l);
    		u=gcd(totl,totp);
    		totl/=u;totp/=u;
		}
		cout << totp << '/' << totl << endl;
  //}
	}
	return 0;
}

