#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll b[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j;
		ll m,x;
		scanf("%d%lld",&n,&m);
		for (int i=1;i<=n;i++) {
			scanf("%lld %lld",&x,&b[i]);
		}
		sort(b+1,b+n+1);
		ll cnt=0,base=1;
		for (int i=1;i<=n;i++) {
			base*=(b[i]+1);
			if (base>m) break;
			cnt++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
