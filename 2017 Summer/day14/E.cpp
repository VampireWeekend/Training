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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[maxn];
vector<int> v;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,k,ans,t=0,i;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	ans=-1;
	for (i=1;i<=n&&a[i]+1000<=a[n];i++) {
		int pos=lower_bound(a+1,a+n+1,a[i]+1000)-a;
		ans=max(ans,pos-i);
	}
	ans=max(ans,n-i+1);
	if (ans%k==0) ans/=k; else ans=ans/k+1;
	printf("%d",ans);
	return 0;
}

