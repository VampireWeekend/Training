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
const int maxn=50005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int pre[maxn][340],head[maxn],a[maxn],fa[maxn][20],dep[maxn];
int nu[55];
int num=0,size;

struct Edge {
    int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from,int to) {
    edge[num]=(Edge){from,to,head[from]};
    head[from]=num++;
    edge[num]=(Edge){to,from,head[to]};
    head[to]=num++;
}

void dfs(int now,int f,int step) {
	fa[now][0]=f;
	for (int i=1;fa[now][i-1]!=0;i++)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	dep[now]=step;
	for (int i=1;i<=size;i++) {
		int k=i,node=now;
		for (int j=18;j>=0;j--) {
			if (k<nu[j]) continue;
			node=fa[node][j];
			k-=nu[j];
		}
		pre[now][i]=pre[node][i]^a[now];
	}
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=f) {
			dfs(to,now,step+1);
		}
	}
}

int findlca(int a,int b) {
    int x=a,y=b;
    int i;
    if (dep[x]>dep[y]) swap(x,y);
    for (i=18;i>=0;i--) {
    	if (dep[fa[y][i]]>=dep[x]) y=fa[y][i];
    }
    if (y==x) return x;
    for (i=18;i>=0;i--) {
    	if (fa[y][i]!=fa[x][i]&&fa[x][i]!=0&&fa[y][i]!=0) {
    		x=fa[x][i];y=fa[y][i];
    	}
    }
    return fa[x][0];
}

int main() {
	nu[0]=1;
	int n,q;
	for (int i=1;i<=18;i++) nu[i]=nu[i-1]*2;
	while (scanf("%d%d",&n,&q)!=EOF) {
		int x,y,z;
		size=sqrt(n);
		num=0;memset(head,-1,sizeof(head));
		mem0(fa);mem0(pre);
		for (int i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		dfs(1,0,1);
		for (int i=1;i<=q;i++) {
			scanf("%d%d%d",&x,&y,&z);
			int ans=0;
			int m=findlca(x,y);
			if (z<=size) {
				//  contribution of lca-->x
				int k=dep[x]-dep[m]+1;k=k/z*z;
				if (k<dep[x]-dep[m]+1) k+=z;
				int node=x;
				for (int j=18;j>=0;j--) {
					if (k<nu[j]) continue;
					node=fa[node][j];
					k-=nu[j];
				}
		//		cout << x << ' ' << node << endl;
				ans=pre[x][z]^pre[node][z];
				//  contribution of lca-->y
				int len=dep[x]+dep[y]-2*dep[m];
				k=len%z;
				int ny=y;
				for (int j=18;j>=0;j--) {
					if (k<nu[j]) continue;
					ny=fa[ny][j];
					k-=nu[j];
				}
				if (dep[ny]<=dep[m]) {
					printf("%d\n",ans);
					continue;
				}
				k=dep[ny]-dep[m];k--;
				k=k/z*z;
				k+=z;
				node=ny;
				for (int j=18;j>=0;j--) {
					if (k<nu[j]) continue;
					node=fa[node][j];
					k-=nu[j];
				}
				ans=ans^(pre[node][z]^pre[ny][z]);
		//		cout << ny << ' ' << node << endl;
				printf("%d\n",ans);
			} else {
				//  contribution of lca-->x
				int node=x,k;
				while (dep[node]>=dep[m]) {
					ans^=a[node];
					k=z;
					for (int j=18;j>=0;j--) {
						if (k<nu[j]) continue;
						node=fa[node][j];
						k-=nu[j];
					}
				}
				//  contribution of lca-->y
				int len=dep[x]+dep[y]-2*dep[m];
				k=len%z;
				int ny=y;
				for (int j=18;j>=0;j--) {
					if (k<nu[j]) continue;
					ny=fa[ny][j];
					k-=nu[j];
				}
				if (dep[ny]<=dep[m]) {
					printf("%d\n",ans);
					continue;
				}
				node=ny;
				while (dep[node]>dep[m]) {
					ans^=a[node];
					int k=z;
					for (int j=18;j>=0;j--) {
						if (k<nu[j]) continue;
						node=fa[node][j];
						k-=nu[j];
					}
				}
		//		cout << ny << ' ' << node << endl;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
