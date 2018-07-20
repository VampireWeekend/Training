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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L);
ll cnt[30]; 
char s[maxn];

int main() {
	int c=0,n;
	while (scanf("%d",&n)!=EOF) {
		c++;
		memset(cnt,-1,sizeof(cnt));
		ll i,j,ans=0,m=25;
		for (i=1;i<=n;i++) {
			scanf("%s",s+1);
			int len=strlen(s+1);
			for (j=1;j<=len;j++) {
				if (cnt[s[j]-'a']==-1) cnt[s[j]-'a']=m--;
			}
			
		}
		
		printf("Case #%d: %lld\n",c,ans);
	}
	return 0;
}
