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
const int maxn=10000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,i,j;
	ll mod,b,num;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%lld%lld",&num,&b);
		ll l=1,ans=0;
		scanf("%s",s+1);
		int len=strlen(s+1);
		for (j=len;j>=1;j--) {
			ans+=(s[j]-'0')*l;
			ans%=(b-1);
			l*=b;
			l%=(b-1);
		}
		printf("%lld %lld\n",num,ans);
	}
	return 0;
}

