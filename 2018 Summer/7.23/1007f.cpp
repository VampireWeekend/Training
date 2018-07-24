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
const int maxn=10000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const ld pi=acos(-1.0L);
ll sum[maxn],num[maxn],base[maxn],a[maxn],sumr[maxn];

int main() {
	int cas;
//	scanf("%d",&cas);
	num[1]=1;
	sum[1]=1;
	ll p=1;base[1]=1;
	int i;
	a[1]=a[2]=1;sumr[1]=1;sumr[2]=2;
	for (int i=3;i<=10000000;i++) {
		a[i]=a[i-a[i-1]]+a[i-1-a[i-2]];
		a[i]%=mod;
	//	cout << a[i] << endl;
		sumr[i]=sumr[i-1]+a[i];sumr[i]%=mod;
	}
	for (i=2;i<=100;i++) {
		num[i]=2*num[i-1]+1;
		if (num[i]>1e18) break;
		sum[i]=sum[i-1]*2ll%mod+p*num[i-1]%mod+(p*2)%mod;
		sum[i]%=mod;
		p=(p*2)%mod;
		base[i]=p;
	}
	int q=i;
	for (int m=1;m<=10000000;m++) {
		ll n,fun=0;
	//	scanf("%lld",&n);
		n=m;
		n--;
		ll ans=1;
		for (i=q;i;i--) {
			if (n>=num[i]) {
				n-=num[i];
				ans=(ans+sum[i])%mod;
				ans=(ans+fun*num[i])%mod;
				fun+=base[i];
	//			fun%=mod;
			}
		}
		fun++;
	//	fun%=mod;
		ans=(ans+fun*n)%mod;
		if (ans!=sumr[m]) cout << m << endl;
//		printf("%lld\n",ans);
	}
	return 0;
}
