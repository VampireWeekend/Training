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
#include <bitset>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=3.1415926535898L;
int a[maxn];

int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		int i;
		ll n,s,j,q,p;
		cin >> n >> s;
		if (s==0&&n==1) {
		    printf("0 0\n");
		}
		else if (s>n*9||s==0) printf("-1 -1\n"); else
		{
			mem0(a);
			if (s<=9*(n-1)) a[1]=1; else a[1]=s-s/9*9;
			int sum=s,k=n+1;
			sum-=a[1];
			for (i=n;sum>=9&&i>1;i--) 
				a[i]=9,sum-=9,k=i;
			if (sum>0) a[k-1]=sum;
			for (i=2;i<k-1;i++) a[i]=0;
			for (i=1;i<=n;i++) cout << a[i];
			cout << ' ';
			mem0(a);
			for (i=1;i<=s/9;i++) a[i]=9;
			a[s/9+1]=s-(s/9)*9;
			for (i=s/9+2;i<=n;i++) a[i]=0;
			for (i=1;i<=n;i++) cout << a[i];
			cout << '\n';
	    }
	}
	return 0;
}

