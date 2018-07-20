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
const int maxn=11005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
bool a[maxn];

ll gcd(ll x,ll y) {  
    ll z;  
    if (x<y) swap(x,y);  
    while (y) {  
        z=y;y=x%y;x=z;  
    }  
    return x;  
}

int main() {
	int n,m,i,j;
	freopen("out.txt","w",stdout);
	for (n=2;n<=100;n++) {
		for (m=n+1;m<=100;m++) {
			if (gcd(n,m)!=1) continue;
			mem0(a);
			priority_queue<int,vector<int>,greater<int> > pq;
			pq.push(n);pq.push(m);
			a[n]=a[m]=1;
			while (pq.top()<=n*m) {
				int now=pq.top();pq.pop();
				if (now+n<=n*m&&!a[now+n]) pq.push(now+n),a[now+n]=1;
				if (now+m<=n*m&&!a[now+m]) pq.push(now+m),a[now+m]=1;
			}
			int sum=0;
			for (i=1;i<=n*m;i++) if (!a[i]) sum++;
			cout << n << ' ' << m << ' ' << sum << endl; 
		}
	}
	fclose(stdout);
	return 0;
}
