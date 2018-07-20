#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dfs(ll sum,ll max) {
	if (sum<=0) 
	    if (sum==0) return 1; else return 0;
	ll ans=0;
	for (int i=max;i>=1;i--)
	    ans+=dfs(sum-i,i);
	return ans;
}

int main() {
	int n;
	FILE *f;
	f=fopen("1.txt","w");
	for (n=109;n<=120;n++) {
		ll ans=dfs(n,n);
		fprintf(f,"a[%d]=%lld;\n",n,ans);
	}
	fclose(f);
}
