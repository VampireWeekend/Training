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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=205,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],b[maxn];
char s[maxn][maxn];
vector<int> x,y;

int main() {
	int n,m,k,p,cnt;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++) {
			if (s[i][j]=='1') {
				a[i]++;b[j]++;
			}
		}
	}
	cnt=0;
	p=0;
	for (int i=1;i<=n;i++) {
		if (cnt+a[i]==(p+1)*k) {
			p++;x.pb(i);
			if (p==k-1) break;
		} else if (cnt+a[i]>(p+1)*k) {
			printf("NO\n");return 0;
		}
		cnt+=a[i];
	}
	cnt=0;
	p=0;
	for (int i=1;i<=m;i++) {
		if (cnt+b[i]==(p+1)*k) {
			p++;y.pb(i);
			if (p==k-1) break;
		} else if (cnt+b[i]>(p+1)*k) {
			printf("NO\n");return 0;
		}
		cnt+=b[i];
	}
	if (x.size()!=k-1) {
		printf("NO\n");return 0;
	}
	if (y.size()!=k-1) {
		printf("NO\n");return 0;
	}
	printf("YES\n");
	for (int i=0;i<k-1;i++) printf("%d ",x[i]);
	printf("\n");
	for (int i=0;i<k-1;i++) printf("%d ",y[i]);
	return 0;
}
