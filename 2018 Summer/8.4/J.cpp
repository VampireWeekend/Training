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
#include <assert.h>
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define N 15
using namespace std;
typedef unsigned ull;
typedef long double ld;
typedef unsigned long long ULL;
typedef double db;
typedef pair<int,int> pp;
const ld pi=acos(-1.0L);
ull arr[105];

ull x,y,z;
ull prand() {
	x^=x<<16;
	x^=x>>5;
	x^=x<<1;
	ull t=x;x=y;y=z;
	return z=t^x^y;
}

ull gcd(ull x,ull y) {  
    ull z;  
    if (x<y) swap(x,y);  
    while (y) {  
        z=y;y=x%y;x=z;  
    }  
    return x;  
}  


int main() {
	int cas,cnt=0;
	scanf("%d",&cas);
	while (cas--) {
		int n;
		cnt++;
        ull a,b,c;
		ULL ans=0;
		scanf("%d%u%u%u",&n,&a,&b,&c);
		x=a;y=b;z=c;
		if (n<=N) {
			arr[1]=prand();
			for (int i=2;i<=n;i++) {
				arr[i]=prand();
				for (int j=1;j<i;j++) {
					ans=max(ans,(ULL)arr[i]*(ULL)arr[j]/(ULL)gcd(arr[i],arr[j]));
				}
			}
			printf("Case #%d: %llu\n",cnt,ans);
			continue;
		}
		for (int i=1;i<=N;i++) arr[i]=-1;
		ull last=prand();
		arr[1]=last;
		for (int i=2;i<=n;i++) {
			ull now=prand();
			last=max(now,last);
			for (int j=1;j<=N;j++) {
				if (now>arr[j]) {
					for (int k=N-1;k>=j;k--) arr[k+1]=arr[k];
					arr[j]=now;
					break;
				}
				if (now==arr[j]) break;
			}
		}
		for (int i=2;i<=N;i++) {
			for (int j=1;j<i;j++) {
				ans=max(ans,(ULL)arr[i]/(ULL)gcd(arr[i],arr[j])*(ULL)arr[j]);
			}
		}
		printf("Case #%d: %llu\n",cnt,ans);
	}
	return 0;
}