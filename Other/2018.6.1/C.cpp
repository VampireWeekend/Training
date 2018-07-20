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
#define pb push_back 
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=5000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn],t[maxn];
int dp[maxn],f[maxn],v[maxn];

int find(int now) {  
    if (f[now]==now) return now; else {  
        f[now]=find(f[now]);  
        return f[now];  
    }  
}  

int main() {
	while (scanf("%s",t+1)!=EOF) {
		scanf("%s",s+1);
		int n,m,i,j;mem0(v);
		n=strlen(s+1);m=strlen(t+1);
		for (i=1;i<=n;i++) {
			f[i]=i;
		}
		f[0]=0;dp[0]=0;
		for (i=1;i<=n;i++) {
			int p=find(i-1);
			if (s[i]==t[dp[p]+1]) {
				dp[i]=dp[p]+1;
				if (dp[i]==m) {
					int now=i;
					for (j=1;j<=m;j++) {
						int np=now;
						f[np]=now=find(now-1);
						if (j==m) v[np]=1;
					}
				}
			} else {
				if (s[i]==t[1]) dp[i]=1; else dp[i]=0;
			}
		}
		int cnt=0;
		for (i=1;i<=n;i++) {
			if (v[i]) cnt+=m;
			if (!cnt) printf("%c",s[i]); else cnt--;
		}
		printf("\n");
	}
	return 0;
}
