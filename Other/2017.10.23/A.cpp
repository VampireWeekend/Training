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
int a[maxn]; 

int main() {
	int cas,cnt=0,i,sum,f,x;
	f=1;a[0]=0;
	for (i=1;i<=100000;i++) {
		f=(f*2)%7;
		a[i]=a[i-1];
		if (f==1) a[i]++;
	}
	scanf("%d",&cas);
	while (cas--) {
		cnt++;
		scanf("%d",&x);
		printf("Case #%d: %d\n",cnt,a[x]);
	}
	return 0;
}
