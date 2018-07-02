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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int cnt[maxn],a[maxn];
vector<int> ans;

int main() {
	int n,i,j,m=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]==0) m++; else if (a[i]>0) {
			cnt[a[i]]++;
		} else {
			a[i]=-a[i];
			if (cnt[a[i]]>0) {
				cnt[a[i]]--;
			} else if (m>0) {
				m--;
				ans.pb(a[i]);
			} else {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	int sz=ans.size();
	for (int i=0;i<sz;i++) {
		printf("%d ",ans[i]);
	}
	for (int i=0;i<m;i++) {
		printf("%d ",1);
	}
	return 0;
}
