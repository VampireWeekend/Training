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
const int maxn=2047;
int a[maxn+5];

int main() {
	int n,i,k;
	scanf("%d",&n);
	if (n<1024) 
	for (i=1;i<=n;i++) {
		k=i;int cnt=0;
		while (k%2==0) {
			cnt++;
			k/=2;
		}
		printf("%d",cnt);
	}
	else 
	for (i=1;i<=n;i++) printf("%d",0);
	return 0;
}
