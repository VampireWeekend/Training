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
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll dp[1<<15],a[1<<15][15],p[1<<15][15][15];
ll d[maxn][maxn];

int main() {
	int n,i,j,k;
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		for (j=i+1;j<n;j++) {
			scanf("%I64d",&d[i][j]);
			d[j][i]=d[i][j];
		} 
	}
	dp[0]=0;
	for (i=1;i<(1<<n);i++) {
		ll cnt=0,x,y;
		for (j=0;j<n;j++) if (1==(i>>j)%2) cnt++;
		if (cnt==1) continue;
		dp[i]=llinf;
		x=y=-1;
		for (j=0;j<n;j++) {
			if (0==(i>>j)%2) continue;
			for (k=0;k<n;k++) {
				if (k==j) continue;
				if (0==(i>>k)%2) continue;
				ll nc=dp[i^(1<<j)]+(cnt-1)*d[j][k]+a[i^(1<<j)][k];
				if (nc<dp[i]) {
					dp[i]=nc;x=j;y=k;
				}
			}
		}
		a[i][x]=(cnt-1)*d[x][y]+a[i^(1<<x)][y];
		for (j=0;j<n;j++) {
			if (0==(i>>j)%2) continue;
			if (j==x) continue; 
			p[i][x][j]=p[i^(1<<x)][j][y]+d[x][y];
		}
		for (j=0;j<n;j++) {
			if (0==(i>>j)%2) continue;
			if (j==x) continue;
			a[i][j]=a[i^(1<<x)][j]+p[i^(1<<x)][j][y]+d[x][y];
			for (k=0;k<n;k++) {
				if (0==(i>>j)%2) continue;
				if (j==k) continue;
				if (k!=x) p[i][j][k]=p[i^(1<<x)][j][k]; 
					else p[i][j][k]=p[i^(1<<x)][j][y]+d[x][y];
			}
		}
	}
	printf("%I64d\n",dp[(1<<n)-1]);
	system("pause");
	return 0;
}
