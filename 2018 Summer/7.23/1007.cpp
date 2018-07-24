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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const ld pi=acos(-1.0L);
ll sum[maxn],num[maxn],base[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	num[1]=1;
	sum[1]=1;
	ll p=1;base[1]=1;
	int i;
	for (i=2;i<=100;i++) {
		num[i]=2*num[i-1]+1;
		if (num[i]>1e18) break;
		sum[i]=sum[i-1]*2ll%mod+p*(num[i-1]%mod)%mod+(p*2ll)%mod;
		sum[i]%=mod;
		p=(p*2ll)%mod;
		base[i]=p;
	}
	int q=i;
	while (cas--) {
		ll n,fun=0;
		scanf("%lld",&n);
		n--;
		ll ans=1;
		for (i=q;i;i--) {
			if (n>=num[i]) {
				n-=num[i];
				ans=(ans+sum[i])%mod;
				ans=(ans+fun*(num[i]%mod))%mod;
				fun+=base[i];
				fun%=mod;
			}
		}
		fun++;
		fun%=mod;
//		cout << n << endl;
		ans=(ans+fun*n)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
