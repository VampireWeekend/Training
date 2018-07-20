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
const int maxn=10005,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  

int main() {
	int n,i,j,p;
	scanf("%d",&n);
	if (n%2==0) printf("No"); else {
		printf("Yes\n");
		p=(n-1)/2;
		int cnt=n-1;
		for (i=1;i<n;i++) {
			for (j=1;j<=min(p,cnt);j++) {
				printf("1 ");
			}
			for (j=min(p,cnt)+1;j<=cnt;j++) {
				printf("0 ");
			}
			printf("\n");
			cnt--;
		}
	}
	return 0;
}

