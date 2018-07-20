#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=105;
char s[maxn][maxn];
int my[288];

int main() {
	int t,n,q,i,j;
	scanf("%d",&q);
	for (t=1;t<=q;t++) {
		scanf("%d",&n);
		int center=n/2,ans=0;
		for (i=0;i<n;i++) scanf("%s",s[i]);
		for (i=0;i<center;i++) {
			for (j=i;j<center;j++) {
				if (i==center-1&&j==center-1) continue;
				memset(my,0,sizeof(my));
				my[s[i][j]]++;
				my[s[n-i-1][j]]++;
				my[s[i][n-j-1]]++;
				my[s[n-i-1][n-j-1]]++;
				my[s[j][i]]++;
				my[s[j][n-i-1]]++;
				my[s[n-j-1][i]]++;
				my[s[n-j-1][n-i-1]]++;
				int m1=max(max(my[s[i][j]],my[s[n-i-1][n-j-1]]),
				max(my[s[i][n-j-1]],my[s[n-i-1][j]]));
				int m2=max(max(my[s[j][i]],my[s[j][n-i-1]]),
				max(my[s[n-j-1][i]],my[s[n-j-1][n-i-1]]));
				int m=max(m1,m2);
				if (i==j) ans+=(8-m)/2; else ans+=8-m;
			}
		}
		for (i=0;i<center;i++) {
			memset(my,0,sizeof(my));
			my[s[i][center]]++;
			my[s[n-i-1][center]]++;
			my[s[center][n-i-1]]++;
			my[s[center][i]]++;
			int m=max(max(my[s[i][center]],my[s[n-i-1][center]]),
			max(my[s[center][n-i-1]],my[s[center][i]]));
			ans+=4-m;
		}
		printf("%d\n",ans);
	}
	return 0;
}
