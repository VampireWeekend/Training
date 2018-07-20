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
const int maxn=505,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[maxn];

int main() {
//	freopen("overcode.in","r",stdin);
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		int n,i,j,ans=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int cnt=1;j=1;
		for (i=2;i<=n;i++) {
			if (abs(a[i]-a[j])>1000) {
				ans+=cnt/6;
				while (abs(a[i]-a[j])>1000) j++;
				cnt=i-j+1;
			} else {
				cnt++;
				if (cnt==6) ans++,cnt=0,j=i+1; 
			}
		}
		printf("%d\n",ans);
	}
//	fclose(stdin);
	return 0;
}
