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
const int maxn=1005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];

int main() {
	int n,i,j,ans,t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		mem0(a);
		for (i=1;i<=n;i++) {
			scanf("%d",&j);
			a[j]++;
		}
		ans=0;a[0]=0;
		for (i=1;i<=1000;i++) {
			if (a[i]>a[ans]) ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
