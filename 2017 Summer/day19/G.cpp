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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=3005,maxk=3005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
ld dp[maxn][maxk];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j,t;
		scanf("%d",&n);
		mem0(dp);
		dp[0][0]=1L;
		ld ans=0L,fac=1L;
		for (i=1;i<n/2;i++) {
			fac*=(ld)i;
		}
		for (t=1;t<=3000;t++) {
			for (i=0;i<n;i++) {
				dp[t][i]+=dp[t-1][i]*(ld)i/(ld)n;
				dp[t][i+1]+=dp[t-1][i]*(ld)(n-i)/(ld)n;
	//			cout << dp[t][i] << endl;
			}
			ans+=fac*dp[t][n]*t;
	//	    cout << ans << endl;
		}
		for (i=n/2;i<n;i++) {
			ans*=(ld)i;
		}
		cout << setiosflags(ios::fixed) << setprecision(1);
		cout << ans << endl;
	}
	return 0;
}
