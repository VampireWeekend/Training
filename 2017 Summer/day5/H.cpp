#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
int a[65],c[65],d[65];
ll b[65];

int main() {
	int n,i,j,flag;
	ll k;
	memset(a,-1,sizeof(a));
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%lld",&b[i]);
	}
	flag=1;
	for (i=1;i<n;i++) {
		int lena=0,lenb=0;
		if (b[i]==b[i+1]) continue;
		k=b[i];
		while (k) {
			lena++;
			c[lena]=k%2;
			k/=2;
		}
		k=b[i+1];
		while (k) {
			lenb++;
			d[lenb]=k%2;
			k/=2;
		}
		if (b[i]<b[i+1]) {
			if (lena!=lenb) {
				if (a[lenb]!=1) a[lenb]=0; else flag=0;
			} else {
				int pos=lena;
				while (c[pos]==d[pos]&&pos>1) pos--;
				if (a[pos]!=1) a[pos]=0; else flag=0;
			}
		} else {
			if (lena!=lenb) {
				if (a[lena]!=0) a[lena]=1; else flag=0;
			} else {
				int pos=lena;
				while (c[pos]==d[pos]&&pos>1) pos--;
				if (a[pos]!=0) a[pos]=1; else flag=0;
			}
		}
	}
	ll ans;
	if (flag) {
		ans=1;
		for (i=1;i<=60;i++) {
			if (a[i]==-1) ans*=2;
		}
	} else ans=0;
	printf("%lld",ans);
	return 0;
}
