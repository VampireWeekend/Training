
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
#define N 100000
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ll p[maxn],q[maxn];

int main() {
//	freopen("kids.in","r",stdin);
//	freopen("kids.out","w",stdout);
	int n,m,i,j,k;
//	scanf("%d%d",&m,&n);
for (m=1;m<=10;m++) {
	for (n=1;n<=10;n++) {
			mem0(p);
	mem0(q);
		p[1]=1;
	for (i=2;i<=n;i++) {
		q[1]=p[1];///(ld)m;
		for (j=2;j<=min(i,m);j++) {
			q[j]=p[j-1]*(ld)(m-j+1)+p[j]*(ld)j;
		}
		for (j=1;j<=min(i,m);j++) {
			p[j]=q[j];
//			cout << p[j] << ' ';
		}
//		cout << '\n';
	}
	ll sum=0L;
	for (i=1;i<=min(n,m);i++) {
		sum+=(ld)i*p[i];
	}
//	cout << setiosflags(ios::fixed) << setprecision(9);
	cout << m << ' ' << n << ' ' << sum << endl;
	}
} 
	
	return 0;
}
