#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <string> 
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define mem(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005;
char a[maxn];

int main() {
	int b,c,i;
	b=c=0;
	scanf("%s",a);
	int len=strlen(a);
	for (i=0;i<len;i++) {
		if (a[i]=='1') b++; else c++;
	}
	int ans=min(b,c);
	cout << ans;
	return 0;
}
