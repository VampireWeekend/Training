#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn=500005;
int a[maxn];

struct Node {
	int b,c;
} node[maxn];

bool cmp(Node x,Node y) {
	return x.b-x.c>y.b-y.c;
}
 
int main() {
	int n,i,k,j,ans=0,sum=0;
	memset(node,0,sizeof(node));
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]<0) node[i%k].b++; else node[i%k].c++;
	}
	sort(node,node+k,cmp);
	for (i=0;i<k;i++) {
		sum+=node[i].b;
	}
	ans=sum;
	for (i=1;i<k;i+=2) {
		sum+=node[i].c+node[i-1].c;
		sum-=node[i].b+node[i-1].b;
		ans=min(ans,sum);
	}
	printf("%d",ans);
	return 0;
}
