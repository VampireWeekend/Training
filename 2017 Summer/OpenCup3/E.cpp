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
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);  
ll dp[maxn][11],sum[maxn][11];
char a[maxn],b[15];
vector<int> v['z'+1];

int main() {
	int n,m,k,i,j;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",a+1);
	scanf("%s",b+1);
	mem0(dp);mem0(sum);
	for (i=1;i<=m;i++) {
		v[b[i]].push_back(i);
	}
	sum[0][0]=1;
	for (i=1;i<=n;i++) {
		for (j=0;j<v[a[i]].size();j++) {
			int pos=v[a[i]][j];
			if (pos==m) {
				if (i-k>0) dp[i][pos]+=sum[i-k][j-1];
				dp[i][pos]%=mod;
			} else {
				dp[i][pos]+=sum[i-1][j-1];
				dp[i][pos]%=mod;
			}
		}
		for (j=1;j<=m;j++) {
			sum[i][j]=sum[i-1][j]+dp[i][j];
			sum[i][j]%=mod;
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}

