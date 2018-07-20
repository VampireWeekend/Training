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
const int maxn=405,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
ll a[maxn][maxn],b[maxn][maxn];

ll gcd(ll a,ll b) {
	ll x,y,z;
	x=a;y=b;
	if (y>x) {
		z=y;y=x;x=z;
	}
	while (y) {
		z=y;y=x%y;x=z;
	}
	return x;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int cas;
	ll i,j;
    a[0][1]=b[0][1]=1;
    for (i=1;i<=400;i++) {
    	ll l=1,p=0;
    	for (j=2;j<=i+1;j++) {
    		if (b[i-1][j-1]==0) {
    			a[i][j]=1;b[i][j]=0;
    			continue;
    		}
    		ll u=gcd(a[i-1][j-1]*j,b[i-1][j-1]*i);
    		a[i][j]=a[i-1][j-1]*j;
    		a[i][j]/=u;
    		b[i][j]=b[i-1][j-1]*i;
    		b[i][j]/=u;
    		ll t=gcd(l,a[i][j]);
    		if (j==2) l=a[i][j]; else l=l/t*a[i][j];
    		if (j==2) p=b[i][j]; else {
    			p*=(a[i][j]/t);
    			p+=b[i][j]*l/a[i][j];
    		}
    	}
    	a[i][1]=l;
    	b[i][1]=l-p;
    }
    scanf("%d",&cas);
	while (cas--) {
		ll x,y,num;
		scanf("%lld%lld%lld",&num,&i,&j);
		printf("%lld ",num);
		if (b[i][j]==0) {
			printf("0\n");
			continue;
		}
		if ((a[i][j]>0&&b[i][j]<0)||(a[i][j]<0&&b[i][j]>0)) printf("-");
		if (a[i][j]==1) {
			printf("%lld\n",abs(b[i][j]));
		} else {
			printf("%lld/%lld\n",abs(b[i][j]),abs(a[i][j]));
		}
	}
	return 0;
}

