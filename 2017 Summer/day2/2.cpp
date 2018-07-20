#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
ll n,a,b,c,d;
ll q[500005],w[500005];
int i;

int main() {
	cin >> n >> a >> b >> c >> d;
	int flag=0;
	for (i=1;i<=n;i++) {
		q[i]=a-(n-i)*d+(i-1)*c;
		w[i]=q[i]+(n-1)*(d-c);
		if (q[i]<=b&&b<=w[i]) flag=1;
	}
	if (flag) cout << "YES"; else cout << "NO";
	return 0;
}
