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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[1005],sg[1005];
int k;

int getsg(int top) {
	if (sg[top]!=-1) return sg[top];
	bool visit[1005];
	mem0(visit);
	for (int i=0;i<=min(k,top-1);i++) {
		if (top-i-a[top-i]>=0) visit[getsg(top-i-a[top-i])]=1;
	}
	for (int i=0;;i++) {
		if (!visit[i]) {
			sg[top]=i;
			return i;
		}
	}
}

int main() {
	int i,n,cas,sum=0;
	scanf("%d%d",&cas,&k);
	while (cas--) {
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
	    	scanf("%d",&a[i]);
	    }
	    memset(sg,-1,sizeof(sg));
	    sg[0]=0;
	    int ans=getsg(n);
	    sum=sum^ans;
	}
	if (sum) printf("Alice can win.\n"); 
	else printf("Bob will win.\n");
	return 0;
}
