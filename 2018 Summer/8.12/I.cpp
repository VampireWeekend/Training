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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char t[maxn];

int main() {
	scanf("%s",t+1);
	int len=strlen(t+1);
	int n,s,e,w;
	n=s=w=e=0;
	for (int i=1;i<=len;i++) {
		if (t[i]=='N') n=1;
		if (t[i]=='S') s=1;
		if (t[i]=='W') w=1;
		if (t[i]=='E') e=1;
	}
	if (n+s+w+e==1) printf("X\n"); else if (n+s+w+e==2) {
		if ((n==1&&s==1)||(w==1&&e==1)) printf("X\n"); else {
			if (n==0) printf("N");
			if (s==0) printf("S");
			if (w==0) printf("W");
			if (e==0) printf("E");
		}
	} else {
		if (n==0) printf("N");
		if (s==0) printf("S");
		if (w==0) printf("W");
		if (e==0) printf("E");
	}
	return 0;
}
