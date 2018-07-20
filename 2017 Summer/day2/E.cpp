#include <iostream>
#include <string.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=100005;
struct Point {
	int val,pos;
};
Point a[maxn];

bool cmp (Point x,Point y){
	return x.val<y.val || (x.val==y.val&&x.pos<y.pos);
}

int main() {
	int n,k,i,j,ans;
	while (scanf("%d%d",&n,&k)!=EOF) {
		for (i=1;i<=n;i++) {
			a[i].pos=i;
			scanf("%d",&a[i].val);
		}
		sort(a+1,a+n+1,cmp);
		j=ans=1;
		for (i=2;i<=n;i++) {
			if (a[i].val==a[i-1].val) {
				while ((a[i].pos-a[j].pos)-(i-j)>k) j++;
				ans=max(ans,i-j+1);
			} else {
				j=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
