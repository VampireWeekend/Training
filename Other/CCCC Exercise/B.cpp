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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
string s;

int main() {
	int a,b;
	cin >> s;
	a=(s[0]-'0')*10+s[1]-'0';
	b=(s[3]-'0')*10+s[4]-'0';
	if (a<11||(a==12&&b==0)) {
		cout << "Only ";cout << s;
		cout << ".  Too early to Dang.";
	} else if (b==0) {
		a-=12;
		for (int i=1;i<=a;i++) cout << "Dang";
	} else {
		a-=11;
		for (int i=1;i<=a;i++) cout << "Dang";
	}
	return 0;
}
