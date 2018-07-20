#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
long long a[105],b[105];

int main() {
	int n,p,i,c,x;
	scanf("%d%d",&n,&p);
	a[0]=0;b[0]=1;
	for (i=1;i<=n;i++) {
		scanf("%d",&x);
		if (x%2) {
			a[i]=b[i-1]+a[i-1];
			b[i]=a[i-1]+b[i-1];
		} else {
			a[i]=a[i-1]*2;
			b[i]=b[i-1]*2;
		}
	}
	if (p) cout << a[n]; else cout << b[n];
}
