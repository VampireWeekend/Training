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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
char s[maxn],t[maxn];

int main() {
	scanf("%s%s",s,t);
	int a,b;
	a=b=0;
	for (int i=0;i<=5;i++) {
		if (s[i]<t[i]) a++; else if (s[i]>t[i]) b++;
	}
	cout << a << endl;
    cout << b << endl;
	return 0;
}
