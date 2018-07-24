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
int ans[maxn];

struct node{
	int l,r;
};
node a[maxn];

bool cmp(node a,node b) {
	return a.l<b.l || (a.l==b.l&&a.r>b.r);
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++) {
			scanf("%d%d",&a[i].l,&a[i].r);
		}
		sort(a+1,a+m+1,cmp);
		int last=0,pre=0;
		set<int> st;
		for (int i=1;i<=n;i++) st.insert(i),ans[i]=0;
		for (int i=1;i<a[1].l;i++) ans[i]=1;
		last=a[1].l-1;
		for (int i=1;i<=m;) {
			int k=i+1;
			while (a[k].r<=a[i].r&&k<=m)
				k++;
			set<int>::iterator iter = st.begin(),i1;
			if (a[i].l>last) {
				for (int j=last+1;j<a[i].l;j++) ans[j]=1;
				last=a[i].l-1;
			}
			for (int j=last+1;j<=a[i].r;j++) {
				ans[j]=*iter;
				i1=iter;iter++;
				st.erase(i1);
			}
			for (int j=pre+1;j<a[k].l;j++) if (ans[j]) st.insert(ans[j]);
			pre=a[k].l-1;
			last=a[i].r;
			i=k;
		}
		for (int i=1;i<=n;i++) {
			ans[i]=max(1,ans[i]);
			printf("%d",ans[i]);
			if (i!=n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
