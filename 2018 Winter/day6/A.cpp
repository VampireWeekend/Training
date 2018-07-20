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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

ll gcd(ll x,ll y) {  
    ll z;  
    if (x<y) swap(x,y);  
    while (y) {  
        z=y;y=x%y;x=z;  
    }  
    return x;  
}

int main() {
	ll a,b,g;
	scanf("%I64d%I64d",&a,&b);
	g=gcd(a,b);
	if (g!=1) {
		printf("infinity infinity\n");
		return 0;
	}
	ll c,d;
	d=a*b-a-b;
	if (a>b) swap(a,b);
	c=b/a*a*(a-1)/2;
	c+=(b%a-1)*(a-1)/2;
	cout << c << ' ' << d;
	return 0;
}
