#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxn=100005; 
int a[maxn][11],b[maxn];
ll c[(1<<10)+5],d[maxn];

int main() {
	int n,m,q,i,j;
	ld k;
	scanf("%d%d",&n,&m);
	memset(c,0,sizeof(c));
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i][0]);
		b[i]=0;
		for (j=1;j<=a[i][0];j++) {
			scanf("%d",&a[i][j]);
			b[i]+=(1<<(a[i][j]-1));
		}
		c[b[i]]++;
	}
	cin >> k;
	ll ans=0;
	for (i=1;i<=1023;i++) {
		int l=i;
		d[i]=0;
		while (l>0) {
			if (l%2) d[i]++;
			l/=2;
		}
	}
	for (i=1;i<=1023;i++) {
		for (j=i;j<=1023;j++) {
			int q=i&j,w=i|j;
			ld ratio=(ld)d[q]/(ld)d[w];
			if (ratio>=k) {
				if (i!=j) ans+=c[i]*c[j]; else ans+=c[i]*(c[i]-1)/2;
			}
		}
	}
	printf("%lld\n",ans);
}
