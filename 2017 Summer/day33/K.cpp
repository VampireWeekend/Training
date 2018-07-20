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
const int maxn=3005,maxk=300005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int f[maxn],pos[maxn],d[maxn],head[maxn];
int num;
map<int,vector<int> > mp;

struct Edge {
	int from,to,pre;
	ll dist;
};
Edge edge[maxk];

void addedge(int from,int to,ll dist) {
	edge[num]=(Edge){from,to,head[from],dist};
	head[from]=num++;
}

bool cmp(Edge a,Edge b) {
	return a.from<b.from || (a.from==b.from&&a.to<b.to);
}

int find(int x) {
	if (x==f[x]) return x; else {
		int t=f[x];
		f[x]=find(f[x]);
		d[x]=d[x]^d[t];    //保证和父亲方向不同 
		return f[x];
	}
}

bool solve(int n,int m) {
	int i;
	for (i=0;i<m;i++) {
		if (edge[i].from!=1) break;
		int to=edge[i].to;
		pos[to]=edge[i].dist;
		int size=mp[pos[to]].size();
		if (size<2) {
			mp[pos[to]].push_back(to);
			if (size==1) {
				int x=mp[pos[to]][0];
				int fa=find(x),fb=find(to);
				if (fa!=fb) {
					f[fa]=fb;
					d[fa]=d[x]^d[to]^1; 
				} else if (d[x]^d[to]==0) return false;
			}
		} else return false;
	}
	for (;i<m;i++) {
		int from=edge[i].from,to=edge[i].to;
		if (pos[from]+pos[to]==edge[i].dist) {   //在1的不同侧 
			int fa=find(from),fb=find(to);
			if (fa!=fb) {
				f[fa]=fb;
				d[fa]=d[from]^d[to]^1; 
			} else if (d[from]^d[to]==0) return false;
		} else if (abs(pos[from]-pos[to])==edge[i].dist) { //在1的同侧 
			int fa=find(from),fb=find(to);
			if (fa!=fb) {
				f[fa]=fb;
				d[fa]=d[from]^d[to]^0; 
			} else if (d[from]^d[to]==1) return false;
		} else return false;
	}
	for (i=1;i<=n;i++) find(i);
	return true;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,x,y,i;
		ll di;
		scanf("%d%d",&n,&m);
		printf("%d\n",n);
		num=0;
		mp.clear();
		memset(head,-1,sizeof(head));
		for (i=1;i<=n;i++) f[i]=i;
		for (i=1;i<=m;i++) {
			scanf("%d%d%lld",&x,&y,&di);
			if (x>y) swap(x,y);
			addedge(x,y,di);
		}
		sort(edge,edge+num,cmp);
		mem0(d);mem0(pos);
		pos[0]=0;
		if (solve(n,m)) {
			printf("0");
			for (i=2;i<=n;i++) {
				if (d[i]==1) printf(" %d",pos[i]); 
				    else printf(" -%d",pos[i]); 
			}
			printf("\n");
		} else printf("impossible\n");
	}
	return 0;
}

