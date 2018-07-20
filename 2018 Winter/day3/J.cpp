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
const int maxn=30000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=3e7;   
const ld pi=acos(-1.0L);
int a[maxn],cnt[maxn];

int main() {
	int n,m,q,i,j,p,x;
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=m;i++) {
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for (i=m+1;i<=n;i++) {
		a[i]=(a[i-m]+a[i-m+1])%mod;
		cnt[a[i]]++;
	}
	for (i=1;i<=3e7;i++) cnt[i]+=cnt[i-1];
	for (i=1;i<=q;i++) {
		scanf("%d",&x);
		p=lower_bound(cnt,cnt+30000001,x)-cnt;
		printf("%d\n",p);
	}
	return 0;
}
