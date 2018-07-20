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
#include <stack>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];  

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	int n,i,ans=0,sum=0;
	scanf("%d",&n);
	map<int,int> mp;
	for (i=1;i<n;i++) {
		scanf("%d",&a[i]);
		sum+=a[i];
		mp[sum]=1;
	}
	scanf("%d",&a[n]);
	sum+=a[n];
	mp[0]=1;
	if (sum%3!=0) {
		printf("0");
		return 0;
	}
	int p=sum/3;
	int now=0;
	for (i=1;i<=n;i++) {
		int d,b,c;
		now+=a[i];
		if (i==n) now=0;
		if (mp[now]==0) continue;
		d=now;b=(now+p)%sum;c=(now+2*p)%sum;
		if (mp[d]&&mp[b]&&mp[c]) {
			ans++;
			mp[d]=mp[b]=mp[c]=0;
		}
	}
	printf("%d",ans);
	return 0;
}

