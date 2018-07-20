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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
int a,b,c;
	cin >> a >> b >> c;
	if (a+b+c==1) {
		if (a==1) printf("A"); else 
		    if (b==1) printf("B"); else printf("C");
	} else if (a+b+c==2) {
		if (a==0) printf("A"); else 
		    if (b==0) printf("B"); else printf("C");
	} else printf("*");
	return 0;
}

