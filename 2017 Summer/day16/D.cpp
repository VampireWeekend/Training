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
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
int a[maxn],visit[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		mem0(visit);
		int i,j,cnt=0,n;
		scanf("%d",&n);
		for (i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		for (i=1;i<=n;i++) {
			if (!visit[i]) {
				cnt++;
				j=i;
				visit[i]=1;
				while (!visit[a[j]]) {
					j=a[j];
					visit[j]=1;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

