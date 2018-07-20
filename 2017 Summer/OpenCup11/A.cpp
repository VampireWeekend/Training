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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
db l1[1<<18+5],l2[1<<18+5];
int p[maxn],q[maxn];

int gcd(int a,int b) {
	int x,y,z;
	x=a;y=b;
	if (x<y) swap(x,y);
	while (y) {
		z=y;y=x%y;x=z;
	}
	return x;
}

int main() {
	int n,a,b,m,i,j;
	scanf("%d%d%d",&n,&a,&b);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&p[i],&q[i]);
	}
	m=n/2;
	int ma=(1<<m)-1,f,s;
	for (i=1;i<=ma;i++) {
		f=s=0;
		for (j=m;j>0;j--) {
			if ((i>>j-1)%2==1) f+=p[i],s+=q[i];
		}
		int o=gcd(f,s);
		f/=o;s/=o;
		l1[i]=(db)f/(db)s;
	}
	m=n-m;
	ma=(1<<m)-1;
	for (i=1;i<=ma;i++) {
		f=s=0;
		for (j=m;j>0;j--) {
			if ((i>>j-1)%2==1) f+=p[i+n/2],s+=q[i+n/2];
		}
		int o=gcd(f,s);
		f/=o;s/=o;
		l1[i]=(db)f/(db)s;
	}
	return 0;
}
