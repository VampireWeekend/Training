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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ll m,n,t;
	int i;
	cin >> m >> n >> t;
	int flag=0;
	if (t==1) {
		ll l=1;
		for (i=1;i<=n&&l<=1e9&&l<=m;i++) {
			l*=(ll)i;
		}
		if (i==n+1&&l<=m) flag=1;
	}
	if (t==2) {
		ll l=1;
		for (i=1;i<=n&&l<=1e9&&l<=m;i++) {
			l*=(ll)2;
		}
		if (i==n+1&&l<=m) flag=1;
	}
	if (t==3) {
		if (n*n<=1e9) 
		if (n*n*n<=1e9)
		if (n*n*n*n<=1e9)
		if (n*n*n*n<=m) flag=1;
	}
	if (t==4) {
		if (n*n<=1e9) 
		if (n*n*n<=1e9)
		if (n*n*n<=m) flag=1;
	}
	if (t==5) {
		if (n*n<=m) flag=1;
	}
	if (t==6) {
		ld f,p=(ld)m;
		f=(ld)n*log2l((ld)n);
		if (f<=m) flag=1;
	}
	if (t==7) {
		if (n<=m) flag=1;
	}
	if (flag) cout << "AC"; else cout << "TLE";
	return 0;
}
