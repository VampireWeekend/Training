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
const int maxn=600000;
int prime[maxn+5],a[maxn+5];
int hash[maxn+5];
int b[maxn+5];

int main() {
	int num=0;
	int n,k,i,j,x;
	scanf("%d %d",&n,&k);
	memset(hash,0,sizeof(hash));
	memset(b,0,sizeof(b));
	for (i=1;i<=k;i++) {
		scanf("%d",&x);
		hash[x]=i;
	}
	for (i=2;i<=n;i++) {
		if (!prime[i]) {
			a[++num]=i;
			if (hash[i]) b[i]=hash[i];
		}
		for (j=1;j<=num&&i*a[j]<=n;j++) {
			int l=i*a[j];
			if (hash[l])
			if (b[a[j]]||b[i]) {
				if (b[i])
				printf("%d %d",min(b[i],hash[l]),max(b[i],hash[l]));
				else 
				printf("%d %d",min(b[a[j]],hash[l]),max(b[a[j]],hash[l]));
				return 0;
			} else b[a[j]]=b[i]=hash[l];
			prime[l]=1;
			if (i%a[j]==0) 
				break;
		}
	}
	printf("0 0");
	return 0;
}
