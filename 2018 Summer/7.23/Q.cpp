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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=10000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
ll a[maxn];

int main() {
	ll sum=2;a[1]=a[2]=1;
	for (int i=3;i<=10000000;i++) {
		a[i]=a[i-a[i-1]]+a[i-1-a[i-2]];
	//	cout << a[i] << endl;
		sum+=a[i];sum%=(1000000007);
	}
	cout << a[10000000] << ' ' << sum%(1000000007);
	return 0;
}
