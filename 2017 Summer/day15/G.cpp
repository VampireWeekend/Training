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
const int maxn=100005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
string s;
char ch[maxn];

int main() {
	int cas,c;
	cin >> cas;
	while (cas--) {
		scanf("%d",&c);
		getchar();
		int i,n,k;
		s="";
		while (s.length()==0) getline(cin,s);
		int len=s.length();
		scanf("%d",&n);
		int sum=0;
		string a="";
		for (i=1;i<=n;i++) {
			scanf("%d",&k);
			sum+=k;
			while (sum<0) sum+=len;
			while (sum>=len) sum-=len;
			a=a+s[sum];
		}
		cout << c << ' ' << a << endl;
	}
	return 0;
}

