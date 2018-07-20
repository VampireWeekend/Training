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
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int pre[maxn],nxt[maxn],a[maxn],pm[maxn],nm[maxn];
char s[maxn];

int main() {
//	freopen("stations.in","r",stdin);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,ans=-inf,first,last;
		scanf("%d",&n);
		scanf("%s",s+1);
		pre[0]=inf;
		first=last=-1;
		for (i=1;i<=n;i++) {
			if (s[i]=='+') pre[i]=last=i; else pre[i]=pre[i-1];
			if (s[i]=='+'&&first==-1) first=i;
		}
		nxt[n+1]=inf;
		for (i=n;i>=1;i--) {
			if (s[i]=='+') nxt[i]=i; else nxt[i]=nxt[i+1];
		}
		pm[0]=nm[n+1]=-inf;
		for (i=1;i<=n;i++) {
			a[i]=min(abs(pre[i]-i),abs(nxt[i]-i));
			pm[i]=max(a[i],pm[i-1]);
			ans=max(ans,a[i]);
		}
		for (i=n;i>=1;i--) nm[i]=max(a[i],nm[i+1]);
		int pos;
		for (i=1;i<=n;i++) {
			if (pre[i]==inf) continue;
			if (s[i]=='+') {
				pos=i;continue;
			}
			int pp,nn,x,y;
			if (pos==first) pp=i-1,x=0;
					else pp=(i-pre[pos-1])/2,x=pre[pos-1]-1;
			if (nxt[i]==inf) nn=n-i,y=n+1; else nn=(nxt[i]-i)/2,y=nxt[i]+1;
			ans=min(ans,max(max(pp,nn),max(pm[x],nm[y])));
			cout << i << ' ' << x << ' ' << y << endl;
		}
		cout << ans << endl;
		for (i=n;i>=1;i--) {
			if (nxt[i]==inf) continue;
			if (s[i]=='+') {
				pos=i;continue;
			}
			int pp,nn,x,y;
			if (pre[i]==inf) pp=i-1,x=0;
					else pp=(i-pre[i])/2,x=pre[i]-1;
			if (pos==last) nn=n-i,y=n+1; else nn=(nxt[pos+1]-i)/2,y=nxt[pos+1]+1;
			ans=min(ans,max(max(pp,nn),max(pm[x],nm[y])));
			cout << i << ' ' << x << ' ' << y << endl;
		}
		printf("%d\n",ans);
	}
//	fclose(stdin);
	return 0;
}
