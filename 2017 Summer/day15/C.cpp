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
const int maxn=10005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,c,i,j,k,ans=0;
		scanf("%d%d",&c,&n);
		for (i=1;i<=n/3;i++) {
			for (j=(n-i)/2;j>=i;j--) {
				k=n-i-j;
				if (i+j>k) {
					if (i==j||j==k) ans++; else ans+=2; 
				} else break;
			}
		}
		printf("%d %d\n",c,ans);
	}
	return 0;
}

