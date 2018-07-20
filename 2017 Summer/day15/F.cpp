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
const int maxn=25,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
ll a[25];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	a[1]=1;a[2]=2;a[3]=4;a[4]=10;a[5]=32;
	a[6]=122;a[7]=544;a[8]=2770;a[9]=15872;
	a[10]=101042;a[11]=707584;a[12]=5405530;
	a[13]=44736512;a[14]=398721962;
	a[15]=3807514624;a[16]=38783024290;
	a[17]=419730685952;a[18]=4809759350882;
	a[19]=58177770225664;
	a[20]=740742376475050;
	int cas;
	scanf("%d",&cas); 
	while (cas--) {
		int n,m,i;
		scanf("%d%d",&n,&m);
		printf("%d %lld\n",n,a[m]);
	}
	return 0;
}

