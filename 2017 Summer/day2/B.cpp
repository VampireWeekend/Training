#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=100005;
int a[maxn];

int gcd(int a,int b) {
	if (a<b) {
		int c=a;a=b;b=c;
	}
	while (b) {
		int c=b;
		b=a%b;
		a=c;
	}
	return a;
} 

int main() {
	int n,cnt=0,i;
	while (scanf("%d",&n)!=EOF) {
		cnt++;
		printf("Case %d: ",cnt);
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		for (i=2;i<=n;i++) {
			a[1]=a[i]=gcd(a[1],a[i]);
		}
		if (a[1]!=1) {
			printf("-1\n\n");
			continue;
		}
		int num=n-1;
		for (i=2;i<=n;i++) 
			if (a[i]!=1) 
				num++;
		printf("%d\n",num);
		for (i=2;i<=n;i++) printf("%d %d\n",1,i);
		for (i=2;i<=n;i++) 
			if (a[i]!=1) 
			    printf("%d %d\n",1,i);
		printf("\n");
	}
	return 0;
}
