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
const int maxn=4,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int i;
	ll n;
	cin >> n;
	if (n<4) cout << n; else {
		ll l=1,ans=1;
		while (l<n) {
			l*=2;
			ans++;
		}
		cout << ans;
	}
	return 0;
}
