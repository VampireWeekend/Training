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
ll a[maxn],f[maxn];

int main() {
	int n,i,ans,j;
	for (i=1;i<=100;i++) a[i]=i,f[i]=1;
	scanf("%d\n",&n);
	string s;
	ll d;
	for (i=1;i<=n;i++) {
		cin >> s >> d;
		if (s=="ADD") {
			for (j=1;j<=100;j++) {
				if (f[j]) a[j]+=d;
			}
		}
		if (s=="SUBTRACT") {
			for (j=1;j<=100;j++) {
				if (f[j]) a[j]-=d;
				if (a[j]<0) f[j]=0;
			}
		}
		if (s=="MULTIPLY") {
			for (j=1;j<=100;j++) {
				if (f[j]) a[j]*=d;
				if (a[j]<0) f[j]=0;
			}
		}
		if (s=="DIVIDE") {
			for (j=1;j<=100;j++) {
				if (f[j]) 
				if (a[j]%d==0) a[j]/=d; else f[j]=0;
			}
		}
	}
	ans=0;
	for (i=1;i<=100;i++) {
		if (!f[i]) ans++;
	}
	cout << ans;
	return 0;
}
