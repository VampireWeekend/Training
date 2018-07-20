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
const int maxn=30,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int cnt[maxn];
char s[maxn][maxn];
vector<int> x[maxn],y[maxn];
bool r[maxn],c[maxn];

int main() {
	int n,i,j;
	while (scanf("%d",&n)!=EOF) {
		mem0(cnt);mem0(r);mem0(c);
		for (i=0;i<26;i++) {
			x[i].clear();y[i].clear();
		}
		for (i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			for (j=1;j<=n;j++) {
				cnt[s[i][j]-'A']++;
				x[s[i][j]-'A'].push_back(i);
				y[s[i][j]-'A'].push_back(j);
			}
		}
		int ans=-1,rr,cc;
		for (i=0;i<26;i++) {
			if (cnt[i]==n-1) ans=i;
		}
		for (i=0;i<x[ans].size();i++) {
			r[x[ans][i]]=1;c[y[ans][i]]=1;
		}
		for (i=1;i<=n;i++) if (!r[i]) rr=i;
		for (i=1;i<=n;i++) if (!c[i]) cc=i;
		printf("%d %d %c\n",rr,cc,(char)(ans+'A'));
	}
	return 0;
}
