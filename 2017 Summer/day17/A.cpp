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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn],t[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,x,y,i,a,b;
		scanf("%d%d%d",&n,&x,&y);
		scanf("%s",s+1);
		scanf("%s",t+1);
		a=b=0;
		for (i=1;i<=n;i++) {
			if (s[i]==t[i]) a++; else b++;
		}
		int minb,maxb;
		minb=max(0,x-b);
		if (a>=x) maxb=x+b; else maxb=n-(x-a);
		if (y>=minb&&y<=maxb) printf("Not lying\n"); 
		    else printf("Lying\n");
	}
	return 0;
}

