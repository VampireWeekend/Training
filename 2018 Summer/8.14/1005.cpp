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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int f[maxn],d[maxn],x[maxn],z[maxn],men[maxn],id[maxn],fa[maxn],a[maxn];
int ff[maxn];
char s[maxn];
vector<int> ans,v[maxn];

int find(int x){
     if (f[x] == x) return x;
     int fa = f[x];
     f[x] = find(f[x]);
     d[x] ^=d[fa];
     return f[x];
}

bool join(int x,int y,int op)
{
    int fx=find(x),fy=find(y);
	if (fx==fy) {
		if (d[x]!=d[y]&&op==0) return false;
		if (d[x]==d[y]&&op==1) return false;
		return true;
	}
    f[fy]=fx;
    d[fy]=op^d[x]^d[y];
	return true;
}

int main() {
	int n,m,k=0,l;
	scanf("%d%d",&n,&m);
	bool flag=1;
	for (int i=1;i<=n;i++) f[i]=i,d[i]=0,men[i]=0;
	for (int i=1;i<=m;i++) {
		scanf("%s",s);
		if (s[0]=='p') {
			int u,v;
			scanf("%d%d",&u,&v);
			if (men[u]&&men[v]) ans.pb(i);
			men[u]=men[v]=1;
			if (s[1]=='a') flag&=join(u,v,0); else flag&=join(u,v,1);
		} else {
			scanf("%d",&l);
			k++;
			if (s[0]=='h') z[k]=1; else z[k]=2;
			x[k]=l;
			id[k]=i;
		}
	}
	if (!flag) {
		printf("inconsistent\n");return 0;
	}
	for (int i=1;i<=n;i++) {
		int faa=find(i);
		fa[i]=faa;
		v[faa].pb(i);
	}
	for (int i=1;i<=k;i++) {
		if (a[x[i]]) {
			if (a[x[i]]!=z[i]) {
				flag=0;
				break;
			}
			ans.pb(id[i]);
            continue;
		}
		if (d[x[i]]==0) a[fa[x[i]]]=z[i]; else a[fa[x[i]]]=3-z[i];
		for (auto j:v[fa[x[i]]]) {
			if (j==fa[x[i]]) continue;
			if (d[j]==0) a[j]=a[fa[x[i]]]; else a[j]=3-a[fa[x[i]]];
		}
	}
	if (!flag) {
		printf("inconsistent\n");return 0;
	} else printf("consistent\n");
/*	for (int i=1;i<=n;i++) {
		cout << f[i] << ' ' << d[i] << endl;
	}*/
	int sz=ans.size();
	printf("%d\n",sz);
	for (auto j:ans) {
		printf("%d ",j);
	}
//	system("pause");
	return 0;
}
