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
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int maxn=55,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[maxn][maxn],visit[maxn][maxn],p[maxn][maxn];
int num[55];
char s[maxn];
int area,n,m;

void dfs(int i,int j,int c) {
	area++;
	visit[i][j]=1;
	for (int k=0;k<4;k++) {
		int nowx=i+dir[k][0],nowy=j+dir[k][1];
		if (nowx>0&&nowx<=n&&nowy>0&&nowy<=m) {
			if (a[nowx][nowy]==c&&!visit[nowx][nowy]) dfs(nowx,nowy,c);
		}
	}
}

void dfs2(int i,int j,int c) {
	a[i][j]=0;
	for (int k=0;k<4;k++) {
		int nowx=i+dir[k][0],nowy=j+dir[k][1];
		if (nowx>0&&nowx<=n&&nowy>0&&nowy<=m&&a[nowx][nowy]==c) {
			dfs2(nowx,nowy,c);
		}
	}
}

int main() {
	int q,i,j,k;
	scanf("%d%d",&n,&m);
	map<char,int> mp;
	map<int,char> mmp;
	mem0(a);
	int o[8];
	mem0(o);
	mp['B']=1;mp['G']=2;mp['R']=3;mp['W']=4;mp['Y']=5;
	mmp[1]='B';mmp[2]='G';mmp[3]='R';mmp[4]='W';mmp[5]='Y';
	for (i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (j=1;j<=m;j++) {
			p[i][j]=mp[s[j]];
			o[p[i][j]]=1;
		}
	}
	for (q=1;q<=5;q++) 
	if (o[q]) {
		memcpy(a,p,sizeof(a));
		int point=0;
		while (1) {
		mem0(visit);
		int frc=0,marea=0,x,y;
		for (i=n;i>=1;i--) {
			for (j=1;j<=m;j++) {
				if (a[i][j]&&!visit[i][j]) {
					area=0;
					dfs(i,j,a[i][j]);
					if (area>1) {
						if (frc==0) {
							frc=a[i][j];
							marea=area;
							x=i;y=j;
						} else
						if (frc==q&&a[i][j]!=q) {
							frc=a[i][j];
							marea=area;
							x=i;y=j;
						} else if (frc!=q) {
							if (a[i][j]!=q&&area>marea) {
								frc=a[i][j];
							    marea=area;
							    x=i;y=j;
							}
						} else {
							if (area>marea) {
								frc=a[i][j];
							    marea=area;
							    x=i;y=j;
							}
						}
					}
				}
			}
		}
		if (marea!=0) {
			point+=marea*(marea-1);
			dfs2(x,y,a[x][y]);
			int tay=0;
			for (j=1;j<=m;j++) {
				num[j]=0;
				for (i=n;i>=1;i--) {
					if (a[i][j]) {
						num[j]++;
						a[n-num[j]+1][j]=a[i][j];
					}
				}
				for(i=n-num[j];i>=1;i--) a[i][j]=0;
			}
			int u=0;
			for (j=1;j<=m;j++) {
				if (num[j]==0) {
					u++;
				} else if (u) {
					for (i=1;i<=n;i++) a[i][j-u]=a[i][j];
				}
			}
			for (j=m-u+1;j<=m;j++) 
				for (i=1;i<=n;i++) 
				    a[i][j]=0;
		} else break;
		} 
		printf("%c: %d\n",mmp[q],point);
    }
	return 0;
}
