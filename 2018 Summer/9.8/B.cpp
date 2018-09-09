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
int tem[maxn];
char s[maxn];

int main() {
	while (scanf("%s",s+1)!=EOF) {
		int len=strlen(s+1),p=-1,top=0,a=0;
		stack<char> st;
		mem0(a);
		for (int i=1;i<=len;i++) {
			if (s[i]>='0'&&s[i]<='9') {
				a=a*10+s[i]-'0';
			} else {
				
			}
		}
	}
	return 0;
}
