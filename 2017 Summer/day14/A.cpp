#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int i,len,ans;
	scanf("%s",s+1);
	len=strlen(s+1);
	ans=0;
	for (i=1;i<=len;i++) {
		if (i%3==1) {
			if (s[i]!='P'&&s[i]!='p') ans++;
		} else if (i%3==2) {
			if (s[i]!='E'&&s[i]!='e') ans++;
		} else {
			if (s[i]!='R'&&s[i]!='r') ans++;
		}
	}
	cout << ans;
	return 0;
}

