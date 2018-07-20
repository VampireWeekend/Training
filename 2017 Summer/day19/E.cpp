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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=305,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
ld a[maxn][maxn],b[maxn][maxn],p[maxn][maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m,k,i,j,l,q;
		scanf("%d%d%d",&n,&m,&k);
		for (i=1;i<=n;i++) 
			for (j=1;j<=n;j++) 
			    cin >> a[i][j];
		for (i=1;i<=n;i++) 
			for (j=1;j<=m;j++) 
				cin >> b[i][j];
		for (i=1;i<=n;i++) 
			cin >> p[1][i];
		cout << setiosflags(ios::fixed) << setprecision(3);
		for (i=1;i<=k;i++) {
			scanf("%d",&l);
			int ans=0;ld mp=0L;
			for (j=1;j<=n;j++) {
				if (p[i][j]*b[j][l]>mp) 
					mp=p[i][j]*b[j][l],ans=j;
			}
			printf("%d",ans); 
			if (i!=k) printf(" ");
			for (q=1;q<=n;q++) 
				p[i+1][q]=0L;
			for (j=1;j<=n;j++) 
				for (q=1;q<=n;q++) 
					p[i+1][q]+=p[i][j]*a[j][q];
			for (q=1;q<=n;q++) {
				cout << p[i+1][q] << endl;
			}
		}
		printf("\n");
	}
	return 0;
}

