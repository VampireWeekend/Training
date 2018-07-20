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
ll ans;
int n;
int a[25];
int b[25];

void dfs(int last,int step,bool h,int n) {
	a[last]=1;
	b[step-1]=last;
	if (step==n+1) {
		ans++;
/*		printf("%d    ",ans);
		for (int i=1;i<step;i++) {
			printf("%d ",b[i]);
		}*/
		a[last]=0;
//	cout << '\n';
		return;
	}
	for (int i=1;i<=n;i++) {
		if (!a[i]) {
			if (h&&i>last) {
				dfs(i,step+1,!h,n);
			} 
		    if (!h&&i<last) {
		    	dfs(i,step+1,!h,n);
		    } 
		}
	}
	a[last]=0;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	for (n=17;n<=19;n++) {
		ans=0;
	 	for (int i=1;i<=n;i++) {
	 		ans=0;
			mem0(a);
			dfs(i,2,0,n);
			mem0(a);
			dfs(i,2,1,n);
		//	printf("%d %d %lld\n",n,i,ans);
		}
		printf("%d %lld\n",n,ans);
	}
	return 0;
}

