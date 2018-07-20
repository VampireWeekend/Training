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
const int inf=0x3f3f3f3f,mod=2520;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ll dp[20][55][mod+5];
int num[25];
int hash[mod+5];

int gcd(int x,int y) {
	int a,b,c;
	a=x,b=y;
	while (b) {
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}

int lcm (int x,int y) {
	return x*y/gcd(x,y);
}

ll dfs(int len,int nlcm,int sum,bool HaveLimit) {
	if (!len) return sum%nlcm==0;
	if (!HaveLimit&&dp[len][hash[nlcm]][sum]!=-1) 
	    return dp[len][hash[nlcm]][sum];
	    
	int p; 
	if (HaveLimit) p=num[len]; else p=9;
	ll ans=0;
	for (int i=0;i<=p;i++) {
		int ne;
		if (i!=0) ne=lcm(nlcm,i); else ne=nlcm;
		ans+=dfs(len-1,ne,(sum*10+i)%mod,i==num[len]?HaveLimit:0);
	}
	if (!HaveLimit) dp[len][hash[nlcm]][sum]=ans;
	return ans;
}

ll solve(ll n) {
	if (n==0) return 1;
	int i=0;
	ll k=n;
	while (k) {
		num[++i]=k%10;
		k/=10;
	}
	return dfs(i,1,0,1);
}

int main() {
	int cas,m=0;
	ll l,r;
	scanf("%d",&cas);
	memset(dp,-1,sizeof(dp));
	for (int i=1;i<=2520;i++) {
		if (mod%i==0) hash[i]=++m;
	}
	while (cas--) {
		scanf("%I64d%I64d",&l,&r);
		ll ans=solve(r)-solve(l-1);
		printf("%I64d\n",ans);
	}
	return 0;
}
