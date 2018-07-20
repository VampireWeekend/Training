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
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[maxn],v[maxn],dp[1000005];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j,sum=0,p=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		mem0(dp);
		for (i=1;i<=n;i++) {
			dp[i]=a[i];
			for (j=1;j<i;j++) {
				if (a[j]<=a[i])
				    dp[i]=max(dp[i],dp[j]+a[i]);
			}
			p=max(p,dp[i]);
		}
		printf("%d\n",sum-p);
	}
	return 0;
}

