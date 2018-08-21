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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1000000007;
const ld pi=acos(-1.0L);
int a[maxn][26],last[26];
char s[maxn];

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
    int n;
		mem0(last);mem0(a);
		scanf("%d",&n);
		int cnt=0;
		for (int i=1;i<=n;i++) {
			scanf("%s",s+1);
			int now=1,j;
			int len=strlen(s+1);
			for (j=1;j<=len;j++) {
				if (now>cnt) break;
				if (a[now][s[j]-'a']==0) break;
				now=a[now][s[j]-'a'];
				now++;
			}
			for (;j<=len;j++) {
				cnt++;
				for (int k=last[s[j]-'a']+1;k<=cnt;k++){
					a[k][s[j]-'a']=cnt;
				}
				printf("%c",s[j]);
				last[s[j]-'a']=cnt;
			}
		}
		printf("\n");
	}
	return 0;
}
