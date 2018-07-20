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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
string s;

int main() {
	int n,i,len,j;
	scanf("%d",&n);
	getchar();
	getline(cin,s);
	len=s.length();
	for (i=1;i<=len+n+len+n;i++) s=s+' ';
	int cnt=len/n+(len%n!=0);
	for (i=1;i<=n;i++) {
		for (j=1;j<=cnt;j++) {
			printf("%c",(char)s[(cnt-j)*n+i-1]);
		}
		cout << '\n';
	}
	return 0;
}
