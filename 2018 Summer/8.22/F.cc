#define SUBMIT
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
#include <assert.h>
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=20000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=998244353;
const ld pi=acos(-1.0L);
ll a[maxn];

int main() {
	#ifdef SUBMIT
		long _begin_time = clock();
	#endif
    a[1]=1;a[2]=0;a[3]=0;a[4]=1;
    // a(n) = (n-2) * a(n-1) + (n-1) * a(n-2) - (-1)^n
    for (ll i=5;i<=20000000;i++) {
        a[i]=(i-2)*a[i-1]+(i-1)*a[i-2];
        if (i%2==0) a[i]--; else a[i]++;
        a[i]%=mod;
    }
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
	#ifdef SUBMIT
		long _end_time = clock();
		printf("time = %ld ms", _end_time - _begin_time);
	#endif
	return 0;
}
