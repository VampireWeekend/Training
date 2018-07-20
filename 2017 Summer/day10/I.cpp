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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ll a[maxn],sm[maxn],bg[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,i,j,ans=0;
	scanf("%d",&n);
	sm[0]=-llinf;
	bg[n+1]=llinf;
	for (i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		sm[i]=max(sm[i-1],a[i]);
	}
	for (i=n;i>=1;i--) {
		bg[i]=min(bg[i+1],a[i]);
	}
	for (i=1;i<=n;i++) {
		if (sm[i-1]<=a[i]&&bg[i+1]>a[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
