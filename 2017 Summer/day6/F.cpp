#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=200005;
int up[maxn],down[maxn];

struct arm{
	int pos,num;
};
arm a[maxn];

bool cmp(arm a,arm b){
	return a.pos<b.pos;
}

int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m); 
	for (i=1;i<=m;i++) {
		scanf("%d%d",&a[i].pos,&a[i].num); 
		up[i]=down[i]=0;
	} 
	sort(a+1,a+m+1,cmp);
	for (i=1;i<=m;i++) {
		int now=a[i].num;
		up[now+1]=max(up[now]+1,up[now+1]);
		down[now]=max(down[now+1]+1,down[now]);
	}
	for (i=1;i<=n;i++) {
		if (i!=n) printf("%d ",up[i]+down[i]+1);
		else  printf("%d",up[i]+down[i]+1);
	}
	printf("\n"); 
	return 0;
}
