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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn],last[25];

int main() {
//	freopen("wifi.in","r",stdin);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,k;
		scanf("%d%d",&n,&k);
		int u=k,p=0,div;
		while (u) {
			u/=2;
			p++;
		}
		div=p-1;
		for (i=0;i<=25;i++) last[i]=0;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		int now=0,j=1,ans=0;
		for (i=1;i<=n;i++) {
			if (a[i]>k) {
				now=0;j=i+1;
				continue;
			}
			now=now|a[i];
			u=a[i],p=0;
			while (u) {
				if (u%2) last[p]=i;
				u/=2;
				p++;
			}
			if (now>k) 
		/*	if (last[div]!=i) {
				j=last[div]+1;
				now=0;
				for (int q=0;q<div;q++) {
					if (last[q]>=j) now=now|(1<<q);
				}
			} else */{
				int x=now,w=a[i],dig=inf;
				for (int q=0;q<=div;q++) {
					if (x%2==1&&w%2==0&&(now-(1<<q))<=k) {
						dig=min(dig,last[q]+1);
					}
					x/=2;w/=2;
				}
				if (dig==inf) dig=i;
				j=dig;
				now=0;
				for (int q=0;q<=div;q++) {
					if (last[q]>=j) now=now|(1<<q);
				}
			}
			ans=max(ans,i-j+1);
		}
		printf("%d\n",ans);
	}
//	fclose(stdin);
	return 0;
}
