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
const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int ans[7]={6,8,9,10,11,12,12};
int add[7]={0,-1,0,0,0,0,1};

int main() {
	int n,m=7,dep=1,base=12;
	scanf("%d",&n);
	if (n<=7) {
		printf("%d\n",ans[n-1]);return 0;
	}
	while (m<n) {
		dep++;
		m+=dep*6;
	}
	m-=dep*6;
	base+=(dep-2)*6;
	for (int i=1;i<=6;i++) {
		m+=add[i]+dep;
		base++;
		if (m>=n) break;
	}
	printf("%d\n",base);
	return 0;
}
