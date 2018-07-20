#include <cstdio>
#include <iostream>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=100005;
ll a[maxn],d[maxn],di[maxn];
vector<ll> v[maxn],sum[maxn];

int main() {
	ll i,j,n,top,mod;
	scanf("%I64d%I64d",&n,&mod);
	memset(d,0x3f,sizeof(d));
	for (i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	d[0]=di[0]=-1;
	top=0;
	for (i=1;i<=n;i++) {
		int pos=lower_bound(d+1,d+n+1,a[i])-d;
		v[pos].push_back(i);
		ll p=lower_bound(sum[pos].begin(),)
	    if (pos>top) top++;
		d[pos]=a[i];
		di[pos]=i;
	}
	printf("%d ",top);
	return 0;
}
