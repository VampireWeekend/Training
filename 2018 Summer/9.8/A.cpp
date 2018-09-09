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
#define N 100000
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[20]={1,2, 3, 5, 7, 11, 13, 17, 23, 31, 37, 53, 71, 73, 113, 131, 137, 173, 311, 317};
char s[maxn];

int main() {
    int cas;
    scanf("%d",&cas);
    int cnt=0;
while (cas--) {
	scanf("%s",s+1);
    cnt++;
	int len=strlen(s+1);
	if (len>=4) {
		printf("Case #%d: 317\n",cnt);
	} else {
		int num=0;
		for (int i=1;i<=len;i++) {
			num=num*10+(s[i]-'0');
		}
		int ans=1;
		for (int i=0;i<=19;i++) {
			if (a[i]<=num) ans=max(ans,a[i]);
		}
		printf("Case #%d: %d\n",cnt,ans);
	}
}
	return 0;
}