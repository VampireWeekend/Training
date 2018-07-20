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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=45,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+9;   
const ld pi=acos(-1.0L);  
int f[maxn],o[maxn],ene[maxn];
ll com[3000005];
ll n,m,num;
bool use[maxn];
vector<int> v[maxn];

struct rel {
	int x,y,d;
};
rel r[maxn];

bool cmp(rel a,rel b) {
	return a.d<b.d;
}

int find(int x) {
	if (f[x]==x) return x; else {
		f[x]=find(f[x]);
		return f[x];
	}
}

ll dfs(int numr,ll e,ll tot) {
	if (numr==m+1) return com[tot];
	if (r[numr].d==0) {
		if (o[find(r[numr].x)]==3) return dfs(numr+1,e,tot-3);
		else {
			ll ans=0,w=e;
			bool z[maxn];mem0(z);
			for (int i=0;i<v[r[numr].a].size();i++) {
				if (!z[v[r[numr].a][i]]) {
					z[v[r[numr].a][i]]=1;
					w--;
				}
			}
			for (int i=0;i<v[r[numr].b].size();i++) {
				if (!z[v[r[numr].b][i]]) {
					z[v[r[numr].b][i]]=1;
					w--;
				}
			}
			if (w>0) {
				ans+=w*dfs(numr+1,e-1,tot-3);
			}
			ans+=tot*dfs(numr+1,r,tot-3);
			return ans%mod;
		}
	} else {
		for (i=1;i<=)
	}
}

int main() {
	scanf("%lld%lld",&n,&m);
	int x,y,a,b,cnt=0,d;
	ll i;
	map<int,int> mp;
	com[0]=1;
	for (i=3;i<=3000000;i+=3) {
		com[i]=com[i-3]+i*(i-1)/2*(i-2)/3;
		com[i]%=mod;
	}
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&d);
		a=mp[x],b=mp[y];
		if (!a) mp[x]=a=++cnt;
		if (!b) mp[y]=b=++cnt;
		r[i]=(rel){a,b,d};
	}
	sort(r+1,r+m+1,cmp);
	for (i=1;i<=40;i++) 
		f[i]=i;
	mem0(o);
	for (i=1;i<=m;i++) {
		if (r[i].d==0) {
			int fa=find(r[i].a),fb=find(r[i].b);
			if (fa!=fb) f[fa]=fb;
		} else {
			v[r[i].a].push_back(r[i].b);
			v[r[i].b].push_back(r[i].a);
			int fa=find(r[i].a),fb=find(r[i].b);
			if (fa==fb) {
				printf("0");
				return 0;
			}
		}
	}
	num=0;
	map<int,int> ak;
	for (i=1;i<=cnt;i++) {
		int p=find(i);
		if (!ak[p]) ak[p]=++num;
		o[ak[p]]++;
		if (o[ak[p]]>3) {
			printf("0");
			return 0;
		}
	}
	for (i=1;i<=num;i++) {
		ak[p]=
	}
	ll ans=dfs(num,3*n);
	return 0;
}

