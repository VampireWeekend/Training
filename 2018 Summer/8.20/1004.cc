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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[105][105],p[105][105];
bool use[maxn];
ll n,m;
ll ans=0;

bool check () {
	int cnt=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int flag=1;
			for (int k=1;k<=m;k++) {
				if (a[i][k]>a[i][j]) flag=0;
			}
			for (int k=1;k<=n;k++) {
				if (a[k][j]>a[i][j]) flag=0;
			}
			if (flag) cnt++;
		}
	}
	return cnt==1;
}

void dfs(int x,int y) {
	if (x==n+1) {
		if (check()) {
			ans++;
/*			for (int i=1;i<=n;i++) {
				for (int j=1;j<=m;j++) {
					cout << a[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';*/
		}
	}
	for (int i=1;i<=n*m;i++) {
		if (!use[i]) {
			use[i]=1;
			a[x][y]=i;
			if (y!=m) dfs(x,y+1); else dfs(x+1,1);
			use[i]=0;
		}
	}
}

int main() {
	cin >> n >> m;
	a[1][1]=n*m;use[n*m]=1;
	dfs(1,2);
	cout << ans*n*m << endl;
	return 0;
}
