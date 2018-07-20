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
const int maxn=5005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],cnt[1000005];

int main() {
	freopen("cases.in","r",stdin);
	int cas;
	scanf("%d",&cas);
	mem0(cnt);
	while (cas--) {
		int n,i,j,ans=0,o,e;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		for (i=1;i<=n;i++) {
			o=e=0;
			for (j=i;j<=n;j++) {
				cnt[a[j]]++;
				if (cnt[a[j]]==1) e++; else 
					if (cnt[a[j]]%2) e++,o--; else e--,o++;
				if (e==1) ans++;
			}
			for (j=i;j<=n;j++) cnt[a[j]]=0;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	return 0;
}
