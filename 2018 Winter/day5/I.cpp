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
ll t[maxn],v[maxn],sum[maxn],mi[maxn][19],ma[maxn][19];
char a[15],b[15];

ll findmin(ll l,ll r) {
	ll k=0;
	while ((1<<(k+1))<=(r-l+1)) k++;
	return min(mi[l][k],mi[r-(1<<k)+1][k]);
}

ll findmax(ll l,ll r) {
	ll k=0;
	while ((1<<(k+1))<=(r-l+1)) k++;
	return max(ma[l][k],ma[r-(1<<k)+1][k]);
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		ll i,j,c;
		sum[0]=0;
		for (i=1;i<=n;i++) {
			scanf("%lld%lld",&t[i],&v[i]);
			ma[i][0]=mi[i][0]=v[i];sum[i]=sum[i-1]+v[i];
		} 
		for (j=1;(1<<(j))<=n;j++) {
			for (i=1;i+(1<<j)-1<=n;i++) {
				ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
				mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
			}
		}
		scanf("%lld",&c);
		ll s,pre;
		for (j=1;j<=c;j++) {
			scanf("%s%s%lld",a,b,&s);
			pre=1;
			ll ans=0;
			for (i=1;i<=n;i++) {
				while (t[i]-t[pre]>s) pre++;
				if (pre==i) 
					continue;
				if (b[0]=='a') {
					ll val=sum[i-1]-sum[pre-1];
					if (a[0]=='g') {
						if (v[i]*(i-pre)>val) ans++;
					} else if (v[i]*(i-pre)<val) ans++;
				} else if (b[2]=='n') {
					ll val=findmin(pre,i-1);
					if (a[0]=='g') {
						if (v[i]>val) ans++;
					} else if (v[i]<val) ans++;
				} else {
					ll val=findmax(pre,i-1);
					if (a[0]=='g') {
						if (v[i]>val) ans++;
					} else if (v[i]<val) ans++;
				}
		//		cout << ans << endl;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
