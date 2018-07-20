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
int a[maxn];

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		int n,i,ans=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			ans+=a[i];
		}
		sort(a+1,a+n+1);
		for (i=n-2;i>=1;i-=3) {
			ans-=a[i];
		}
		printf("Case #%d: %d\n",cnt,ans);
	}
	return 0;
}
