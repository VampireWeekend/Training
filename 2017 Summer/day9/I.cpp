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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int num;
ll t[1000005],a[maxn],ans[maxn];

struct area{
	int l,r,id,kuai;
};
area q[maxn];

bool cmp(area a,area b) {
	return a.kuai<b.kuai || (a.kuai==b.kuai&&a.r<b.r);
}

int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	num=sqrt(n);
	if (n%num!=0) num++;
	for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
		q[i].kuai=q[i].l/num;
	}
	sort(q+1,q+m+1,cmp);
	mem0(t);
	ll k=0;
	for (i=q[1].l;i<=q[1].r;i++) {
		k+=(t[a[i]]*2+1)*a[i];
		t[a[i]]++;
	}
	int l=q[1].l,r=q[1].r;
	ans[q[1].id]=k;
//	cout << l << ' ' << r << ' ' << k << endl;
	for (i=2;i<=m;i++) {
		while (r<q[i].r) {
			r++;
			k+=(t[a[r]]*2+1)*a[r];
			t[a[r]]++;
		}
		while (r>q[i].r) {
			k-=(t[a[r]]*2-1)*a[r];
			t[a[r]]--;
			r--;
		}
		while (l<q[i].l) {
			k-=(t[a[l]]*2-1)*a[l];
			t[a[l]]--;
			l++;
		}
		while (l>q[i].l) {
			l--;
			k+=(t[a[l]]*2+1)*a[l];
			t[a[l]]++;
		}
		ans[q[i].id]=k;	
//		cout << l << ' ' << r << ' ' << k << endl;
	}
	for (i=1;i<=m;i++) 
		printf("%I64d\n",ans[i]); 
	return 0;
}
