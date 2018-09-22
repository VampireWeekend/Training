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
const int maxn=10005,inf=0x3f3f3f3f,mod=256;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn],u[maxn],v[maxn];
bool visit[maxn][256];

int main() {
	ios::sync_with_stdio(false);
	int cas;
	cin >> cas;
	string s;
	while (cas--) {
		int n,x,y;
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> s;
			if (s[0]=='a') {
				a[i]=1;
				cin >> u[i];
			} else {
				if (s=="beq") a[i]=2; else if (s=="bne") a[i]=3; else if (s=="blt") a[i]=4; else a[i]=5;
				cin >> u[i] >> v[i];
			}
		}
		int now=0,pos=1,flag=0;
		mem0(visit);
		while (pos<=n) {
			if (visit[pos][now]) {
				flag=1;break;
			}
			visit[pos][now]=1;
			if (a[pos]==1) {
				now=now+u[pos];now%=mod;pos++;
			} else if (a[pos]==2) {
				if (now==u[pos]) pos=v[pos]; else pos++;
			} else if (a[pos]==3) {
				if (now!=u[pos]) pos=v[pos]; else pos++;
			} else if (a[pos]==4) {
				if (now<u[pos]) pos=v[pos]; else pos++;
			} else {
				if (now>u[pos]) pos=v[pos]; else pos++;
			}
		}
		if (flag) cout << "No\n"; else cout << "Yes\n";
	}
	return 0;
}
