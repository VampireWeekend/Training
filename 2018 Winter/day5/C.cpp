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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

struct point{
	db x,y;
};
point p[maxn];

struct pointc{
	int x,y;
};
pointc pp[maxn];

bool cmp(point a,point b) {
	return a.x<b.x || (a.x==b.x&&a.y<b.y);
}

bool cmpc(pointc a,pointc b) {
	return a.x<b.x || (a.x==b.x&&a.y<b.y);
}

db sqr(db x) {
	return x*x;
}

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		int i,j,b=-inf;
		for (i=1;i<=n;i++) {
			scanf("%d%d",&pp[i].x,&pp[i].y);
			b=max(b,pp[i].x+pp[i].y);
			p[i].x=(db)pp[i].x;p[i].y=(db)pp[i].y;
		}
		int sum=0;
		for (i=1;i<=n;i++) {
			if (pp[i].x+pp[i].y==b) sum++;
		}
		sort(p+1,p+n+1,cmp);
		sort(pp+1,pp+n+1,cmpc);
/*		cout << '\n';
		for (i=1;i<=n;i++) {
			cout << p[i].x << ' ' << p[i].y << endl;
		}*/
		int pre=0,cnt=0;
		db ans=((db)b)*sqrt(2.0),d,k;
		for (i=1;i<=n;i++) {
			if (pp[i].x+pp[i].y==b) {
				cnt++;
				if (cnt!=1) continue;
				for (j=pre+1;j<=i;j++) {
					if (pp[j].y>pp[i].y&&pp[j].x<pp[i].x) {
						k=(p[i].y-p[j].y)/(p[i].x-p[j].x);
						d=sqrt(sqr(p[i].x-p[i].y/k)+sqr(p[i].y-k*p[i].x));
						ans=min(ans,d);
					}
				}
				pre=i;
			} else if (pre!=0) { 
				if (cnt!=sum) continue;
				k=(p[pre].y-p[i].y)/(p[pre].x-p[i].x);
				d=sqrt(sqr(p[pre].x-p[pre].y/k)+sqr(p[pre].y-k*p[pre].x));
				ans=min(ans,d);
			}
	//		printf("%.3lf\n",ans);
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
