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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,i;
		int ans=0;
		char c;
		scanf("%d %c",&n,&c);
		scanf("%s",s+1);
		int flag=0;
		for (i=1;i<=n;i++) {
			int p=abs(s[i]-c);
			if (!flag&&p==0) {
				continue;
			}
			if (!flag) {
				if (p<10) ans+=1; else ans+=2;
				flag=1;
				continue;
			}
			flag=1;
			ans+=2;
		}
		ans=max(ans,1);
		printf("%d\n",ans);
	}
	return 0;
}
