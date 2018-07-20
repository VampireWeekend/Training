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
const int maxn=305,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[maxn];

struct Num{
	int odd,index,id;
};
Num b[maxn];

bool cmp(Num x,Num y) {
	return x.index<y.index || (x.index==y.index&&x.odd<y.odd);
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,i,cas,j;
	scanf("%d",&cas);
	while (cas--) {
		n=0;
		scanf("%d",&a[++n]);
		while (a[n]!=0) scanf("%d",&a[++n]);
		n--;
		for (i=1;i<=n;i++) {
			b[i].index=0;
			b[i].id=i;
			int k=a[i];
			while (k%2==0) {
				b[i].index++;
				k/=2;
			}
			if (k==1) {
				b[i].index=129-b[i].index;
			} else b[i].odd=k;
		}
		sort(b+1,b+n+1,cmp);
		for (i=1;i<n;i++) {
			printf("%d ",a[b[i].id]); 
	//		cout << b[i].id << ' ' << b[i].index << ' ' << b[i].odd << endl;
		}
//		cout << b[n].id << ' ' << b[n].index << ' ' << b[n].odd << endl;
		printf("%d\n",a[b[n].id]);
	}
	return 0;
}

