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

int main() {
	ll n,i,cnt=0;
	cin >> n;
	while (n>3) {
		if (n%2==0) printf("["); else printf("1[");
		n/=2;
		cnt++;
	}
	if (n==3) printf("111");
	else if (n==2) printf("11"); else if (n==1) printf("1");
	for (i=1;i<=cnt;i++) {
		printf("]");
	}
	return 0;
}
