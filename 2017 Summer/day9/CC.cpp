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
const int maxn=35,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
char s[maxn];
int mp[maxn],a[(1<<25)],dp[(1<<25)];
int n,m,ans;

int lowbit(int x) {
	return x&(-x);
}

int init(int x) {
	if (dp[x]) return dp[x];   //减少时间复杂度 
		int j=x;
		while (j) {
			dp[x]++;
			j-=lowbit(j);
		}
		return dp[x];
}

void dfs(int x,int k,int state) { //x:行数，k:炸的行数，state:当前所有列状态 
	if (x==n+1) {
		ans=min(ans,max(init(state),k));  
		return;
	}
	if (mp[x]!=0) dfs(x+1,k+1,state);   //剪枝，若某行不需要炸则不炸这一行 
	dfs(x+1,k,state|mp[x]);
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	mem0(mp);
	mem0(dp);
	for (i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (j=1;j<=m;j++) {
			if (s[j]=='*') mp[i]+=(1<<(j-1));
		}
	}
	ans=min(n,m);
	dfs(1,0,0);
	cout << ans;
	return 0;
}
