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
const int maxn=100005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L); 
int qx[maxn],qy[maxn],a[maxn],step[maxn];
bool hash[705];

int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	int n,i,h,t,final;
	scanf("%d",&n);
	map<int,int> mp;
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		mp[a[i]]=i;
	}
	scanf("%d",&final);
	mem0(hash);
	h=0;t=1;qx[1]=qy[1]=step[1]=0;
	hash[0]=1;
	while (h<t) {
		h++;
		int nowx=mp[qx[h]],nowy=mp[qy[h]];
		for (i=nowx+1;i<=n;i++) {
			if (!hash[i+qy[h]])
		}
		
		
	}
	printf("IMPOSSIBLE\n");
	return 0;
}

