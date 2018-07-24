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
typedef pair<ll,int> pp;
const int maxn=100005;
const ll llinf=0x3f3f3f3f3f3f3f3f,seed=512467,mod=1e9+7;
const ld pi=acos(-1.0L);
ll fac[maxn],hs[maxn],hsh[maxn];
int len[maxn];
pp hn[maxn];
bool lz[maxn];
map<ll,int> ans,mp;
char s[maxn],t[maxn];

ll hash(int n) {
    fac[0]=1;hsh[0]=0;
	for (int i=1;i<=n;i++) {
		fac[i]=(fac[i-1]*seed)%mod;
		hsh[i]=hsh[i-1]*seed%mod+s[i];
		hsh[i]%=mod;
	}
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	hash(n);
	for (int i=1;i<=m;i++) {
		scanf("%s",t+1);
		len[i]=strlen(t+1);
		hs[i]=0;
		lz[len[i]]=1;
		for (int j=1;j<=len[i];j++) {
			hs[i]=(hs[i]*seed+t[j])%mod;
		}
		mp[hs[i]]=1;
	}
	for (int i=1;i<=n;i++) {
		if (!lz[i]) continue;
		for (int j=1;j+i-1<=n;j++) {
			hn[j]=pp((hsh[j+i-1]-hsh[j-1]*fac[i]%mod+mod)%mod,j);
		}
		sort(hn+1,hn+n-i+2);
		for (int j=1;j+i-1<=n;) {
			int k=j,cnt=1;
			while (hn[k+1].first==hn[j].first&&k+i<=n) k++;
			if (!mp.count(hn[j].first)) {
				j=k+1;continue;
			}
			int last=hn[j].second;
			for (int l=j+1;l<=k;l++) {
				if (hn[l].second-last>=i) cnt++,last=hn[l].second;
			}
			ans[hn[j].first]=cnt;
			j=k+1;
		}
	}
	for (int i=1;i<=m;i++) {
		printf("%d\n",ans[hs[i]]);
	}
	return 0;
}
