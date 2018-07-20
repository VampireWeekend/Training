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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

int main() {
	int mi,ma,i,x,n,k;
	cin >> n >> k;
	string s;
	ma=1;mi=k;
	for (i=1;i<=n;i++) {
		cin >> x >> s;
		if (s=="SAFE") {
			ma=max(ma,x);
		} else {
			mi=min(mi,x);
		}
	}
	int a,b;
	a=min(ma+1,mi);
	b=max(mi-1,ma);
	cout << a << ' ' << b;
	return 0;
}
