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
int sz[maxn];
string s;
vector<int> v[505];

int main() {
	getline(cin,s);
	int n=s.length(),cas=0,l;
	ll ans=0;
	for (int i=0;i<n;i++) {
		v[s[i]].pb(i);
	}
	for (int i=0;i<250;i++) {
		sz[i]=v[i].size();
	}
	l=n;
	int now=0;
	while (getline(cin,s)) {
		cas++;
		if (cas==1) n=s.length();
		int sum=1,pos=0;
		for (int i=0;i<n;i++) {
			if (s[i]==' ') continue;
			pos=lower_bound(v[s[i]].begin(),v[s[i]].end(),(now+i)%l)-v[s[i]].begin();
			if (pos==sz[s[i]]) pos=0;
			pos=v[s[i]][pos];
			if (pos - (now + i) % l < 0) pos += l;
			sum=max(pos- (now + i) % l+1,sum);
		}
 //       cout << sum << endl;
		ans+=(ll)sum;
		now=(sum+now)%l;
//        cout << now << endl;
	}
//	system("pause");
	printf("%lld\n",ans);
	return 0;
}
