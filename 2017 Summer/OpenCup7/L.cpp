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
const int maxn=25,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int dp[maxn][maxn][maxn][maxn];
char a[maxn][maxn];
char s[maxn][maxn];

int dfs(int x1,int y1,int x2,int y2) {
	if (dp[x1][y1][x2][y2]!=-1) return dp[x1][y1][x2][y2];
    int f;
    bool visit[100];
    mem0(visit);
    for (int i=x1;i<=x2;i++) {
        for (int j=y1;j<=y2;j++) {
            if (a[i][j]=='.') {
                int cnt=1;
                short path[45][2];
                a[i][j]='#';
                path[0][0]=i;path[0][1]=j;
                for (int k=i-1;k>=x1;k--) {
                	if (a[k][j]=='#') break;
                	a[k][j]='#';
                	path[cnt][0]=k;path[cnt++][1]=j;
                }
                for (int k=i+1;k<=x2;k++) {
                	if (a[k][j]=='#') break;
                	a[k][j]='#';
                	path[cnt][0]=k;path[cnt++][1]=j;
                }
                for (int k=j-1;k>=y1;k--) {
                	if (a[i][k]=='#') break;
                	a[i][k]='#';
                	path[cnt][0]=i;path[cnt++][1]=k;
                }
                for (int k=j+1;k<=y2;k++) {
                	if (a[i][k]=='#') break;
                	a[i][k]='#';
                	path[cnt][0]=i;path[cnt++][1]=k;
                }
                f=0;
                if (i-1>=x1&&j-1>=y1) f=f^dfs(x1,y1,i-1,j-1);
                if (i-1>=x1&&j+1<=y2) f=f^dfs(x1,j+1,i-1,y2);
                if (i+1<=x2&&j-1>=y1) f=f^dfs(i+1,y1,x2,j-1);
                if (i+1<=x2&&j+1<=y2) f=f^dfs(i+1,j+1,x2,y2);
                for (int k=0;k<cnt;k++) {
                   	a[path[k][0]][path[k][1]]=s[path[k][0]][path[k][1]];
                }
                visit[f]=1;
            }
        }
    }
    for (int i=0;;i++) {
    	if (!visit[i]) return dp[x1][y1][x2][y2]=i;
    }
    return 0;
}

int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	memset(dp,-1,sizeof(dp));
	for (i=1;i<=n;i++) {
		scanf("%s",a[i]+1);
		for (j=1;j<=m;j++) {
			s[i][j]=a[i][j];
		}
	}
	if (dfs(1,1,n,m)) printf("First"); else printf("Second");
	return 0;
}

