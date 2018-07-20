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
const int maxn=1000005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
map<string,int> mp;
bool v[maxn];

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int i,j,n,l,p,k; 
		mp.clear();
		mem0(v);
		scanf("%d",&n);
		string s;
		for (i=1;i<=n;i++) {
			cin >> s;
			mp[s]=i;
		}
		l=0;k=0;int cnt=0;
		for (i=1;i<=n;i++) {
			cin >> s;p=mp[s];
			k=max(k,p);l++;
			if (i==k) {
				if (cnt) printf(" ");
				cnt++;
				printf("%d",l);l=0;
			}
		}
		printf("\n");
	}
	return 0;
}
