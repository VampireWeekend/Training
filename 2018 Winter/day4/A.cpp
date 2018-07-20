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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
//	freopen("tabs.in","r",stdin);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,k,pos,ans;
		scanf("%d%d",&n,&k);
		if (k==1||k==n) ans=1; else ans=2;
		if (k==1&&n==1) ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
