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
const int maxn=15,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll u[maxn],f[maxn],uc[maxn],fc[maxn],st[maxn];

int main() {
	int i,j;
	ll ans;
	for (i=1;i<=10;i++) {
		scanf("%lld%lld",&uc[i],&fc[i]);
	}
	for (i=1;i<=10;i++) {
		scanf("%lld%lld%lld",&u[i],&f[i],&st[i]);
	}
	ans=0;ll t=0;
	for (int T=1;T<=3;T++) {
		for (i=1;i<=10;i++) {
	//		for (j=1;j<=10;j++) {
				if (st[i]<t) {
					st[i]+=(t-st[i])/(u[i]+f[i])*(u[i]+f[i]);
//					if (st[i]<t) st[i]+=(u[i]+f[i]);
				}
				if (st[i]>t) {
					t+=uc[i];st[i]=max(st[i],t);t+=fc[i];
				} else
				if (st[i]+u[i]<t) {
					t+=uc[i];
					st[i]=max(t,st[i]+u[i]+f[i]);
					t+=fc[i];
				} else {
					st[i]+=u[i];
					t=st[i]+uc[i];
					st[i]=max(st[i]+f[i],t);
					t+=fc[i];
				}
				cout << t << ' ' << st[i] << endl;
	//		}
		}
	//	cout << '\n';
	}
	t-=fc[10];
	cout << t << endl;
	return 0;
}
