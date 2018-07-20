#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;
typedef long double ld;
const int maxn=100005;
int a[maxn];

int main() {
	int n,k,i,j,q=0;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (i>1&&a[i]!=a[i-1]) q++;
	}
	ld ans=(ld)(k-1)/(ld)k;
	ans*=(ld)q;
	cout << setiosflags(ios::fixed) << setprecision(9);
	cout << ans;
	return 0;
}
