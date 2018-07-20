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
const int maxn=5005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;

int a[maxn],x[maxn],x2[maxn],y[maxn],y2[maxn];
bool f[maxn];

bool judge(int i,int j) {
	if (x[i]==x[j]&&y[i]==y[j]) return true;
	if (x2[i]==x2[j]&&y2[i]==y2[j]) return true;
	if (x[i]==x2[j]&&y[i]==y2[j]) return true;
	if (x2[i]==x[j]&&y2[i]==y[j]) return true;
	return false;
}

int main() {
	freopen("lshape.in","r",stdin);
	freopen("lshape.out","w",stdout);
    int n,i,j,ans=0;
    scanf("%d",&n);
    mem0(f);
	for (i=1;i<=n;i++) {
		scanf("%d%d%d%d",&x[i],&y[i],&x2[i],&y2[i]);
		if (x2[i]-x[i]==0) f[i]=1; 
		//else k[i]=(ld)(y2[i]-y[i])/(ld)(x2[i]-x[i]);
		for (j=1;j<i;j++) {
			if (judge(i,j)) 
			if (f[j]) {
				if (y2[i]==y[i]) ans++;  
		    }
			else if (f[i]) {
				if (y2[j]==y[j]) ans++;
			}
		    else {
				if ((y[i]-y2[i])*(y[j]-y2[j])+(x[i]-x2[i])*(x[j]-x2[j])==0) 
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

