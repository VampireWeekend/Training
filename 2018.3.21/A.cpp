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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
long double a[maxn],b[maxn];

int main() {
	int n;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i]=1;
		int x=a[i];
		while (x) {
			x/=10;b[i]*=10.0L;
		}
	}
	for (i=1;i<=n;i++) {
		for (j=i;j<=n;j++) {
			if (cmp(a[i],a[j])) {
				swap(a[i],a[j]);
				swap(b[i],b[j]);
			}
		}
	}
	for (i=1;i<=n;i++)
	return 0;
}
