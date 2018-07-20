#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	long long n,i,j,ans;
	cin >> n;
	i=n/2;
	j=(n+1)/2;
	if (n<=2) {
		ans=0; 
	} else if (n>=6) {
		ans=i*j*(j-1)/2+i*(i-1)*(i-2)/6;
	} else {
		if (n==3) ans=1;
		if (n==4) ans=2;
		if (n==5) ans=6;
	}
	printf("%lld",ans);
	return 0;
}
