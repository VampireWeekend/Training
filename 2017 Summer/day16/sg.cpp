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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);

int getsg(int n) {
	if (n==1) return 0;
	bool visit[256];
	mem0(visit);
	for (int i=1;i<=n/2;i++) {
		int f=getsg(n-i);
	//	if (!f) 
		visit[f]=1;
	}
	for (int i=0;;i++)
	    if (!visit[i]) return i;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	for (int n=1;n<=100;n++) {
		cout << n << ' ' << getsg(n) << endl;
	} 
	return 0;
}

