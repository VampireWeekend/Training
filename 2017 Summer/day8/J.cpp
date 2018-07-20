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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ll a[maxn][maxn],b[maxn][maxn];

int main() {
	ll l=1;
	int i,j,k,h,w,p;
	scanf("%d%d%d",&w,&h,&p);
	for (i=1;i<=p;i++) {
		l*=9;
	}
	for (i=1;i<=h;i++) {
		for (j=1;j<=w;j++) {
			scanf("%lld",&a[i][j]);
		    a[i][j]*=l;
		}
	}
	for (k=1;k<=p;k++) {
		a[0][0]=a[h][w];
		a[h+1][w+1]=a[1][1];
		a[h+1][0]=a[1][w];
		a[0][w+1]=a[h][1];
		for (i=1;i<=h;i++) {
			a[i][0]=a[i][w];
			a[i][w+1]=a[i][1];
		}
		for (j=1;j<=w;j++) {
			a[0][j]=a[h][j];
			a[h+1][j]=a[1][j];
		}
		for (i=1;i<=h;i++) {
			for (j=1;j<=w;j++) {
				b[i][j]=(a[i+1][j]+a[i-1][j]+a[i][j+1]+a[i][j-1]+
				a[i+1][j+1]+a[i-1][j-1]+a[i+1][j-1]+a[i-1][j+1]+a[i][j])/9;
			}
		}
		for (i=1;i<=h;i++) {
		for (j=1;j<=w;j++) {
			a[i][j]=b[i][j];
		}
	}  
	}
	map<ll,int> my;
	int ans=0;
	for (i=1;i<=h;i++) {
		for (j=1;j<=w;j++) {
			if (my[a[i][j]]==0) my[a[i][j]]++,ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
