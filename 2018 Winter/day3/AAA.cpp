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
#include <sstream>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
ll a[maxn],p[55];

int main() {
	int t=2;string s;stringstream ss;
		s="";
		ss.clear();
		ss << t;ss >> s; 
		s="input"+s+".in";
		const char* pp = s.data();
		freopen(pp,"r",stdin);
		s="";
		ss.clear();
		ss << t;ss >> s; 
		s="outputw"+s+".out";
		const char* q = s.data();
		freopen(q,"w",stdout);
		
	ll n,mn=llinf,mx=-llinf;
	cin >> n;
	p[0]=1;
	for (int i=1;i<=18;i++) p[i]=p[i-1]*10;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		for (int j=1;j<i;j++) {
			ll x,y,z=0;
			x=a[i];y=a[j];
			for (int k=0;k<=9;k++) {
				z+=((x%10+y%10)%10)*p[k];
				x/=10;y/=10;
			}
			mn=min(mn,z);
			if (mn==306) {
				cout << i << ' ' << j << endl;
				cout << a[i] << ' ' << a[j] << endl;
			}
			mx=max(mx,z);
		}
		if (i==530) cout << mn << endl;
	}
	cout << mn << ' ' << mx << endl;
	return 0;
}
