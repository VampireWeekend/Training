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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=2005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

bool check(int i) {
	return (i%4==0&&i%100!=0)||(i%400==0);
}

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int i,x,y,d,sum=0;
		scanf("%d-%d-%d",&x,&y,&d);
		if (check(x)&&y==2&&d==29) {
			for (i=x+4;;i+=4) {
				sum+=4*365;
				if (check(i)) {
					sum++;
					sum%=7;
				} else continue;
				if (sum==0) break;
			}
		} else
		for (i=x+1;;i++) {
			if (check(i)) {
				if (y>2) sum+=366; else sum+=365;
			} else if (check(i-1)) {
				if (y<=2) sum+=366; else sum+=365;
			} else sum+=365;
			sum%=7;
			if (sum==0) break;
		}
		printf("%d\n",i);
	}
	return 0;
}

