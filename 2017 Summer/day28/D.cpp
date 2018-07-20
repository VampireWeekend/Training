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
int a[maxn],b[maxn];
int p[maxn][maxn];
int m,n;

bool check(int step) {
	for (int i=0;i<m;i++) {
		if (p[step][i]!=b[i]) return false;
	}
	return true;
}

bool inverse(int step) {
	for (int i=0;i<m;i++) {
		if (p[step][m-i-1]!=b[i]) return false;
	}
	return true;
}

bool dfs(int len,int step) {
	if (len<m) return false; 
	if (len==m) 
	    if (check(step-1)||inverse(step-1)) return true; else return false;
	bool z=false;
	int i;
	for (i=1;i<=len/2;i++) {
		int lc=i-1,rc=i;
		while (lc>=0&&rc<len) {
			p[step][lc]=p[step-1][lc]+p[step-1][rc];
			lc--;rc++;
		}
		for (int j=rc;j<len;j++) p[step][j-i]=p[step-1][j];
	//	for (int j=0;j<len-i;j++) printf("%d ",p[step][j]);
     //	printf("\n");
		z=z|dfs(len-i,step+1);
	}
	for (i=len/2+1;i<len;i++) {
		int lc=i-1,rc=i;
		while (lc>=0&&rc<len) {
			p[step][lc]=p[step-1][lc]+p[step-1][rc];
			lc--;rc++;
		}
		for (int j=0;j<=lc;j++) p[step][j]=p[step-1][j];
	//	for (int j=0;j<i;j++) printf("%d ",p[step][j]);
    // 	printf("\n");
		z=z|dfs(i,step+1);
	}
	return z;
}

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]); 
		p[0][i]=a[i];
	}
	scanf("%d",&m);
	for (i=0;i<m;i++) {
		scanf("%d",&b[i]); 
	}
	if (dfs(n,1)) printf("S"); else printf("N");
	return 0;
}
