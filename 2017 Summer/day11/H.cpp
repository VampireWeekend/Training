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
#define N 10
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
ld p[maxn],q[maxn];

int main() {
//	freopen("kids.in","r",stdin);
//	freopen("kids.out","w",stdout);
	int n,m,i,j;
	scanf("%d%d",&m,&n);
	ld k=1L;
	for (i=1;i<=n;i++) {
		k*=(ld)(m-1)/(ld)(m);
	}
	k=1L-k;
	k*=(ld)m;
	cout << setiosflags(ios::fixed) << setprecision(9);
	cout << k;
	return 0;
}

