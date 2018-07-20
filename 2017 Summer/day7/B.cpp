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
#include <iomanip>
#include <cmath>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=2005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 

int main() {
	int n,t,i,j;
/*	map<string,int> my;
	my["0000"]=0;my["0001"]=1;my["0002"]=2;my["0003"]=3;*/
	cout << setiosflags(ios::fixed) << setprecision(4);
	int ly,lm,ry,rm;
	scanf("%d",&n);
	for (t=1;t<=n;t++) {
		scanf("%d%d%d%d",&lm,&ly,&rm,&ry);
		ld ans=0L;
		if (ly==ry) {
			ans=0.5L/(ld)(12-lm+1)*(ld)(rm-lm);
		}
		else {
			ans=-0.5L+(ld)(ry-ly);
			ans+=(ld)(rm-1)/(ld)12.0L;
		}
		cout << ans << endl; 
	}
	return 0;
}
