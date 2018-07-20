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

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas,num;
	scanf("%d",&cas);
	while (cas--) {
		ll n,ans;
		int i,j;
		scanf("%d%lld",&num,&n);
		ans=n;
		while (n!=1) {
			if (n%2) n=n*3+1; else n/=2;
			ans=max(ans,n);
		}
		printf("%d %lld\n",num,ans);
	}
	return 0;
}

