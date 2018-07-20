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
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);  
ll dp[maxn][11][2][2];
int num[maxn];
char s[maxn];

ll dfs(int len,int last,bool up,bool down,bool HaveLimit) {
	if (len==0) 
		return 1;
	if (dp[len][last][up][down]!=-1&&!HaveLimit) 
	    return dp[len][last][up][down];
	
	int p=HaveLimit?num[len]:9,i;
	ll ans=0;
	if (last<=p) ans+=dfs(len-1,last,up,down,HaveLimit&&last==num[len]);
	if (!up) 
	    for (i=0;i<=min(last-1,p);i++) {
	    	ans+=dfs(len-1,i,up,down||i<last,HaveLimit&&i==num[len]);
	    	ans%=mod;
	    }
	if (!down)
	for (i=last+1;i<=p;i++) {
		ans+=dfs(len-1,i,up||i>last,down,HaveLimit&&i==num[len]);
		ans%=mod;
	}
	if (!HaveLimit) dp[len][last][up][down]=ans;
	return ans;
}

ll solve (ll n) {
	if (n==0) return 0;
	int len=0,i,j;
	ll p=n;
	while (p) {
		num[++len]=p%10;
		p/=10;
	}
	ll ans=0;
	for (j=1;j<=num[len];j++) {
		ans+=dfs(len-1,j,0,0,j==num[len]);
		ans%=mod;
	}
	for (i=len-1;i>0;i--) {
	    for (j=1;j<=9;j++) {
	    	ans+=dfs(i-1,j,0,0,0);
		   	ans%=mod;
	    }
	}
	return ans;
}

int main() {
	int cas;
	scanf("%d",&cas);
	memset(dp,-1,sizeof(dp));
	while (cas--) {
		ll ans=0,l,r;
		scanf("%lld%lld",&l,&r);
		ans=solve(r)-solve(l-1);
		printf("%lld\n",ans);
	}
	return 0;
}

