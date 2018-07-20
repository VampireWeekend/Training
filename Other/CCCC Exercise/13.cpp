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
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
const int inf=0x3f3f3f3f;    
const ld pi=acos(-1.0L);
vector<int> v,a;
map<ull,int> mp;

ull seed1=26,seed2=1e9+7;  

int main() {
	int n,i,j,m,x,y;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		v.clear();
		scanf("%d:",&x);
		for (j=1;j<=x;j++) {
			scanf("%d",&y);
			v.push_back(y);
		}
		sort(v.begin(),v.end());
		ull sum=seed1;  
   		for (j=0;j<v.size();j++) {  
    	    sum*=seed2;  
        	sum+=v[j];
    	}
    	mp[sum]++;
    	a.push_back(sum); 
	}
	v.clear();
	int ans=0;
	for (i=0;i<n;i++) {
		if (mp[a[i]]) v.push_back(mp[a[i]]),ans++;
	}
	printf("%d\n",ans);
	for (i=0;i<v.size();i++) printf("%d ",v[i]);
	return 0;
}
