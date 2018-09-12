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
int len[maxn],last[maxn];
map<ll,int> mp;

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int n,ans=0,m=0,k;
		ll x,y;
		scanf("%d",&n);
		mp.clear();
		mem0(len);
		memset(last,-1,sizeof(last));
		for (int i=1;i<=n;i++) {
			scanf("%d",&k);
			for (int j=1;j<=k;j++) {
				scanf("%lld%lld",&x,&y);
				x=x*1e10+y;
				if (mp.find(x)==mp.end()) {
					m++;
					mp[x]=m;
				}
				int pos=mp[x];
				if (last[pos]==i) continue;
					else if (last[pos]==i-1) len[pos]++; else len[pos]=1;
				ans=max(ans,len[pos]);
				last[pos]=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
