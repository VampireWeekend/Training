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
const int maxn=165,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	int cas;
	scanf("%d",&cas);getchar();
	while (cas--) {
		db x=0;ll a=0;char ch;
		scanf("%c",&ch);
		while (ch>='0'&&ch<='9') {
			a=a*10+ch-'0';
			scanf("%c",&ch);
		}
		if (a!=0) printf("%lld",a);
		if (ch!='.') {
			printf("\"\n");continue;
		}
		if (a!=0) printf(" ");
		a=0;ll t=1;
		scanf("%c",&ch);
		while (ch>='0'&&ch<='9') {
			t*=10;
			a=a*10+ch-'0';
			scanf("%c",&ch);
		}
		if (a==0) {
			printf("\"\n");continue;
		}
		int flag=0;
		ll i,j;
		for (i=4;i<=128;i*=2) {
			for (j=1;j<i;j++) {
				if ((a*i>=t*j&&(a-1)*i<t*j)||(a*i<=t*j&&(a+1)*i>t*j)) {
					flag=1;break;
				}
			}
			if (flag) break;
		}
		printf("%lld/%lld\"\n",j,i);
	}
	return 0;
}
