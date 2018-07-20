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
int n;
int a[maxn],u[maxn];
int b[10005][maxn];
bool z[15];

void dfs(int len) {
	if (len==6) {
		n++;
		for (int i=0;i<6;i++) 
			b[n][i]=u[i];
		return;
	} else 
		for (int i=0;i<6;i++) 
			if (!z[i]) {
				z[i]=1;
				u[len]=i;
				dfs(len+1);
				z[i]=0;
			}
}

int main() {
	int i,j,k,h,p,l;
	for (i=0;i<6;i++) scanf("%d",&a[i]);
	n=0;
	mem0(z);
	dfs(0);
	int flag=0;
	for (i=1;i<=n;i++) {
		if (a[b[i][0]]+a[b[i][1]]==a[b[i][2]]+a[b[i][3]]&&
		   a[b[i][2]]+a[b[i][3]]==a[b[i][4]]+a[b[i][5]])
		   flag=1;
	}
	if (flag) printf("Yes"); else printf("No");
	return 0;
}

