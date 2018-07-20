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
const int maxn=50005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=3.1415926535898L;
int dp[maxn],v[25],s[25];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int ans,i,j,k,y,n,m,x,r;
		scanf("%d%d",&n,&y);
		scanf("%d",&m);
		x=inf;
		for (i=1;i<=m;i++) {
			scanf("%d%d",&s[i],&v[i]);
			s[i]/=1000;
			x=min(x,s[i]);
		}
		for (i=1;i<=y;i++) {
			mem0(dp);
			ans=0;
			for (j=x;j<=n/1000;j++) {
				for (k=1;k<=m;k++) {
					if (j>=s[k]) 
					    dp[j]=max(dp[j],dp[j-s[k]]+v[k]);
				}
				ans=max(ans,dp[j]);
			}
			n+=ans;
		}
		printf("%d\n",n);
	}
	return 0;
}
