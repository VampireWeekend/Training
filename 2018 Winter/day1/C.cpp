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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];
db c[maxn],w[maxn];

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int i,j,ans,n;
		scanf("%d",&n);
		mem0(a);
		ans=0;
		for (i=1;i<=n;i++) {
			scanf("%lf%lf",&w[i],&c[i]);
			a[i]=1;
			for (j=1;j<i;j++) {
				if (w[j]<w[i]&&c[j]>c[i]) a[i]=max(a[i],a[j]+1);
			}
			ans=max(ans,a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
