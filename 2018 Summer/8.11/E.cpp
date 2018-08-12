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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],b[maxn],c[maxn],d[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=k;i++) {
			scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		}
		if (n%2==0||m%2==0) printf("%d\n",n*m); else {
			int ans=n*m+1;
			for (int i=1;i<=k;i++) 
                if ((a[i]+b[i])%2==0&&(c[i]+d[i])%2==0&&(a[i]!=c[i]||b[i]!=d[i])) ans=n*m;
			printf("%d\n",ans);
		}
	}
	return 0;
}
