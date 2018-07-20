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
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int a[maxn],b[maxn],c[maxn];

int main() {
	int n,i,ans,j,k,m;
	ans=inf*2;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	j=1,k=n/2+1;m=0;
	if (n%2) k++;
	for (i=1;i<=n/2;i++) {
		b[++m]=a[j++];
		b[++m]=a[k++];
	}
	if (n%2) b[n]=a[j];
	for (i=2;i<=n;i++) ans=min(ans,abs(b[i]-b[i-1]));
	j=n/2+1,k=1;m=0;
	for (i=1;i<=n/2;i++) {
		c[++m]=a[j++];
		c[++m]=a[k++];
	}
	if (n%2) c[n]=a[j];
	int u=2*inf;
	for (i=2;i<=n;i++) u=min(u,abs(c[i]-c[i-1]));
	if (ans<u) {
		for (i=1;i<n;i++) printf("%d ",c[i]);
		printf("%d\n",c[n]);
	} else {
		for (i=1;i<n;i++) printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
	return 0;
}

