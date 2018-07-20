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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[maxn][maxn],qx[40005],qy[40005],mark[maxn][maxn];
bool visit[maxn][maxn];

int main() {
	char c;
	int i,j,cas,n,m,l,k,x,y;
	int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	scanf("%d",&cas);
	while (cas--) {
		mem0(a);
		scanf("%d%d",&m,&n);
		scanf("%c",&c);
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				scanf("%c",&c);
				if (c=='X') a[i][j]=0; else a[i][j]=c-'A'+1;
			}
			scanf("%c",&c);
		}
		scanf("%d",&l);
		for (k=1;k<=l;k++) {
			scanf("%d%d",&y,&x);
			x++;y++;
			a[x][y]++;
			if (a[x][y]>4&&!mark[x][y]) {
				int h=0,t=1;
				qx[1]=x;qy[1]=y;
				mem0(visit);
				visit[x][y]=1;
				while (h<t) {
					h++;
					for (j=0;j<=3;j++) {
					//	cout << nowx << ' ' << nowy << endl;
						int nowx=qx[h]+dir[j][0],nowy=qy[h]+dir[j][1];
						if (a[nowx][nowy]) {
							a[nowx][nowy]++;
						if (!visit[nowx][nowy]&&a[nowx][nowy]>4
						&&nowx>0&&nowx<=n&&nowy>0&&nowy<=m) {
							t++;
							visit[nowx][nowy]=1;
							qx[t]=nowx;qy[t]=nowy;
						}
						}
					}
				}
			}
		}
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (a[i][j]>=4) printf("D"); 
				else if (a[i][j]==0) printf("X"); else 
				printf("%c",(char)(a[i][j]-1+'A'));
			}
			printf("\n");
		}
	}
	return 0;
}
