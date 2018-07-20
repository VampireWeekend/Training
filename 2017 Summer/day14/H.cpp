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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);

struct Re {
	int l,r;
};
Re a[maxn];

bool cmp(Re a,Re b) {
	return a.r<b.r || (a.r==b.r&&a.l>b.l);
}

int main() {
	multiset<int> s;
	int n,k,i;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	for (i=1;i<=k;i++) {
		s.insert(0);
	}
	multiset<int>::iterator iter;
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for (i=1;i<=n;i++) {
		iter=s.upper_bound(a[i].l);
		if (iter!=s.begin()) {
			iter--;
			s.erase(iter);
			s.insert(a[i].r);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

