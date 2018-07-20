#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn=1005;

struct Point{
	int x,y,num;
};
Point a[maxn]

bool cmp (Point a,Point b) {
	return a.x<b.x || (a.x==b.x&&a.y<b.y);
}

int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	
	return 0;
}
