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
const int maxn=805,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int a[maxn][maxn];
int p[maxn*maxn];

int main() {
	int n,i,j,k,l,r,u,d,q;
	ll m=-llinf,w=llinf;
	scanf("%d%d",&n,&q);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
			m=max(m,(ll)a[i][j]);
			w=min(w,(ll)a[i][j]);
		}
	}
	for (i=1;i<=q;i++) {
		scanf("%d%d%d%d",&u,&l,&d,&r);
		int lc=w,rc=m,mid,tot=(r-l+1)*(d-u+1),ans;
		if (tot%2) tot/=2; else tot=tot/2-1;
		while (lc<=rc) {
		int cnt=0;
		mid=(lc+rc)/2;
		for (j=u;j<=d;j++) {
			for (k=l;k<=r;k++) {
				if (a[j][k]<mid) cnt++;
			}
		}
		if (cnt<=tot) lc=mid+1,ans=mid; else {
			rc=mid-1;
		}
	    }
	    printf("%d\n",ans);
	}
	return 0;
}

