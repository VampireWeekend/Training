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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	freopen("chess.in","r",stdin);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		ll n,k,ans;
		scanf("%I64d%I64d",&n,&k);
		if (n==k+1) ans=n*n-n; else {
			ll m=(n-1)/(k+1);
			ll a=m*2+1;
			ans=n*n-(k+1)-(k+1)*(3+a)*m/2;
			if (n%(k+1)!=0) 
				ans+=((k+1)-n%(k+1))*a;
		}
		printf("%I64d\n",ans);
	}
	fclose(stdin);
	return 0;
}
