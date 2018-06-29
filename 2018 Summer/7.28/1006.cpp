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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=2005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char a[maxn][maxn];
int x,y;

void update(int i,int j) {
	x=min(x,i);
	y=min(y,j);
}

int main() {
	int n,m,cas;
	scanf("%d",&cas);
	while (cas--) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) {
			scanf("%s",a[i]+1);
		}
		x=n/2;y=m/2;
		for (int i=1;i<=n/2;i++) {
			for (int j=1;j<=m/2;j++) {
				if (a[i][j]!=a[n+1-i][j]) {
					update(i,j);continue;
				}
				if (a[i][j]!=a[i][m+1-j]) {
					update(i,j);continue;
				}
				if (a[i][j]!=a[n+1-i][m+1-j]) {
					update(i,j);continue;
				}
			}
		}
		int ans=(x-1)*(y-1);
		printf("%d\n",ans);
	}
	return 0;
}
