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
const int maxn=1000005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	int len,i,l,r,j,ans,cnt,sum;
	scanf("%s",s+1);
	ans=sum=cnt=0;
	len=strlen(s+1);
	r=1;
	for (i=1;i<=len;i++) {
		l=i;
		if (s[i-1]=='K'&&i!=1) cnt++;
		if (s[i-1]=='H'&&i!=1) cnt--;
		if (s[i-1]=='M'&&i!=1) sum--;
		while (r<=len&&cnt>=0) {
			if (s[r]=='M') sum++; else 
			    if (s[r]=='H') cnt++; else cnt--;
			r++; 
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}

