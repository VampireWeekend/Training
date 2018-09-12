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
int dp[maxn][205];
int b[maxn],c[maxn],d[maxn];

int main() {
	int n,m,k,l;
	scanf("%d%d%d%d",&n,&m,&k,&l);
	m+=100;k+=100;l+=100;
	for (int i=1;i<=n;i++) {
		scanf("%d%d%d",&b[i],&c[i],&d[i]);
	}
	for (int j=0;j<=l;j++) dp[n+1][j]=0;
	for (int j=l+1;j<k;j++) dp[n+1][j]=1;
	for (int j=k;j<=200;j++) dp[n+1][j]=2;
	for (int i=n;i>=1;i--) {
		if (i%2==0) {
			for (int j=0;j<=200;j++) dp[i][j]=3;
		} else for (int j=0;j<=200;j++) dp[i][j]=-1;
		if (b[i]!=0) {
			if (i%2==0)
				for (int j=0;j<=200;j++) dp[i][j]=min(dp[i][j],dp[i+1][min(j+b[i],200)]);
			else
				for (int j=0;j<=200;j++) dp[i][j]=max(dp[i][j],dp[i+1][min(j+b[i],200)]);
		}
		if (c[i]!=0) {
			if (i%2==0)
				for (int j=0;j<=200;j++) dp[i][j]=min(dp[i][j],dp[i+1][max(j-c[i],0)]);
			else
				for (int j=0;j<=200;j++) dp[i][j]=max(dp[i][j],dp[i+1][max(j-c[i],0)]);
		}
		if (d[i]!=0) {
			if (i%2==0)
				for (int j=0;j<=200;j++) dp[i][j]=min(dp[i][j],dp[i+1][200-j]);
			else
				for (int j=0;j<=200;j++) dp[i][j]=max(dp[i][j],dp[i+1][200-j]);
		}
	}
	assert(dp[1][m]>=0&&dp[1][m]<=2);
	if (dp[1][m]==0) {
		printf("Bad Ending\n");
	} else if (dp[1][m]==1) printf("Normal Ending\n"); else printf("Good Ending\n");
	return 0;
}
