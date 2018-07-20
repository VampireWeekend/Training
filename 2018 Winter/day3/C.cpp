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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

struct point{
	int x,y,z;
};
point p[maxn];

bool cmp(point a,point b) {
	return a.x<b.x || (a.x==b.x&&a.y<b.y) || (a.x==b.x&&a.y==b.y&&a.z<b.z);
}

bool pequal(point a,point b) {
	if (a.x==b.x&&a.y==b.y&&a.z==b.z) return true;
	return false;
}

int gcd(int x,int y) {  
    ll z;  
    if (x<y) swap(x,y);  
    while (y) {  
        z=y;y=x%y;x=z;  
    }  
    return x;  
}  

int main() {
	int n,i,x,y,z;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	n--;
	if (n==0) {
		cout << 0;return 0;
	}
	for (i=1;i<=n;i++) {
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		p[i].x-=x;p[i].y-=y;p[i].z-=z;
		if (p[i].x<0) {
			p[i].x=-p[i].x;p[i].y=-p[i].y;p[i].z=-p[i].z;
		}
		int u;
		if (p[i].x!=0) u=abs(p[i].x); else 
			if (p[i].y!=0) u=abs(p[i].y); else u=abs(p[i].z);
		if (p[i].y!=0) u=gcd(u,abs(p[i].y));
		if (p[i].z!=0) u=gcd(u,abs(p[i].z));
		if (p[i].x!=0) p[i].x/=u;
		if (p[i].y!=0) p[i].y/=u;
		if (p[i].z!=0) p[i].z/=u;
	}
	sort(p+1,p+n+1,cmp);
	int ans=1;
	for (i=2;i<=n;i++) {
		if (!pequal(p[i],p[i-1])) ans++;
	}
	cout << ans;
	return 0;
}
