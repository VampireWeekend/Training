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
#define N 100000
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll mu[maxn],sum[maxn],p[maxn];
int num;

void init() {
	num=0;
	meminf(mu);
	ll i,j;
	mu[1]=1;
	for (i=2;i<=N;i++) {
		if (mu[i]==llinf) {
			p[++num]=i;
			mu[i]=-1;
		}
		for (j=1;j<=num&&i*p[j]<=N;j++) {
			if (i%p[j]==0) {
				mu[i*p[j]]=0;
			} else mu[i*p[j]]=-mu[i];
		}
	}
	for (int i=1;i<=N;i++) sum[i]=sum[i-1]+mu[i];
}

int main() {
	int cas,cnt=0;
	init();
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		ll a,b,c,d,k,ans,ans2;
		ans=ans2=0;
		scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
		if (k==0) {
			printf("Case %d: 0\n",cnt);continue;
		}
		b/=k;d/=k;
		if (b>d) swap(b,d);
		for (ll i=1;i<=b;i++) {
			ans+=mu[i]*(b/i)*(d/i);
		}
		for (ll i=1;i<=b;i++) {
			ans2+=mu[i]*(b/i)*(b/i);
		}
		ans-=ans2/2;
		printf("Case %d: %lld\n",cnt,ans);
	}
	return 0;
}
