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
const int maxn=2005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
bool z[maxn][maxn];

int main() {
	int n,i,j,k,l,x1,x2,y1,y2;
	scanf("%d",&n);
	mem0(z);
	for (i=1;i<=n;i++) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		(y2-y1)/(x2-x1);
		int last=x1;
		for (j=x1+1;j<=x2;j++) {
			if (((y2-y1)*(j-x1))%(x2-x1)==0) {
				for (k=last;k<=j;k++) {
					
				}
				last=j;
			}
				cout << j << ' ' << k << endl;
		}
	}
	int ans=0;
	for (i=1;i<=2000;i++) {
		for (j=1;j<=2000;j++) {
			if (z[i][j]) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

