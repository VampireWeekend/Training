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
typedef unsigned long long ll;
typedef long double ld;
const int maxn=1005,inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3f; 
const ld pi=acos(-1.0L);
char s[maxn];
ll dp[maxn];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,i,j,t,cas;
	ll ans;
	scanf("%d",&cas);
	for (t=1;t<=cas;t++) {
		scanf("%s",s+1);
		mem0(dp);
		dp[0]=1;
		if (s[1]!='0') dp[1]=1;
		int len=strlen(s+1),flag=1;
		if (s[1]=='0'&&len==1) {
			printf("Case #%d: 0\n",t);
			continue;
		}
		for (i=2;i<=len;i++) {
			if (s[i]!='0') dp[i]+=dp[i-1];
			int num=(s[i-1]-'0')*10+(s[i]-'0');
			if (num<=26&&num>=10) {
				if (i==2) dp[i]++; else dp[i]+=dp[i-2];
			} else {
				if (num%10==0) {
					printf("Case #%d: 0\n",t);
					flag=0;
					break;
				}
			}
		}
		if (flag) {
			printf("Case #%d: ",t);
		    cout << dp[len] << endl;
		}
	}
	return 0;
}

