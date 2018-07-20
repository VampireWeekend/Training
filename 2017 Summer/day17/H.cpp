#include <cstdio>
#include <iostream>
#include <algorithm>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
const int maxn=250005,inf=0x3f3f3f3f,mod=1e9+7;
int a[maxn],b[maxn],c[maxn];

struct node {
	int val;
};
node p[maxn];

bool cmp(node x,node y) {
	return x.val>y.val;
}

int main() {
    int n;
	while (scanf("%d",&n)!=EOF) {
		int i,j;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		c[n+1]=-inf;
		for (i=n;i>=1;i--) {
			c[i]=max(c[i+1],a[i]-i);
		}
		for (i=1;i<=n;i++) {
			scanf("%d",&b[i]);
			p[i].val=c[b[i]];
		}
		sort(p+1,p+n+1,cmp);
		int u=-inf,sum=0;
		for (i=1;i<=n;i++) {
			sum+=max(u,p[i].val);
			u=max(u,p[i].val-i-n);
			sum%=mod;
		}
		printf("%d\n",sum);
	}
	return 0;
}

