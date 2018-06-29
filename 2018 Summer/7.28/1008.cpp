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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],sum[maxn];
map<int,int> mp;

struct node {
	int x,y;
};
node b[maxn];

bool cmp(node a,node b) {
	return a.x>b.x || (a.x==b.x&&a.y>b.y);
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,i,j,q;
		scanf("%d%d",&n,&q);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		m=0;
		for (int i=1;i<=n;i++) {
			int k=mp[a[i]];
			if (k) {
				b[++m].x=k;
				b[m].y=a[i];
				mp[a[i]]=0;
			}
		}
		sort(b+1,b+m+1,cmp);
		int cnt=0;sum[1]=b[1].x;
		for (int i=2;i<=m;i++) {
			if (b[i].x==b[1].x) cnt++; else break;
			sum[i]=sum[i-1]+b[i].x;
		}
		if (cnt>q) {
			printf("-1\n");continue;
		}
		int ans=b[1].y;
		cnt++;
		int last=1;
		for (int i=cnt+1;i<=m;i++) {
			if (b[i].x==b[i-1].x) {
                sum[i]=sum[i-1]+b[i].x;
                continue;
            }
			if ((sum[last-1]-(b[last].x-1)*(last-1))+(i-last-1)<=q&&last!=1) ans=max(ans,b[last].y);
			last=i;
			sum[i]=sum[i-1]+b[i].x;
		}
		if ((sum[last-1]-(b[last].x-1)*(last-1))+(m-last)<=q&&last!=1) ans=max(ans,b[last].y);
		printf("%d\n",ans);
		mp.clear();
	}
	return 0;
}
