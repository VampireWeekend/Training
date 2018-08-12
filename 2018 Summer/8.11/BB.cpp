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
const maxn=1005,int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn][maxn],b[maxn][maxn],cnt[maxn];
int ans=0;

bool check(int n) {
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) b[i][j]=a[i][j];
	int add=1,sum=n;
	while (add==0) {
		add=0;
		for (int i=1;i<=n;i++) 
			for (int j=1;j<=n;j++)
				if (a[i][j+1]+a[i][j-1]+a[i+1][j]+a[i-1][j]>=2&&a[i][j]==0) a[i][j]=1,add++;
		sum+=add;
	}
	return sum==n*n;
}

void dfs(int n,int dep){
	if (n==dep-1) {
		if (check(n)) ans++;
	}
	for (int i=1;i<=n;i++) {
		if (cnt[i]==1) continue; 
		a[dep][i]=1;
		cnt[i]=1;
		dfs(n,dep+1);
		a[dep][i]=0;
		cnt[i]=0;
	}
}

int main() {
	int n,i,x,sum=0;
	scanf("%d",&n);
	dfs(n,1);
	cout << ans << endl;
	return 0;
}
