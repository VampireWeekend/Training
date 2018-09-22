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
int cnt[105];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,x;
		scanf("%d",&n);
		mem0(cnt);
		for (int i=1;i<=n;i++) {
			scanf("%d",&x);
			int num=0;
			while (x) {
				num++;
				x/=2;
			}
			cnt[num]++;
		}
		int ans=-inf;
		for (int i=1;i<=40;i++) {
			ans=max(ans,cnt[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
