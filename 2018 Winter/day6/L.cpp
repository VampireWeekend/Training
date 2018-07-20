#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn][maxn],p[maxn][maxn],cnt[maxn];
char s[maxn];
vector<int> v[maxn];

int main() {
	int cas,n;
	scanf("%d",&cas);
	while (cas--) {
		scanf("%d",&n);
		scanf("%s",s);
		mem0(cnt);
		int i,j,k;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				scanf("%d",&a[i][j]);
				p[i][j]=0;
			}
			v[i].clear();
		}
		if (s[0]=='d')
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][j]==0) {
					for (k=i;k>1;k--) {
						a[k][j]=a[k-1][j];
					}
					a[1][j]=0;
				}
			}
		}
		if (s[0]=='u') {
			for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][j]==0) {
					for (k=i+1;k<=n;k++) {
						a[k-1][j]=a[k][j];
					}
					a[n][j]=0;
				}
			}
		}
		}
		if (s[0]=='l') {
			for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][j]==0) {
					for (k=j+1;k<=n;k++) {
						a[i][k-1]=a[i][k];
					}
					a[i][n]=0;
				}
			}
		}
		}
		if (s[0]=='r') {
			for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][j]==0) {
					for (k=j-1;k>=1;k--) {
						a[i][k+1]=a[i][k];
					}
					a[i][1]=0;
				}
			}
		}
		}
		if (s[0]=='d')
		for (i=n-1;i>=1;i--) {
			for (j=1;j<=n;j++) {
				if (a[i][j]==a[i+1][j]&&!p[i+1][j]) {
					p[i][j]=1;a[i][j]*=2;a[i+1][j]=0;
				}
			}
		}
		if (s[0]=='u')
		for (i=2;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][j]==a[i-1][j]&&!p[i-1][j]) {
					p[i][j]=1;a[i][j]*=2;a[i-1][j]=0;
				}
			}
		}
		if (s[0]=='r')
		for (i=n-1;i>=1;i--) {
			for (j=1;j<=n;j++) {
				if (a[j][i]==a[j][i+1]&&!p[j][i+1]) {
					p[j][i]=1;a[j][i]*=2;a[j][i+1]=0;
				}
			}
		}
		if (s[0]=='l')
		for (i=2;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[j][i]==a[j][i-1]&&!p[j][i-1]) {
					p[j][i]=1;a[j][i]*=2;a[j][i-1]=0;
				}
			}
		}
		if (s[0]=='u'||s[0]=='d')
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[j][i]!=0) cnt[i]++,v[i].push_back(a[j][i]);
			}
		}
		if (s[0]=='l'||s[0]=='r')
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][j]!=0) cnt[i]++,v[i].push_back(a[i][j]);
			}
		}
		if (s[0]=='u')
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (i>cnt[j]) printf("0"); else printf("%d",v[j][i-1]);
				if (j!=n) printf(" ");
			}
			printf("\n");
		}
		if (s[0]=='d')
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (n-i+1>cnt[j]) printf("0"); else printf("%d",v[j][i+cnt[j]-n-1]);
				if (j!=n) printf(" ");
			}
			printf("\n");
		}
		if (s[0]=='l')
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (j>cnt[i]) printf("0"); else printf("%d",v[i][j-1]);
				if (j!=n) printf(" ");
			}
			printf("\n");
		}
		if (s[0]=='r')
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (n-j+1>cnt[i]) printf("0"); else printf("%d",v[i][j+cnt[i]-n-1]);
				if (j!=n) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
