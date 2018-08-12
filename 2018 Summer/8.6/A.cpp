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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
unsigned a[maxn];

unsigned x,w,y,z;
unsigned prand() {
	x=x^(x<<11);
	x=x^(x>>4);
	x=x^(x<<5);
	x=x^(x>>14);
	w=x^y^z;
	x=y;y=z;z=w;
	return z;
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,m;
		scanf("%d%d",&n,&m);
		unsigned f1,f2,l,r,v;
		scanf("%u%u%u",&x,&y,&z);
		int cnt=0;
		for (int i=1;i<=m;i++) {
			f1=prand();f2=prand();
			l=min(f1%n+1,f2%n+1);
			r=max(f1%n+1,f2%n+1);
			v=prand()%(1<<30);
			for (int j=l;j<=r;j++) a[j]=1;
		/*	if ((l<=100||r+100>=n)&&v>900000000) {
				cnt++;
			} */
		}
		cnt=0;
		for (int i=1;i<=n;i++) if (!a[i]) cnt++;
		printf("%d\n\n",cnt);
	}
	return 0;
}
