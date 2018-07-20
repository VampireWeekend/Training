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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define N 150
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=305,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int s[maxn][maxn];

int main() {
	int n,i,j,k,l,x,y;
//	scanf("%d",&n);
//    freopen("2.out","w",stdout);
	mem0(s);
	for (i=0;i<=N;i++) {
		for (j=0;j<=N;j++) {
			if (i*i+j*j>20000) break;
			for (k=0;k<=N;k++) {
				for (l=0;l<=N;l++) {
					if (abs(i)+abs(j)==1) continue;
					if (abs(k)+abs(l)==1) continue;
					if (k*k+l*l>20000) break;
					x=i*k-j*l;y=i*l+j*k;
					if (abs(x)>150||abs(y)>150||x<0||y<0) continue;
					s[x][y]++;
				}
			}
		}
	}
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
    	scanf("%d%d",&x,&y);
    	if (x<0) x=-x;
    	if (y<0) y=-y;
    	if (x*x+y*y<=1) printf("C\n"); else
    	if (s[x][y]) printf("C\n"); else printf("P\n");
    }
/*printf("int a[150][150]={");
	for (i=0;i<=N;i++) {
		printf("{");
		for (j=0;j<=N;j++) {
			if (j!=N) printf("%d,",s[i][j]); else printf("%d",s[i][j]);
		}
		printf("}");
		if (i!=N) printf(",");
	}
	printf("}");*/
	return 0;
}
