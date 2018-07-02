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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=2005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const ld pi=acos(-1.0L);
ll dp[maxn],ans[10];
char t[maxn];
int m;

struct node {
	int cnt,c;
};
node s[maxn];

bool cmp(node a,node b) {
	return a.cnt>b.cnt;
}

void init(int n) {
	for (int i=0;i<(1<<10);i++) {
		int cnt=0;
		for (int j=0;j<10;j++) {
			if (i&(1<<j)) cnt++;
		}
		if (cnt%2==0) s[++m].c=i,s[m].cnt=cnt;
	}
}

int main() {
	int cas;
	m=0;
	init(10);
	sort(s+1,s+m+1,cmp);
	scanf("%d",&cas);
	while (cas--) {
		int n,q,x,y;
		mem0(dp);
		for (int i=0;i<=10;i++) ans[i]=0;
		dp[0]=1;
		scanf("%d%d",&n,&q);
		for (int i=1;i<=q;i++) {
			scanf("%s%d%d",t,&x,&y);
			x--;y--;
			int now=(1<<x)+(1<<y);
			for (int j=1;j<=m;j++) {
	//			if (j==now) continue; 
				if ((s[j].c&now)==now) {
					ll p=dp[s[j].c];
					if (t[0]=='+') dp[s[j].c]+=dp[s[j].c^now]; else dp[s[j].c]-=dp[s[j].c^now];
					dp[s[j].c]=(dp[s[j].c]+mod)%mod;
					ans[s[j].cnt]+=(dp[s[j].c]-p+mod);
					ans[s[j].cnt]%=mod;
				}
			}
	//		if (t[0]=='+') dp[now]++,ans[now]=(ans[now]+1)%mod; else dp[now]--,ans[now]=(ans[now]-1+mod)%mod;
			for (int j=2;j<=n;j+=2) {
				printf("%lld",ans[j]); 
				if (j!=n) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
