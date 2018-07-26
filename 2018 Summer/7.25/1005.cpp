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
#define pb push_back 
#define N 45
#define len 2000
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pp;
const int maxn=2005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f;
const ld pi=acos(-1.0L);
int a[maxn][maxn];

int main() {
	int s=len/N;
	for (int i=1;i<=s;i++) {
		for (int j=1;j<=s;j++) {
			int st=i-j+2000*N;
			st%=N;
		//	int st=min(i,j)-1;
			for (int k=1;k<=N;k++) {
				a[(i-1)*N+(k-1+st)%N+1][(j-1)*N+k]=1;
			}
		}
	}
	printf("2000\n");
	for (int i=1;i<=2000;i++) {
		for (int j=1;j<=2000;j++) {
			if (j!=2000) printf("%d",a[i][j]); else printf("%d\n",a[i][j]);
		}
	}
	return 0;
}
