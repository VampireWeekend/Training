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
const int maxn=1000,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[10],b[10];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,i,c,j;
	scanf("%d",&n);
	b[0]=1;
	for (i=1;i<=n;i++) {
		a[i]=i;
		b[i]=b[i-1]*i;
	}
	for (i=1;i<=b[n];i++) {
		for (j=1;j<n;j++) printf("%d ",a[j]);
		printf("%d\n",a[n]);
		for (j=n-1;j>=1;j--) {
			if (i%b[j]==0) {
				c=a[n-j];a[n-j]=a[n-j+1];a[n-j+1]=c;
				break;
			}
		}
	}
	return 0;
}

