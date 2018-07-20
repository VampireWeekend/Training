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
const int maxn=100,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

int sqr(int x) {
	return x*x;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int a,b,c,x,y,z,d,e,f;
	cin >> x >> y >> z >> a >> b >> c >> d >> e >> f;
	if (x>=a&&x<=d&&y>=b&&y<=e&&z>=c&&z<=f) {
		cout << 0 << endl;
	} else {
		int ans=0;
		if (!(x>=a&&x<=d)) ans+=sqr(min(abs(x-a),abs(x-d)));
		if (!(y>=b&&y<=e)) ans+=sqr(min(abs(y-b),abs(y-e)));
		if (!(z>=c&&z<=f)) ans+=sqr(min(abs(z-c),abs(z-f)));
		cout << ans << endl;
	}
	return 0;
}

