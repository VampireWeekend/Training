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
typedef unsigned long long ull;
typedef long double ld;
const int maxn=100005,inf=0x3f3f3f3f;   
const ld pi=acos(-1.0L); 
int a[50];
int n;

ull seed1=26,seed2=1e9+7;  
  
ull hashaa() {  
    ull sum=seed1;  
    for (int i=0;i<n;i++) {  
        sum*=seed2;  
        sum+=a[i];  
    }  
    return sum;  
}  

int main() {
	int cas;
	scanf("%d",&cas);
while (cas--) {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	map<ull,int> mp;
	mp.clear();
	int cnt=0,flag=0;
	while (cnt<=1000) {
		cnt++;
		int sum=0,p=a[0];
		for (int i=0;i<n-1;i++) {
			a[i]=abs(a[i+1]-a[i]);
			sum+=a[i];
		}
		a[n-1]=abs(a[n-1]-p);
		sum+=a[n-1];
		ull f=hashaa();
		if (mp[f]) {
			printf("LOOP\n");
			flag=1;
			break;
		}
		if (sum==0) {
			printf("ZERO\n");flag=1;
			break;
		}
		mp[f]++;
	}
	if (!flag) 
		printf("LOOP\n");
}
	return 0;
}

