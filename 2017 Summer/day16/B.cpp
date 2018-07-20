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
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[maxn],b[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	while (n!=0||m!=0) {
		mem0(a);mem0(b);
		int ans=0;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		for (j=1;j<=m;j++) {
			int flag=1;
			for (i=1;i<=n;i++) {
				scanf("%d",&b[i]);
				if (b[i]>a[i]) flag=0;
			}
			if (flag) ans++;
		}
		printf("%d\n",ans);
		scanf("%d%d",&n,&m);
	}
	return 0;
}

