#define SUBMIT
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=4000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
int rl[maxn];
ll inv[maxn],ps[maxn];
char s[maxn],a[maxn];
ll ans=0;

ull fac[maxn],hsh[maxn];
map<ull,int> mp[maxn];
const ull seed=100001651,seed2=63218479;
void myhash(int n) {
    fac[0]=1;hsh[0]=0;
	for (int i=1;i<=n;i++) {
		fac[i]=fac[i-1]*seed;
		hsh[i]=hsh[i-1]*seed+s[i-1];
	}
}

ull gethash(int l,int r) {
	l++;r++;
    return (((hsh[r]-hsh[l-1]*fac[r-l+1])%mod)+mod)%mod;
}

void manacher(int len) {
	int i,maxright,pos;
	maxright=pos=0;
	for (i=0;i<len;i++) {
		if (i<=maxright) {
			rl[i]=min(rl[2*pos-i],maxright-i);
		} else {
			rl[i]=1;
			if (mp[1].find((ull)s[i])==mp[1].end()) {
				mp[1][s[i]]=1;
				ans+=s[i]-'0';
				ans%=mod;
			}
		}
		while (i-rl[i]>=0&&i+rl[i]<len&&s[i-rl[i]]==s[i+rl[i]]) {
			rl[i]++;
			if (s[i-rl[i]+1]=='#') continue;
			ull now=gethash(i-rl[i]+1,i);
			if (mp[rl[i]].find(now)==mp[rl[i]].end()) {
				mp[rl[i]][now]=1;
				int l=i-rl[i]+1,r=i+rl[i]-1,mid=i/2+1;
				l/=2;r/=2;
				l++;r++;
				ans+=(ps[r]-ps[l-1]*inv[r-l+1]%mod+mod)%mod;
				ans%=mod;
			}
		}
		if (i+rl[i]-1>maxright) {
			maxright=i+rl[i]-1;
			pos=i;
		}
	}
}

int main() {
//	scanf("%s",a);
//	int len=strlen(a);
	int len=2000000;
	for (int i=0;i<len;i++) {
		a[i]='1';
	}
	for (int i=0;i<len;i++) {
		ps[i+1]=ps[i]*10+(a[i]-'0');
		ps[i+1]%=mod;
	}
	s[0]='#';
	for (int i=0;i<len;i++) {
		s[i*2+1]=a[i];
		s[i*2+2]='#';
	}
	len*=2;
	len++;
	inv[0]=1;
	for (int i=1;i<=len;i++) {
		inv[i]=inv[i-1]*10%mod;
	}
	myhash(len);
	manacher(len);
	printf("%lld\n",ans);
	return 0;
}
