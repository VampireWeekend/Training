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

struct name{
	string first,last;
};
name a[maxn];

bool cmp(name a,name b){
	return (a.last<b.last) || (a.last==b.last&&a.first<b.first);
}

int main() {
	int i,n; 
	scanf("%d\n",&n);
	for (i=1;i<=n;i++) {
		cin >> a[i].first >> a[i].last;
	}
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++) {
		cout << a[i].first << ' ' << a[i].last << endl;
	}
	return 0;
}
