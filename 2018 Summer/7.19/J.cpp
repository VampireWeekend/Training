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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],cnt[maxn],ans[maxn],t[maxn];

struct query{
	int l,r,id,k;
};
query q[maxn];

bool cmp(query a,query b) {
	return a.k<b.k || (a.k==b.k&&a.r<b.r);
}

int main() {
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF) {
		mem0(cnt);
		int tot=0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if (!cnt[a[i]]) tot++;
			cnt[a[i]]++;
		}
		mem0(t);
		int size=sqrt(n);int qq=0,l,r;
		for (int i=1;i<=m;i++) {
			scanf("%d%d",&l,&r);
			l++;r--;
			if (l>r) {
				ans[i]=tot;continue;
			}
			qq++;
			q[qq].l=l;q[qq].r=r;
			q[qq].id=i;q[qq].k=q[qq].l/size;
		}
		sort(q+1,q+qq+1,cmp);
		int nl,nr,na=0;
		nl=q[1].l;nr=q[1].r;
		for (int i=nl;i<=nr;i++) {
			t[a[i]]++;
			if (t[a[i]]==cnt[a[i]]) na++;
		}
		ans[q[1].id]=tot-na;
		for (int i=2;i<=qq;i++) {
			while (nl<q[i].l) {
				if (t[a[nl]]==cnt[a[nl]]) na--;
				t[a[nl]]--;
				nl++;
			}
			while (nl>q[i].l) {
				t[a[nl-1]]++;
				if (t[a[nl-1]]==cnt[a[nl-1]]) na++;
				nl--;
			}
			while (nr>q[i].r) {
				if (t[a[nr]]==cnt[a[nr]]) na--;
				t[a[nr]]--;
				nr--;
			}
			while (nr<q[i].r) {
				t[a[nr+1]]++;
				if (t[a[nr+1]]==cnt[a[nr+1]]) na++;
				nr++;
			}
			ans[q[i].id]=tot-na;
		}
		for (int i=1;i<=m;i++) {
			printf("%d\n",ans[i]);
		}
	} 
	return 0;
}