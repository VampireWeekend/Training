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
const int maxn=105,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);  
int last[maxn];

int main() {
	int n,i,t;
	scanf("%d",&n);
	printf("1 1 0\n");
	for (i=1;i<n;i++) {
		printf("%d %d %d\n",i+1,i+1,i);
		last[i]=i+1;
	}
	printf("1 1 %d\n",n);last[n]=1;
	int now=1;
	for (t=1;t<n*(n-2);t++) {
		last[now]=(last[now]+1)%(n+1);
		if (last[now]==0) last[now]++;
		printf("%d %d %d\n",last[now],last[now],now);
		now=last[now];
	}
	printf("0 1 %d\n",now);
	return 0;
}

