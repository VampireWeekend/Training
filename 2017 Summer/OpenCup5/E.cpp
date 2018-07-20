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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
ll a[maxn],lena[maxn],lenb[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i;
		ll d1,d2;
		scanf("%d%lld%lld%lld",&n,&d1,&d2,&a[1]);
		mem0(lena);mem0(lenb);
		for (i=2;i<=n;i++) {
			scanf("%lld",&a[i]);
			if (a[i]-a[i-1]==d1) lena[i]=lena[i-1]+1; else 
			    if (a[i]-a[i-1]==d2) lenb[i]=lenb[i-1]+1;
		}
		ll ans=n,last=-1;
		lena[n+1]=lenb[n+1]=0;
		for (i=2;i<=n+1;i++) {
			if (lena[i-1]!=0&&lena[i]==0) {
				ans+=lena[i-1]*(lena[i-1]+1)/2;
				last=i-1;
			} else if (lenb[i-1]!=0&&lenb[i]==0) {
				if (last==i-1-lenb[i-1]) ans+=lena[last]*lenb[i-1];
				ans+=lenb[i-1]*(lenb[i-1]+1)/2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

