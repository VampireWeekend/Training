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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int a[maxn],c[maxn];

int getsg(int top) {
	bool visit[105];
	mem0(visit);
	if (top==0) return 0;
	for (int i=top;i>=1;i--) {
		if (a[i]) {
			for (int j=i-1;j>=i-c[i];j--) {
				a[j]++;
				a[i]--;
				int k=top;
				while (a[k]==0&&k>0) k--;
				visit[getsg(k)]=1;
				a[j]--;
				a[i]++;
			}
		}
	}
	for (int i=0;;i++)
	    if (!visit[i]) return i;
}

int main() {
	int n,i;
while (scanf("%d",&n)!=EOF) {
//	scanf("%d",&n);
	c[1]=a[1]=0;
	for (i=1;i<n;i++) {
		scanf("%d%d",&c[i],&a[i]);
		a[i]%=2;
	}
	int ans=getsg(n-1);
	if (ans) printf("First\n"); else printf("Second\n");
//	printf("%d\n",ans);
}
	return 0;
}

