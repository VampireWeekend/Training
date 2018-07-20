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
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);

int main() {
	int n,i,j;
	cin >> n;
	printf("*");
	for (j=1;j<=n-2;j++) 
		printf(" ");
	printf("*");
	printf(" ");
	for (j=1;j<=n;j++) 
		printf("*");
	printf("\n");
	for (i=1;i<=n-2;i++) {
		printf("*");
		for (j=1;j<=n-2;j++) 
			printf(" ");
		printf("*");
		printf(" ");
		printf("*");
		for (j=1;j<=n-2;j++) 
			printf(" ");
		printf("*");
		printf("\n");
	}
	for (j=1;j<=n;j++) 
		printf("*");
	printf(" ");
	printf("*");
	for (j=1;j<=n-2;j++) 
		printf(" ");
	printf("*");
	return 0;
}
