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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=200005,maxk=64,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],x[105],b[maxn*2];

bool linear_basis_insert(ll p) {
	for (int i=maxk;i>=0;i--) {
		if ((p>>i)%2==1) {
			if (!x[i]) {
				x[i]=p;
				for (int j=i-1;j>=0;j--) 
					if (x[j]&&((x[i]>>j)%2==1)) x[i]^=x[j];
                for (int j=i+1;j<=maxk;j++) 
					if ((x[j]>>i)%2==1) x[j]^=x[i];
				return true;
			} else p=p^x[i];
		}
	}
	return p!=0;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		mem0(x);
		int n,i,j;
		ll m=0;
		bool flag=1;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			flag&=linear_basis_insert(a[i]);
		}
		sort(a+1,a+n+1);
		m=unique(a+1,a+n+1)-a-1;
		ull ans=1;
		int cnt=0;
		for (j=0;j<=maxk;j++)
			if (x[j]) cnt++;
		for (i=1;i<=cnt;i++) ans*=2;
		ans-=m;
		printf("%lld\n",ans);
	}
	return 0;
}
