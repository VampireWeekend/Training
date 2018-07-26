#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <unordered_map>
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
typedef pair<ll,ll> pp;
const int maxn=1000005;
const ll llinf=0x3f3f3f3f3f3f3f3f,seed=233,seed2=13331,mod=998244353,mod2=1000000007;
const ld pi=acos(-1.0L);
ll fac[maxn],hsh[maxn],fac2[maxn],hsh2[maxn];
char s[maxn];
vector<int> v[maxn];
unordered_map<ll,int> mp;

void myhash(int n) {
    fac[0]=fac2[0]=1;hsh[0]=hsh2[0]=0;
	for (int i=1;i<=n;i++) {
		fac[i]=(fac[i-1]*seed)%mod;
		hsh[i]=hsh[i-1]*seed%mod+s[i];
		hsh[i]%=mod;
/*		fac2[i]=(fac2[i-1]*seed2)%mod2;
		hsh2[i]=hsh2[i-1]*seed2%mod2+s[i];
		hsh2[i]%=mod2;*/
	}
}

int main() {
	int n,m;
	scanf("%s",s+1);
	n=strlen(s+1);
	m=n;
	myhash(n);
	for (int i=1;i<=n;i++) {
		ll w=(hsh[i-1]+hsh[n]*fac[i-1]%mod-hsh[i-1]*fac[n]%mod+mod)%mod;
		if (mp.count(w)) {
			int pos=mp[w];
			v[pos].pb(i); 
			m--;
		} else {
			v[i].pb(i);
			mp[w]=i;
		}
	}
	printf("%d\n",m);
	for (int i=1;i<=m;i++) {
		int size=v[i].size();
		if (size==0) continue;
		printf("%d ",size);
		for (int j=0;j<size;j++) {
			printf("%d",v[i][j]-1);
			if (j==size-1) printf("\n"); else printf(" ");
		}
	}
	return 0;
}
