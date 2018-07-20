#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#define mem0(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=200005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
ll a[maxn],b[maxn*5];
struct node {
	ll id,dist;
	node(ll id,ll dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist || (dist==x.dist&&id>x.id);
	}
};
priority_queue<node> pq;

int main() {
	int i,n,k,id;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	pq.push(node(1,a[1]));
	for (i=1;i<=k;i++) {
		b[i]=pq.top().dist;
		id=pq.top().id;
		if (id<n) {
			pq.push(node(id+1,b[i]-a[id]+a[id+1]));
			pq.push(node(id+1,b[i]+a[id+1]));
		}
		pq.pop();
	}
	printf("%lld\n",b[k]);
	return 0;
}

