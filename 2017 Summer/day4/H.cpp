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
typedef long long ll;

int main() {
	int k;
	ll n,m;
	scanf("%d",&k);
	while (k--) {
		scanf("%lld%lld",&n,&m);
		if ((n*m)%6==0&&n!=1&&m!=1) printf("Yes\n"); else printf("No\n"); 
	}
	return 0;
}
