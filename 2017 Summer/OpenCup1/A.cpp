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
	int n,len,i,ans,l,r;
	scanf("%s",s+1);
	len=strlen(s+1);
	ans=1;
	l=1;r=len;
	while (s[l]=='L'&&l<=len) l++;
	while (s[r]=='R'&&r>=1) r--;
	if (l>r) {
		printf("%d",len);
		return 0;
	}
	printf("%d",(l-1)+(len-r)+1);
	return 0;
}

