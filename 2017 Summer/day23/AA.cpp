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
const int maxn=105555,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

int main() {
//  freopen("A.in","r",stdin);  
//  freopen("output.txt","w",stdout);  
	int n,k,m,i;
	scanf("%d%d%d",&n,&k,&m);
	while (n!=0||k!=0||m!=0) {
		int ans=0;
		for (i=2;i<=n;i++) {
			ans=(ans+k)%i;
		}
		k%=n;
		if (k==0) k=n;
		ans=ans+m-k;
		while (ans<0) ans+=n;
		while (ans>=n) ans-=n;
		printf("%d\n",ans+1);
		scanf("%d%d%d",&n,&k,&m);
	}
	return 0;
}

