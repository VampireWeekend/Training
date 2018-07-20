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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=2005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[205];

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		for (j=1;j<=20;j++) scanf("%d",&a[j]);
		for (j=20;j>1;j--) {
			if (a[j]>=2) a[j-1]+=a[j]/2;
			if (a[j]%2) 
				a[j]=1;
			else a[j]=0;
		}
		for (j=1;j<20;j++) printf("%d ",a[j]);
		printf("%d\n",a[20]);
	}
	return 0;
}
