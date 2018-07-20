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
const int maxn=50005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int num;
int visit[maxn*2],head[maxn*2];

struct Pair{
	int a,b;
};
Pair p[maxn];

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

bool cmp(Pair x,Pair y) {
	return x.a<y.a || (x.a==y.a&&x.b<y.b);
}

void addedge (int from,int to) {
	edge[num]=(Edge) {from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge) {to,from,head[to]};
	head[to]=num++;
}

bool dfs(int fa,int now,int t) {
	visit[now]=t;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			if (dfs(now,to,t)) return true;
		} else if (visit[to]==t&&fa!=to) return true;
	}
	return false;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int k,i,x,y,z,n=0;
	num=0;
	scanf("%d",&k);
	map<int,int> mp;
	memset(head,-1,sizeof(head));
	for (i=1;i<=k;i++) {
		scanf("%d%d%d",&x,&y,&z);
		p[i].a=x*1e6+y*1e3+z;
		int f=mp[p[i].a];
		if (f==0) mp[p[i].a]=f=++n;
		scanf("%d%d%d",&x,&y,&z);
		p[i].b=x*1e6+y*1e3+z;
		int g=mp[p[i].b];
		if (g==0) mp[p[i].b]=g=++n;
		addedge(f,g);
		p[i].a/=1e3;
		p[i].b/=1e3;
	}
	mem0(visit);
	int flag=0,m=0;
	for (i=1;i<=n;i++) {
		if (!visit[i]) flag=flag|dfs(0,i,++m);
	}
	if (flag) printf("True closed chains\n");
    	else printf("No true closed chains\n");
    memset(head,-1,sizeof(head));
    num=0; 
    mp.clear();
    n=0;
    sort(p+1,p+k+1,cmp);
    p[0].a=0;
    for (i=1;i<=k;i++) {
    	int f=mp[p[i].a],g=mp[p[i].b];
    	if (!f) mp[p[i].a]=f=++n;
    	if (!g) mp[p[i].b]=g=++n;
    	if (f!=g&&!(p[i].a==p[i-1].a&&p[i].b==p[i-1].b)&&
		!(p[i].a==p[i-1].b&&p[i].b==p[i-1].a)) addedge(f,g);
    }
/*    for (i=0;i<num;i++) {
		cout << edge[i].from << ' ' << edge[i].to << endl;
	}*/
    mem0(visit);
	flag=0;m=0;
	for (i=1;i<=n;i++) {
		if (!visit[i]) flag=flag|dfs(0,i,++m);
	}
	if (flag) printf("Floor closed chains\n"); 
	    else printf("No floor closed chains\n");
	return 0;
}

