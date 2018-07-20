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
const int maxn=101,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],b[maxn],dp[maxn][100001],pre[maxn][100001];

int main() {
	int n,i,j,k,sum=0,ans=0;
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for (i=0;i<n;i++) {
		for (j=0;j<=sum;j++) {
			if (dp[i][j]==-1) continue;
			if (dp[i][j]>dp[i+1][j+a[i]/100]) {
				dp[i+1][j+a[i]/100]=dp[i][j];
				pre[i+1][j+a[i]/100]=j;
			}
			if (dp[i][j]+min(j,a[i])>dp[i+1][j-min(j,a[i])]) {
				dp[i+1][j-min(j,a[i])]=dp[i][j]+min(j,a[i]);
				pre[i+1][j-min(j,a[i])]=j;
			}
		}
		sum+=a[i]/100;
	}
	ans=k=-1;
	for (i=0;i<=sum;i++) {
		if (dp[n][i]>ans) {
			ans=dp[n][i];
			k=i;
		}
	}
	if (n==1) {
		printf("%d\n%d + 0\n",a[0],a[0]);
		return 0;
	}
	printf("%d\n",sum*100-ans);
	for (i=n-1;i>0;i--) {
		b[i+1]=dp[i+1][k]-dp[i][pre[i+1][k]];
		k=pre[i+1][k];
	}
	for (i=1;i<=n;i++) {
		printf("%d + %d\n",a[i-1]-b[i],b[i]);
	}
	return 0;
}
