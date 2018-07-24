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
typedef pair<int,int> pp;
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn];

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int h,m,x,y;
		scanf("%d%d",&h,&m);
		scanf("%s",s);
		int len=strlen(s);
		x=y=0;
		int flag=0;
		for (int i=4;i<len;i++) {
			if (s[i]=='.') {
				flag=1;continue;
			}
			if (!flag) x=(x*10)+s[i]-'0'; else y=(y*10)+s[i]-'0';
		}
		if (s[3]=='-') x+=8; else if (s[3]=='+') {
			if (x>=8) x-=8; else {
				if (y==0) {
					x-=8;
					s[3]='-';
					x=abs(x);
				} else {
					y=10-y;
					x-=7;
					s[3]='-';
					x=abs(x);
				}
			}
		}
		if (s[3]=='+') {
			h+=x;m+=y*6;
			if (m>=60) {
				h+=m/60;m%=60;
			}
			h%=24;
		} else {
			h-=x;m-=y*6;
			while (m<0) {
				m+=60;
				h--;
			}
			while (h<0) h+=24;
		}
		if (h==0) printf("00"); else if (h<10) printf("0%d",h); else printf("%d",h);
		printf(":");
		if (m==0) printf("00"); else if (m<10) printf("0%d",m); else printf("%d",m);
		printf("\n");
	}
	return 0;
}
