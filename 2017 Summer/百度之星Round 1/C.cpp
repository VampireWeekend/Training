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
const int maxn=100005,maxm=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
ll ans[maxm][11];
ll a[maxn],b[maxn],val[maxm],c[maxm];

int main() {
	int n,m,i,j,k;
	while (scanf("%d%d",&n,&m)!=EOF) {
		meminf(ans);
		for (i=1;i<=n;i++) {
			scanf("%I64d%I64d",&a[i],&b[i]);
		}
		for (i=1;i<=m;i++) {
			scanf("%I64d%I64d",&c[i],&val[i]);
		}
		for (i=0;i<=10;i++) {
			ans[0][i]=0;
			for (j=1;j<=m;j++) {
				if (val[j]>i) {
					for (k=1;k<val[j]-i;k++) {
						ans[k][i]=min(ans[k][i],c[j]);
					}
					for (k=val[j]-i;k<=1000;k++) {
						ans[k][i]=min(ans[k][i],ans[k-val[j]+i][i]+c[j]);
//						cout << ans[k][i] << endl;
					}
				}
			}
		}
		ll sum=0;
		for (i=1;i<=n;i++) {
			if (ans[a[i]][b[i]]!=llinf) sum+=ans[a[i]][b[i]];
			else {
				sum=-1;
				break;
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}

