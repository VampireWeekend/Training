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
int a[maxn][maxn];
char s[maxn];

int main() {
	int n,m,i,j;
	int sum=0;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (j=1;j<=m;j++) {
			a[i][j]=s[j]-'0';
			if (a[i][j]!=0) sum+=2;
		}
	}
	for (i=1;i<=n;i++) {
		sum+=2*a[i][1];
		for (j=2;j<=m;j++) {
			if (a[i][j]>a[i][j-1]) sum+=2*(a[i][j]-a[i][j-1]);
		}
	}
	for (i=1;i<=m;i++) {
		sum+=2*a[1][i];
		for (j=2;j<=n;j++) {
			if (a[j][i]>a[j-1][i]) sum+=2*(a[j][i]-a[j-1][i]);
		}
	}
	printf("%d\n",sum);
	return 0;
}
