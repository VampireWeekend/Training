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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=10555,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i;
		scanf("%d",&n);
		n--;
		int m=sqrt(n),ans=0;
		for (i=1;i<=m;i++) {
			if (n%i==0) {
				if (i*i==n) ans++; else ans+=2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

