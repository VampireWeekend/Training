#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#define mem0(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
int num[75];
ll a[75];
char s[75];

ll solve(ll limit) {
	if (limit==-1) return 0;
	int cnt=0;
	ll ans=0;
	int i,j,l,len;
	ll k;
	k=limit;
	while (k) {
		num[++cnt]=k%2;
		k/=2;
	}	
for (len=1;len<=cnt;len++) {
	if (a[len]<=limit) ans++;
	for (i=2;i<=len;i++) {
		if (len%i==0) {
			for (j=1;j<i;j++) {
				int t=len/i;
				k=i-j;
				ll x=0,num=(a[k]<<j);
				for (l=1;l<=t;l++) {
					x=(x<<i)+num;
				}
		/*		mem0(s);
				itoa(x,s,2);
		    	printf("%s\n",s);*/
				if (x<=limit) ans++;
			}
		} else {
			int t=len/i;
			k=len%i;
			j=i-k;
			ll x=0,num=(a[k]<<j);
			for (l=1;l<=t;l++) {
				x=(x<<i)+num;
			}
			x=(x<<k)+a[k];
/*			mem0(s);
			itoa(x,s,2);
			printf("%s\n",s);*/
			if (x<=limit) ans++;
		}
	}
}
	return ans;
}

int main() {
	ll l,r,ans;
	a[1]=1;
	for (int i=2;i<=64;i++) {
		a[i]=a[i-1]*2+1;
	}
	cin >> l >> r;
	ans=solve(r)-solve(l-1);
	printf("%I64d\n",ans);
	return 0;
}
