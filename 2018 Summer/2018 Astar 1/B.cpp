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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int sum[maxn][26];
char s[maxn];

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		int n,q,l,r;
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for (int j=0;j<26;j++) sum[0][j]=0;
		for (int i=1;i<=n;i++) {
			for (int j=0;j<26;j++) {
				sum[i][j]=sum[i-1][j]+(s[i]==(char('A'+j)));
			}
		}
		cnt++;printf("Case #%d:\n",cnt);
		for (int i=1;i<=q;i++) {
			scanf("%d%d",&l,&r);
			int ans=0;
			for (int j=0;j<26;j++) {
				ans=max(ans,sum[r][j]-sum[l-1][j]);
				if (ans>0) break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
