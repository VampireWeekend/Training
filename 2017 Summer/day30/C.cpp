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
bool a[maxn];

int main() {
	int n,k,r,i,ans=0,x;
	scanf("%d%d%d",&n,&k,&r);
	mem0(a);
	for (i=1;i<=k;i++) {
		scanf("%d",&x);
		a[x]=1;
	}
	int tot=0;
	for (i=1;i<r;i++) {
		if (a[i]) tot++;
	}
	for (i=r;i<=n;i++) {
		if (a[i]) tot++;
		if (a[i-r]) tot--;
		if (tot==1) {
			if (!a[i]) a[i]=1; else a[i-1]=1;
			tot++;ans++;
		} else if (tot==0) {
			a[i]=a[i-1]=1;
			ans+=2;tot=2;
		}
	}
	printf("%d\n",ans);
	return 0;
}

