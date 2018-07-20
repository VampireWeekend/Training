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
ll sum[20],dp[20][10];

int main() {
	dp[1][0]=1;
	for (int i=1;i<=9;i++) dp[1][i]=1;
	sum[1]=10;
    int i,j;
	for (i=2;i<=18;i++) {
	    dp[i][0]=sum[i-1];
	    sum[i]=sum[i-1];
		for (j=1;j<=9;j++) {
			if (j!=1) dp[i][j]=sum[i-1];
			else dp[i][j]=sum[i-1]-dp[i-1][3];
			sum[i]+=dp[i][j];
		}
	}
	for (i=1;i<=18;i++) {
		sum[i]--;
		cout << sum[i] << endl;
	}
	int cas;
	scanf("%d",&cas);
	while (cas--) {
		ll n;
		scanf("%lld",&n);
		int num=1;
		while (sum[num]<n) num++;
		i=num;
		int r=0;
		int digit[20];
		mem0(digit);
		r=sum[i-1];
		while (i) {
		    if (i==num) j=1; else j=0;
			while (dp[i][j]+r<n&&j<=9) {
			    r+=dp[i][j];
				j++;
			}
			digit[i]=j;
			i--;
		}
		for (i=num;i>=1;i--) {
			printf("%d",digit[i]);
		}
		printf("\n");
	}
	return 0;
}
