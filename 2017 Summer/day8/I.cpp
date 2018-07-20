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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[5],b[5];

int sqr(int x) {
	return x*x;
}

int main() {
	int i;
	for (i=1;i<=3;i++) scanf("%d",&a[i]);
	for (i=1;i<=3;i++) scanf("%d",&b[i]);
	sort(a+1,a+4);
	sort(b+1,b+4);
	int flag=0;
	if (sqr(a[1])+sqr(a[2])==sqr(a[3])) {
		if (a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]) flag=1;
	}
	if (flag) cout << "YES"; else cout << "NO";
	return 0;
}
