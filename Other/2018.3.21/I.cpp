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
int a[maxn];
vector<int> v,b;

int main() {
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j,cnt,cnto;
		v.clear();b.clear();
		scanf("%d",&n);
		cnt=cnto=0;
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if (i%2) {
				if (a[i]%2==1) {
					v.push_back(a[i]),cnt++;
					if (a[i]==1) cnto++;
				} else if (a[i]>2) b.push_back(a[i]);
			} else {
				if (a[i]%2==0) {
					v.push_back(a[i]),cnt++;
					if (a[i]==1) cnto++;
				} else if (a[i]>2) b.push_back(a[i]);
			}
		}
		if (cnt%2) {
			printf("-1\n");
			continue;
		}
		int ans=0;
		if (cnto*2<=cnt) printf("%d\n",cnt/2); else {
			sort(v.begin(),v.end());
			int r=v.size()-1;
			for (i=0;i<cnto&&cnto<=r;) {
	//			cout << v[r] << endl;
				v[r]--;r--;i++;ans++;
			}
			r=v.size()-1;
			while (i<cnto&&cnto<=r) {
	//			cout << v[r] << endl;
				while (v[r]>2&&i+2<=cnto) {
					v[r]-=2;
					i+=2;
					ans+=2;
				}
				r--;
			}
			r=0;
			while (i<cnto&&r<b.size()) {
				while (b[r]>2&&i+2<=cnto) {
					b[r]-=2;
					i+=2;
	//				cout << b[r] << endl;
					ans+=2;
				}
				r++;
			}
			if (i<cnto) printf("-1\n"); else printf("%d\n",ans);
		}
	}
	return 0;
}
