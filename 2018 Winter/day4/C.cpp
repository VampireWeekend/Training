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
const int maxn=55,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int c[maxn];
char s[maxn];
bool a[maxn];

int main() {
//	freopen("scoreboard.in","r",stdin);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,ans;
		for (i=0;i<13;i++) a[i]=true;
		scanf("%d",&n);
		scanf("%s",s);
		for (i=0;i<n;i++) {
			a[s[i]-'A']=false;
		} 
		ans=-1;
		for (i=0;i<13;i++) {
			scanf("%d",&c[i]);
			if (a[i]) 
				if (ans==-1) ans=i; else 
					if (c[ans]<c[i]) ans=i;
		}
		printf("%c\n",(char)('A'+ans));
	}
//	fclose(stdin);
	return 0;
}
