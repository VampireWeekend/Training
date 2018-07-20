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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
const ld pi=acos(-1.0L); 
ll a[maxn]; 

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	a[0]=0;a[1]=2;a[2]=24;a[3]=96;a[4]=416;
	int i,x,cas;
	for (i=5;i<=10000;i++) {
		a[i]=5*a[i-1]-10*a[i-2]+10*a[i-3]-5*a[i-4]+a[i-5];
		a[i]%=mod;
	}
	scanf("%d",&cas);
	while (cas--) {
		scanf("%d",&x);
		printf("%lld\n",a[x]);
	}
	return 0;
}

