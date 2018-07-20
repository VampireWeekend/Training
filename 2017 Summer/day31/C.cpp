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
const int maxn=15,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int a[maxn][maxn];
int p[maxn][maxn];
int b[10005][maxn];
int u[maxn];
bool z[maxn];
int n;

void dfs(int len) {
	if (len==7) {
		n++;
		for (int i=0;i<7;i++) 
			b[n][i]=u[i];
		return;
	} else 
		for (int i=0;i<7;i++) 
			if (!z[i]) {
				z[i]=1;
				u[len]=i;
				dfs(len+1);
				z[i]=0;
			}
}

int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	n=0;
	mem0(z);
	dfs(0);
//	b[1][0]=3;b[1][1]=0;b[1][2]=5;b[1][3]=6;b[1][4]=1;b[1][5]=4;b[1][6]=2;
	while (cas--) {
		cnt++;
		int i,j;
		for (i=0;i<7;i++) {
			for (j=0;j<6;j++) {
				scanf("%d",&a[i][j]);
				p[i][a[i][j]]=j; 
			}
		}
		for (i=1;i<=n;i++) {
			int c=b[i][0],pos;
			pos=p[c][1];
			int flag=1;
			for (j=2;j<7;j++) {
				int d=(p[b[i][j]][a[c][(pos+1)%6]]+1)%6,
				e=(p[b[i][j-1]][a[c][pos]]+5)%6;
				if (a[b[i][j]][d]!=
				a[b[i][j-1]][e]) {
					flag=0;
					break;
				}
				pos=(pos+1)%6;
			}
			if (!flag) continue; else 
			if (a[b[i][1]][(p[b[i][1]][a[c][(pos+1)%6]]+1)%6]!=
				a[b[i][6]][(p[b[i][6]][a[c][pos]]+5)%6])
			continue; else break;
		}
		printf("Case %d:",cnt);
		if (i==n+1) printf(" No solution\n"); else {
			for (j=0;j<7;j++) printf(" %d",b[i][j]);
			printf("\n");
		}
	}
	return 0;
}

