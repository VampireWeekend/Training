#include <cstdio>
#include <iostream>
#include <string.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;   
int a[maxn][maxn];
ll fac[maxn];
bool z[maxn];

int main() {
	int cas;
	int n,i,j,m;
	fac[1]=1;
	for (i=2;i<=100;i++) {
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
	}
	while (scanf("%d%d",&n,&m)!=EOF) {
		int cnt=0,flag=1;
		for (i=1;i<=m;i++) {
			scanf("%d",&a[i][1]);
			if (a[i][1]==-1) {
				cnt++;
				continue;
		    }
			mem0(z);int k=1;z[a[i][1]]=1;
			for (j=2;j<=n;j++) {
				scanf("%d",&a[i][j]);
				if (!z[a[i][j]]) z[a[i][j]]=1,k++;
			}
			if (k!=n) flag=0;
		}
		if (!flag) {
			printf("0\n");
			continue;
		}
		if (cnt==1) {
			printf("1\n");
			continue;
		} else if (cnt!=0) {
			ll ans=1;
			for (i=1;i<cnt;i++) {
				ans*=fac[n];
				ans%=mod;
			}
			printf("%lld\n",ans);
		} else {
			int tot=0;
			for (i=1;i<=n;i++) {
				int p=i;
				for (j=m;j>=1;j--) {
					p=a[j][p];
				}
				if (p==i) tot++;
			}
			if (tot==n) printf("1\n"); else printf("0\n");
		}
	}
	return 0;
}

