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
const int maxn=500005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],b[maxn],ans[maxn];
ll f[maxn],dp[maxn];

int lowbit(int a) {  
    return (a&(-a));  
}  
  
ll getsum(int tt,int n) {  
    ll sum=0;  
    for (int t=tt;t<=n;t+=lowbit(t))   
        sum=min(sum+f[t],llinf);  
    return sum;  
}  
  
void update(int tt,ll c,int n) {  
    int t=tt;  
    for (int t=tt;t;t-=lowbit(t))  
        f[t]=min(f[t]+c,llinf);  
}  

int main() {
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	ll m=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++) {
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	}
	for (int i=n;i>=1;i--) {
		dp[i]=getsum(a[i]+1,n)+1;
		dp[i]=min(dp[i],llinf);
		update(a[i],dp[i],n);
	}
	if (k>getsum(1,n)) {
		printf("-1\n");return 0;
	}
	m=0;
	for (int i=1;i<=n;i++) {
		if (a[i]<=a[ans[m]]) continue;
		if (k<=dp[i]) {
			k--;
			ans[++m]=i;
		} else {
			k-=dp[i];
		}
		if (k==0) break;
	}
	printf("%lld\n",m);
	for (int i=1;i<=m;i++) {
		printf("%d ",ans[i]);
	}
	return 0;
}
