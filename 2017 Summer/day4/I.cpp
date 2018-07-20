#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <cmath>
#include <queue>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn];
char s[105];

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	int n,m,i,j,c;
	while (scanf("%d",&c)!=EOF) {
		n=m=0;
		for (i=1;i<=c;i++) {
		scanf("%s",s);
		int j=0,k=0;
		while (s[j]>='0'&&s[j]<='9') {
			k=k*10+s[j]-'0';
			j++;
		}
		if (s[j]=='B') a[++n]=k; else b[++m]=k;
	    }
	    sort(a+1,a+n+1,cmp);
	    sort(b+1,b+m+1,cmp);
	    int h=min(n,m);
		int ans=0;
	    for (i=1;i<=h;i++) {
	    	ans+=a[i]+b[i]-1;
	    	ans--;
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
