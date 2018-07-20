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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=53,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=3.1415926535898L;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas,cnt=0;
	cin >> cas;
	while (cas--) {
		ld a,b;
		cnt++;
		cin >> a >> b;
		ld ans=a*sin(pi/b)/(1L+sin(pi/b));
		printf("Case %d: ",cnt);
		cout << setiosflags(ios::fixed) << setprecision(9);
		cout << ans << endl;
	}
	return 0;
}

