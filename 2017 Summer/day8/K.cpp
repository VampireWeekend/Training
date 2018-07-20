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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int inque[maxn],step[maxn],dir[maxn];

struct cycle {
	int x,y,r;
};
cycle a[maxn];

int sqr(int r) {
	return r*r;
}

int gcd(int a,int b) {
	int x=a,y=b,z;
	while (y!=0) {
		z=y;
		y=x%y;
		x=z;
	}
	return x;
}

int main() {
	int n,i,flag=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++) 
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
	memset(step,-1,sizeof(step));
	queue<int> q;
	q.push(1);
	dir[1]=1;
	step[1]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		for (i=1;i<=n;i++)
			if (i!=now) 
				if ((sqr(a[i].x-a[now].x)+sqr(a[i].y-a[now].y))==sqr(a[now].r+a[i].r)) {
					if (step[i]==-1) {
						step[i]=step[now]+1;
						dir[i]=dir[now]*(-1);
						q.push(i);
					} else {
						if (dir[i]+dir[now]!=0) 
							flag=1;
					}
				}
		if (flag) break;
	}
	int l=gcd(a[n].r,a[1].r);
	if (step[n]!=-1&&!flag) 
	printf("%d:%d\n",a[1].r*dir[n]/l,a[n].r/l); 
	else 
	 if (flag) printf("The input gear cannot move.\n"); else 
	 printf("The input gear is not connected to the output gear.\n"); 
	return 0;
}
