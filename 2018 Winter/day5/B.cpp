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
const int maxn=100005,inf=0x3f3f3f3f;  
const ld pi=acos(-1.0L);
map<ull,int> mp;
ull seed1=26,seed2=1e9+7;  
char s[maxn];
int a[maxn];
  
ull hash() {  
    ull sum=seed1;  
    for (int i=1;i<10;i++) {  
        sum*=seed2;  
        if (a[i]) sum+=i;  
    }
    return sum;  
}  

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		int i,j;
		for (i=1;i<=n;i++) {
			scanf("%s",s);
			int len=strlen(s);
			for (j=1;j<=9;j++) a[j]=0;
			for (j=0;j<len;j++) {
				a[s[j]-'0']=1;
			}
			mp[hash()]=1;
		}
		int ans=mp.size();
		printf("%d\n",ans);
		mp.clear();
	} 
	return 0;
}
