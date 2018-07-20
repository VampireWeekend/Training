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
const ll inf=2e18; 
const ld pi=acos(-1.0L);
ll a[6];
vector<ll> ans[35];

int main() {
	ll n;
	int i,j,k;
	a[1]=4;a[2]=27;a[3]=3125;a[4]=823543;a[5]=a[6]=1;
	for (i=1;i<=11;i++) a[5]*=11;
	for (i=1;i<=13;i++) a[6]*=13;
	for (i=1;i<=6;i++) {
		ans[1].push_back(a[i]);
	}
	for (i=2;i<=30;i++) {
		int size=ans[i-1].size();
		map<ll,int> mp;
		for (j=0;j<size;j++) {
			for (k=1;k<=6;k++) {
				if (inf/ans[i-1][j]>=a[k]) {
					if (mp[a[k]*ans[i-1][j]]==0) {
						ans[i].push_back(a[k]*ans[i-1][j]);
						mp[a[k]*ans[i-1][j]]++;
					} 
				}
			}
		}
		sort(ans[i].begin(),ans[i].end());
	}
	ll m,r;
	cin >> m >> r;
	int sum=0;
	for (i=0;i<ans[m].size();i++) {
		if (ans[m][i]<=r) sum++; else break; 
	}
	printf("%d\n",sum);
	for (i=0;i<sum;i++) {
		printf("%lld",ans[m][i]);
		if (i!=sum-1) printf(" ");
	}
	return 0;
}

