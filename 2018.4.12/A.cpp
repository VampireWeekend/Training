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
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll l[maxn],c[maxn],p[maxn];
ll x,y;

void dfs(ll n,ll dep) {
	if (dep==0) return 1;
	dfs(n%c[i]==0?c[i]:n,dep-1);
	if (n>c[i]*3) {
		x+=l[i];
		
	} else if (n>c[i]*2) {
		x+=l[i];y+=l[i];
	} else if (n>c[i]) {
		y+=l[i];
	} else {
		
	}
}

int main() {
	ll i,j,k,n,d;
	scanf("%I64d%I64d",&k,&n);
	l[1]=1;c[1]=1;
	x=y=0;d=-1;
	for (i=2;i<=15;i++) {
		l[i]=l[i-1]*2ll,c[i]=c[i-1]*4ll;
		if (c[i]>=n&d==-1) d=i; 
	}
	dfs(n,d);
	
/*	for (i=k;i>=2;i--) {
		if (n>c[i]*3) {
			x+=l[i];
			
		} else if (n>c[i]*2) {
			x+=l[i];y+=l[i];
		} else if (n>c[i]) {
			y+=l[i];
		} else {
			
		}
		n%=c[i];if (!n) n=c[i];
	} */
	return 0;
}
