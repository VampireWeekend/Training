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
const ld pi=3.1415926535898L;
int a[maxn],ans[maxn],pre[maxn],t[maxn];

struct query{
	int l,r,kuai;
};
query q[maxn];

bool cmp(query a,query b) {
	return a.kuai<b.kuai || (a.kuai==b.kuai&&a.r<b.r);
}

int main() {
	int n,k,i,j,flag=0,m=0;
	scanf("%d%d",&n,&k);
	mem0(pre);
	int size=sqrt(n);
	for (i=1;i<=k;i++) {
		scanf("%d",&a[i]);
		if (!pre[a[i]]) {
			printf("%d ",a[i]);
		} else {
			q[++m].l=pre[a[i]];q[m].r=i-1;q[m].kuai=pre[a[i]]/size;
		}
		pre[a[i]]=i;
	}
	for (i=1;i<=n;i++) {
		if (!pre[i]) printf("%d ",i);
	}
	printf("\n");
	sort(q+1,q+m+1,cmp);
	mem0(t);
	memset(ans,-1,sizeof(ans));
	int b=0,nl,nr;
	for (i=q[1].l;i<=q[1].r;i++) {
		if (!t[a[i]]) b++;
		t[a[i]]++;
	}
	ans[q[1].l]=b-1;
	nl=q[1].l;nr=q[1].r;
	for (i=2;i<=m;i++) {
//		cout << q[i].l << ' ' << q[i].r << endl;
		while (nl<q[i].l) {
			t[a[nl]]--;
			if (t[a[nl]]==0) b--;
			nl++;
		}
		while (nl>q[i].l) {
			if (t[a[nl-1]]==0) b++;
			t[a[nl-1]]++;
			nl--;
		}
		while (nr>q[i].r) {
			t[a[nr]]--;
			if (t[a[nr]]==0) b--;
			nr--;
		}
		while (nr<q[i].r) {
			if (t[a[nr+1]]==0) b++;
			t[a[nr+1]]++;
			nr++;
		}
		ans[q[i].l]=b-1;
	} 
	for (i=1;i<=k;i++) {
		if (ans[i]==-1) printf("%d\n",n-1); 
		    else printf("%d\n",ans[i]);
	}
	return 0;
}

