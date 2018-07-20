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
const int maxn=1005,inf=0x3f3f3f3f;    
const ld pi=acos(-1.0L);
char s[maxn],a[maxn];
map<ull,int> mp,mp2;
vector<ull> v[25];

ull seed1=26,seed2=1e9+7;  

int main() {
	scanf("%s",s+1);
	int n,i,j,len,q,k;
	len=strlen(s+1);
	scanf("%d",&q);
	for (i=1;i<=len;i++) {
		ull sum=seed1;  
   		for (j=i;j<=len;j++) {  
    	    sum*=seed2;  
        	sum+=s[j];
			mp[sum]++;  
    	}
	}
	v[0].push_back(seed1);
	for (i=1;i<=q;i++) {
		scanf("%s",a+1);
		n=strlen(a+1);
		int cnt=0;
		for (j=1;j<=n;j++) {
			cnt++;v[cnt].clear();
			for (k=0;k<v[cnt-1].size();k++) v[cnt].push_back(v[cnt-1][k]*seed2+a[j]);
			if (a[j+1]=='?') {
				for (k=0;k<v[cnt-1].size();k++) v[cnt].push_back(v[cnt-1][k]);
				j++;
			}
		}
		int ans=0;
		for (k=0;k<v[cnt].size();k++) {
			if (mp2[v[cnt][k]]!=i) mp2[v[cnt][k]]=i,ans+=mp[v[cnt][k]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
