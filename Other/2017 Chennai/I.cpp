#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,k,i,len,a,b;
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		len=strlen(s+1);
		a=b=0;
		int aa,bb;aa=bb=0;
		for (i=1;i<=len;i++) {
			if (s[i]>='A'&&s[i]<='Z') a++; else b++;
		} 
		if (k>=a) aa=1;
		if (k>=b) bb=1;
		if (aa&&bb) printf("both\n"); else 
		if (aa) printf("chef\n"); else 
		if (bb) printf("brother\n"); else printf("none\n");
	}
	return 0;
}
