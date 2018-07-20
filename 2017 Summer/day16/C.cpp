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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ll ans;
	int len,i,j;
	ll k,m,n;
	scanf("%s",s);
	scanf("%lld",&k);
	len=strlen(s);
	m=s[0]-'0';
	for (i=2;i<len;i+=2) {
		if (s[i-1]=='+') m+=(s[i]-'0'); else m*=(s[i]-'0'); 
	}
	ll p;
	n=0;
	p=s[0]-'0';
	i=0;
	while (i+2<len) {
		i+=2;
		if (s[i-1]=='*') {
			p*=(s[i]-'0');
		} else {
			n+=p;
			p=s[i]-'0';
		}
	}
	n+=p;
	if (n==k&&m==k) cout << 'U'; else 
	if (n==k) cout << 'M'; else if (m==k) cout << 'L'; else cout << 'I';
	return 0;
}

