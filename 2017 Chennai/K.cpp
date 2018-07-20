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
char s[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j,c1,c2,ca,cb;
		scanf("%d",&n);
		c1=c2=ca=cb=0;
		for (i=1;i<=n;i++) {
			scanf("%s",s+1);
			int len=strlen(s+1);
			if (len==1) {
				if (s[1]=='a') ca++; else cb++;
			} else {
				if (s[1]==s[2]) {
					if (s[1]=='a') ca+=2; else cb+=2;
				} else {
					if (s[1]=='a') c1++; else c2++;
				}
			}
		}
		ca=min(ca,1);cb=min(cb,1);
		int u=min(c1,c2);
		if (c1+c2==0) {
			printf("%d\n",ca+cb);
			continue;
		}
		int ans=u*2+1;
		c1-=u;c2-=u;
		if (c1) ans+=2*c1-1; else if (c2) ans+=2*c2-1;
		printf("%d\n",ans); 
	}
	return 0;
}
