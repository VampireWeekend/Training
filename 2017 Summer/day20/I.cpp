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
typedef unsigned long long ull;
typedef long double ld;
const int maxn=75,inf=0x3f3f3f3f;
const ull llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];
ull a[maxn];

int main() {
//	freopen("semipal.in","r",stdin);
//	freopen("semipal.out","w",stdout);
	int len,cas;
	ull k;
	int i;
	scanf("%d",&cas);
	a[0]=1;
	for (i=1;i<=63;i++) {
		a[i]=a[i-1]*2;
	}
	while (cas--) {
		mem0(s);
		scanf("%d%I64d",&len,&k);
		ull r=0;
		if (r+a[len-2]>=k) {
			s[len]=s[1]='a';
		} else {
			s[1]=s[len]='b';
			r+=a[len-2];
		}
		for (i=2;i<len;i++) {
			if (r+a[len-i-1]>=k) {
				s[i]='a';
			} else {
				s[i]='b';
				r+=a[len-i-1];
			}
		}
		for (i=1;i<=len;i++) {
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}

