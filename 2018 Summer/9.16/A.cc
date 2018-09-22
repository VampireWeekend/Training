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
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);

int main() {
	int cas;
	scanf("%d",&cas);
	int n,m,ans;
	while (cas--) {
		scanf("%d%d",&n,&m);
		printf("%d ",m);
		if (m==0) {
			ans=0;
		} else
		if (n==m) {
			ans=m;
		} else if (n-m>=m-1) {
			ans=1;
		} else {
			int t=n-m+1;
			ans=m/t;
			if (m%t!=0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
