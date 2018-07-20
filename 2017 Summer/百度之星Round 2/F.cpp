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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
char s[maxn][maxn];
int a[maxn][maxn];
bool visit[maxn][maxn];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int flag,m,n; 

void dfs(int i,int j) {
	visit[i][j]=1;
	for (int k=0;k<4;k++) {
		int x=dir[k][0]+i,y=dir[k][1]+j;
		if (x>0&&y>0&&x<=n&&y<=m) {
			if (!visit[x][y]&&a[x][y]==1) dfs(x,y);
		}
	}
}

void dfs0(int i,int j) {
	visit[i][j]=1;
	for (int k=0;k<4;k++) {
		int x=dir[k][0]+i,y=dir[k][1]+j;
		if (x>0&&y>0&&x<=n&&y<=m) {
			if (!visit[x][y]&&a[x][y]==0) dfs0(x,y);
		} else flag=0;
	}
}

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	int i,j;
while (scanf("%d%d",&n,&m)!=EOF) {
	memset(a,-1,sizeof(a));
	for (i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for (j=1;j<=m;j++) {
			a[i][j]=s[i][j]-'0';
		}
	}
	int kuai1=0;
	mem0(visit);
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			if (a[i][j]==1&&!visit[i][j]) dfs(i,j),kuai1++;
		}
	}
	if (kuai1!=1) {
		printf("-1\n");
		continue;
	}
	int kuai0=0,wrap0=0;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			if (a[i][j]==0&&!visit[i][j]) {
				flag=1;
				dfs0(i,j),kuai0++;
				if (flag) wrap0++;
			}
		}
	}
	if (wrap0==1) printf("0\n"); else
	    if (wrap0==0) printf("1\n"); else printf("-1\n");
}
	return 0;
}

