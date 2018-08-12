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
const int maxn=500005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],z[maxn],v[maxn],ans[maxn];

int main() {
	queue<int> q;
	int n,m=0;
	scanf("%d",&n);
	int sum=0;
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (!z[a[i]]) q.push(a[i]),ans[a[i]]=1;
		z[a[i]]=1;
		sum^=a[i];
	}
	if (sum==0) {
		printf("%d\n",n);return 0;
	}
	if (z[sum]) {
		printf("1\n",n);return 0;
	}
	set<int> st;
	for (int i=1;i<=n;i++) {
		if (!z[i]) st.insert(i);
	}
	while (!q.empty()) {
		int now=q.front();q.pop();m=0;
		for (auto u:st) {
			if (!z[u^now]) z[u^now]=1,v[++m]=u,ans[u]=min(ans[u],ans[u^now]+ans[now]);
		}
		if (ans[sum]) break;
		for (int i=1;i<=m;i++) st.erase(v[i]);
	}
	printf("%d\n",n-ans[sum]);
	return 0;
}
