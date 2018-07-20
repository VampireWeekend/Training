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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	ll a,b,c;
	cin >> a >> b >> c;
	ll p;
	if (b>c) swap(b,c);
	p=c/b*b;
	if (p<c) p+=b;
	if (p<=a) cout << "OK"; else cout << "DEADLOCK";
	return 0;
}

