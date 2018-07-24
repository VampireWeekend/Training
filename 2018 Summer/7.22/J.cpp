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
const int maxn=200005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
const ld pi=acos(-1.0L);
ll ans[maxn],lv[maxn][21],rv[maxn][21];
pp q[maxn];
vector<int> v[maxn];
int a[maxn];
ll n,m;

void divide(int l,int r,vector<int> v) {
	int mid=(l+r)/2;
	for (int i=mid+1;i<=r;i++)
		for (int j=m-1;j>=0;j--)
			rv[i][j]=0;
	for (int i=mid+1;i<=r;i++) {
		rv[i][a[i]]=1;
		for (int j=m-1;j>=0;j--) {
			rv[i][j]+=rv[i-1][j]+rv[i-1][(j-a[i]+m)%m]; 
			rv[i][j]%=mod;
		}
	}
	for (int i=mid;i>=l;i--)
		for (int j=m-1;j>=0;j--)
			lv[i][j]=0;
	for (int i=mid;i>=l;i--) {
		lv[i][a[i]]=1;
		for (int j=m-1;j>=0;j--) {
			lv[i][j]+=lv[i-1][j]+lv[i-1][(j-a[i]+m)%m];
			lv[i][j]%=mod;
		}
	}
	vector<int> ql,qr;
	int size=v.size();
	for (int i=0;i<size;i++) {
		int k=v[i];
		if (q[k].first<=mid&&q[k].second>mid) {
			ans[k]=lv[q[k].first][0]*rv[q[k].second][0]%mod;
			for (int j=1;j<=m-1;j++) {
				ans[k]+=lv[q[k].first][j]*rv[q[k].second][m-j];
				ans[k]%=mod;
			}
		} else
			if (q[k].second<=mid) ql.pb(k); else qr.pb(k);
	}
	if (ql.size()&&mid>l) divide(l,mid,ql);
	if (qr.size()&&mid+1<r) divide(mid+1,r,qr);
}

int main() {
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[i]%=m;
	}
	int q;
	scanf("%d",&qn);
	int x,y;
	for (int i=1;i<=qn;i++) {
		scanf("%d%d",&q[i].first,&q[i].second);
		if (q[i].first!=q[i].second) v.pb(i); else 
			if (a[i]==0) ans[i]=1;
	}
	divide(1,n,v);
	for (int i=1;i<=qn;i++) {
		printf("%lld\n",ans[i]);
	}
	return 0;
}