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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int a[maxn][maxn];

int main() {
	int n,m;
	char s[4]={'D','R','U','R'};
	int dir[4][2]={{1,0},{0,1},{-1,0},{0,1}}; 
	scanf("%d",&n);
	while (scanf("%d%d",&n,&m)!=EOF) {
		int i,j,sum=0,p=inf,x,y;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				scanf("%d",&a[i][j]);
				sum+=a[i][j];
				if ((i+j)%2==1&&a[i][j]<p) p=a[i][j],x=i,y=j;
			}
		}
		if (n%2==1) {
			printf("%d\n",sum);
			for (i=1;i<=n;i++) {
				for (j=1;j<m;j++) {
					if (i%2==1) printf("R"); else printf("L");
				}
				if (i!=n) printf("D");
			}
		} else if (m%2==1) {
			printf("%d\n",sum);
			for (i=1;i<=m;i++) {
				for (j=1;j<n;j++) {
					if (i%2==1) printf("D"); else printf("U");
				}
				if (i!=m) printf("R");
			}
		} else {
			printf("%d\n",sum-p);
			for (i=1;i<=(x-1)/2*2;i++) {
				for (j=1;j<m;j++) {
					if (i%2==1) printf("R"); else printf("L");
				}
				printf("D");
			}
			int cnt=0,k=0;j=1;
			while (cnt<2*(m-1)) {
				cnt++;
				if (i+dir[k][0]==x&&j+dir[k][1]==y) {
					k=(k-1+4)%4;
					printf("%c",s[k]);
					i+=dir[k][0];j+=dir[k][1];
					k++;k%=4;
				} else {
					printf("%c",s[k]);
					i+=dir[k][0];j+=dir[k][1];
					k++;k%=4;
				}
			}
			if (i!=n) printf("D");
			for (i=(x-1)/2*2+3;i<=n;i++) {
				for (j=1;j<m;j++) {
					if (i%2==0) printf("R"); else printf("L");
				}
				if (i!=n) printf("D");
			}
		}
		printf("\n");
	}
	return 0;
}

