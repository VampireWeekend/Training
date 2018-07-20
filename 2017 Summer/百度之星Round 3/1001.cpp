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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);  
char s[maxn];

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int i,len,j;
		ll ans,base,tem;
		scanf("%s",s);
		ans=0;base=1;
		i=strlen(s);
		while (i>0) {
			i--;
			if (s[i]==')') {
				len=s[i-1]-'0';
				i-=5;
				tem=0;
				ll ba=1;
				while (s[i]!='(') {
					tem=tem+(s[i]-'0')*ba;
					tem%=mod;
					ba*=10;
					ba%=mod;
					i--;
				}
				tem*=base;
				tem%=mod;
				for (j=1;j<=len;j++) {
					ans+=tem;
					ans%=mod;
					tem=(tem*ba)%mod;
				}
				for (j=1;j<=len;j++) {
					base*=ba;
					base%=mod;
				}
			}
			else {
				ans+=(s[i]-'0')*base;
				ans%=mod;
				base=(base*10)%mod;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

