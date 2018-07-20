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
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
ll a[maxn],b[maxn];
int m;

ll getsg(ll p) {
	ll n=p;
	int k,i;
	for (i=1;i<=m;i++) {
		if (b[i+1]>n) break; 
	}
	k=i;
	if (b[i+1]==n+1) return 0;
	while (((n-b[k])/2)%2!=0) {
		n/=2;
		k--;
	}
	return (b[k]/4)+(n-b[k])/4;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas;
	ll i;
	map<ll,int> sg;
	scanf("%d",&cas);
	for (i=1;i<=2e18;i=i*2+1) {
		sg[i]=1;
	}
	m=0;
	for (i=2;i<=2e18;i*=2) {
		b[++m]=i;
	}
	b[++m]=i;
	while (cas--) {
		int n,j;
		scanf("%d",&n);
		ll sum=0;
		for (i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			if (a[i]%2==0) sum=sum^(a[i]/2); else {
		//		cout << a[i] << ' ' << getsg(a[i]);
				sum=sum^(getsg(a[i]));
			}
		}
		if (sum!=0) cout << "YES" << endl; 
		else cout << "NO" << endl;
	}
	return 0;
}

