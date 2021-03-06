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
#define pb push_back
#define N 1000000
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[N+5],s[N+5];

int main() {
	a[1]=0;
	int n;
	cin >> n;
	for (int i=2;i<=n;i++) {
		a[i]=a[i/2];
		if (i*(i+1)/2%2) a[i]--; else a[i]++;
		s[i]=s[i-1]+abs(a[i]);
	}
	cout << s[n] << endl;
	return 0;
}
