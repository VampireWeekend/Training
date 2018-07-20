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
const int maxn=2005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[30],b[30];

bool dfs(int step,bool pair,int cnt) {
	if (step==5) return true;
	int i,j,flag=0;
	if (!pair)
	for (i=1;i<=9;i++) {
		if (b[i]>=2) {
			b[i]-=2;
			flag=flag|dfs(step+1,1,cnt);
			b[i]+=2;
		}
	}
	if (cnt<4)
	for (i=1;i<=9;i++) {
		if (b[i]>=3) {
			b[i]-=3;
			flag=flag|dfs(step+1,pair,cnt+1);
			b[i]+=3;
		}
	}
	if (cnt<4)
	for (i=1;i<=7;i++) {
		if (b[i]&&b[i+1]&&b[i+2]) {
			b[i]--;	b[i+1]--;b[i+2]--;
			flag=flag|dfs(step+1,pair,cnt+1);
			b[i]++; b[i+1]++;b[i+2]++;
		}
	}
	return flag;
}

int main() {
	int i,j,flag,n,k;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		mem0(b);
		for (j=1;j<=14;j++) {
			scanf("%d",&a[j]);
			b[a[j]]++;
		}
		if (dfs(0,0,0)) printf("Vulnerable\n"); else printf("Immune\n");
	}
	return 0;
}
