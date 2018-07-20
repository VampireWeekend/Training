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
const int maxn=600005;
int a[maxn],prime[maxn],b[maxn];

int main() {
	int i,j,k,n,num=0,x;
	scanf("%d%d",&n,&k);
	memset(prime,0,sizeof(prime));
	for (i=2;i<=n;i++) {
		if (!prime[i]) {
			a[++num]=i;
		}
		for (j=1;j<=num&&i*a[j]<=n;j++) {
			int l=i*a[j];
			prime[l]=1;
			if (i%a[j]==0) 
				break;
		}
	}
	for (i=1;i<=k;i++) {
		scanf("%d",&b[i]);
	}
	sort(b+1,b+n+1);
	for (i=1;i<=k;i++) {
		for (j=1;j<i;j++) {
			if (b[i]%b[j]==0) {
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	printf("0 0");
	return 0;
}
