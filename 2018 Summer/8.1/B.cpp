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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const ld pi=acos(-1.0L);
ll c[maxn][maxn],sum[maxn][maxn];

int main() {
	int i,j,n,m;
	c[0][0]=1;
	for (i=1;i<=1000;i++) {
		c[i][0]=c[i][i]=1;
		for (j=1;j<i;j++) {
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
		sum[i][0]=1;
		for (j=1;j<=i;j++) {
			sum[i][j]=(c[i][j]+sum[i][j-1])%mod;
 //           if (i==5)cout << sum[i][j] << ' ' << endl;
		}
	}
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		scanf("%d%d",&n,&m);
		printf("%lld\n",sum[n][m]);
	}
	return 0;
}
