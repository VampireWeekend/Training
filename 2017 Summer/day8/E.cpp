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
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=105,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
int a[208];
char s[208];

int main() {
	int n,i,j;
	map<char,int> my;
	cin >> s;
	char c;
	int len=strlen(s);
	for (i=0;i<len;i++) {
		my[s[i]]++;
	}
	int m1,m2;
	m1=m2=0;
	for (c='a';c<='z';c=(char)(c+1)) {
		if (my[c]>=m1) {
			m2=m1;
			m1=my[c];
		} else if (my[c]>=m2) {
			m2=my[c];
		}
	}
	int ans=len-m1-m2;
	cout << ans;
	return 0;
}
