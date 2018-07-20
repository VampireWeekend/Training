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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],dp[maxn][maxn],b[maxn];

int main() {
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	b[1]=m;
	mem0(dp);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (i!=1) {
			b[i]=b[i-1]/3*2;
			if (b[i-1]%3==2) b[i]++;
		}
	}
	int ans=0;
	for (i=1;i<=n;i++) {
		for (j=1;j<=i;j++) {
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]+min(b[j],a[i]));
			if (i>1)
				dp[i][j]=max(dp[i][j],dp[i-2][j]+min(b[j],a[i]));
			if (i>2&&j==1)
			for (k=1;k<=i-3;k++)
				dp[i][j]=max(dp[i][j],dp[i-3][k]+min(m,a[i]));
			ans=max(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
