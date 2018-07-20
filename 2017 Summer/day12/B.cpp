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
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[maxn],ans[maxn],f[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int n,k,i,j;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int tot=1;
	mem0(f);
	while (l<r) {
		ans[tot*2]=a[r];
		f[r]=1;
		while (a[l]+a[r]<=k&&l<r) l++;
		if (a[l]+a[r]>k&&l<r) {
			ans[tot*2-1]=a[l];
			f[l]=1;
		} else {
			ans[tot*2-1]=a[l-1];
			f[l-1]=1;
		}
		l++;
		r--;
		tot++;
	}
	tot--;
	int num=tot*2;
	tot=0;
	for (i=n;i>=1;i--) {
		if (!f[i]) ans[++num]=a[i];
	}
	for (i=1;i<=n;) {
		if (ans[i]+ans[i+1]>k) {
			tot++;
			i++;
		} else {
			tot++;
			i+=2;
		}
	}
	printf("%d\n",tot);
	for (i=1;i<n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}

