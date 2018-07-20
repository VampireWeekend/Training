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
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=405,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
ld a[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int i,j,k,n;
	ld d;
	ld minc,cost,mind;
	int l,r;
	cout << setiosflags(ios::fixed) << setprecision(7);
	scanf("%d",&n);
	for (i=1;i<=n;i++) cin >> a[i];
	minc=1e7L;
	for (i=1;i<=n;i++) {
		for (j=i+1;j<=n;j++) {
			d=(a[j]-a[i])/(ld)(j-i);
			cost=0;
			for (k=1;k<=n;k++) {
				cost+=abs(((ld)(k-i))*d+a[i]-a[k]);
			}
			if (cost<minc) {
				minc=cost;l=i;r=j;mind=d;
			}
//			cout << minc << endl;
		}
	}
	cout << minc << endl;
	for (i=1;i<=n;i++) {
		ld pos=(i-l)*mind+a[l];
		cout << pos << ' ';
	}
	return 0;
}
