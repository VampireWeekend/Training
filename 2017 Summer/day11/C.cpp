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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[maxn];

int main() {
//	freopen("dales.in","r",stdin);
//	freopen("dales.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,c,h,d;
		h=d=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		int last;
		int k=1;
		while (a[k]==a[k+1]&&k<n) k++;
		last=k;
		int lastd=0,lasth=0,flag=0;
		for (i=k+1;i<=n-1;i++) {
			if (a[i]>a[i-1]&&a[i]>a[i+1]) {
				if (!flag) d=max(d,min(i-last,lastd));
				lasth=i-last;
				lastd=0;
				last=i;
				flag=0;
			} else 
			if (a[i]<a[i-1]&&a[i]<a[i+1]) {
				if (!flag) h=max(h,min(i-last,lasth));
				lastd=i-last;
				lasth=0;
				last=i;
				flag=0;
			} else if (a[i-1]==a[i]) {
				if (a[i-2]>a[i-1]) {
					h=max(h,min(i-1-last,lasth));
					lasth=0;
				}
				if (a[i-2]<a[i-1]) {
					d=max(d,min(i-1-last,lastd));
					lastd=0;
				}
				flag=1;
				last=i;
			}
		}
		if (a[n]>a[n-1]) {
			if (!flag) d=max(d,min(n-last,lastd));
		} else if (a[n]<a[n-1]) {
			if (!flag) h=max(h,min(n-last,lasth));
		} else {
			if (a[n-2]>a[n-1]) 
				h=max(h,min(n-1-last,lasth));
			if (a[n-2]<a[n-1]) 
				d=max(d,min(n-1-last,lastd));
		}
		printf("%d %d\n",h,d);
	}
	return 0;
}
