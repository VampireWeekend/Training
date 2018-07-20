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
typedef unsigned long long ll;  
typedef long double ld;  
const int maxn=85,inf=0x3f3f3f3f;    
const ll llinf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;     
const ld pi=acos(-1.0L);    
ll dp[maxn][11];  
int num[maxn];  
char s[maxn];  
  
ll dfs(int len,int last,bool HaveLimit) {  
    if (len==0)   
        return 1;  
    if (dp[len][last]!=-1&&!HaveLimit)   
        return dp[len][last];  
    
    int p=HaveLimit?num[len]:9,i;  
    ll ans=0;
    for (i=last;i<=p;i++) {  
        ans+=dfs(len-1,i,HaveLimit&&i==num[len]);  
//        ans%=mod;  
    }  
    if (!HaveLimit) dp[len][last]=ans;  
    return ans;  
}  
  
int main() {  
    int cas;  
    scanf("%d",&cas);  
    memset(dp,-1,sizeof(dp));  
    while (cas--) {  
        scanf("%s",s);  
        int len=strlen(s),i,j,flag=0;  
        for (i=0;i<len;i++) {  
            num[len-i]=s[i]-'0'; 
			if (i>0) 
				if (s[i]<s[i-1]) {
					flag=1;break;
				} 
        }  
        if (flag) {
        	printf("-1\n");continue;
        }
        ll ans=0;  
        for (j=1;j<=num[len];j++) {  
            ans+=dfs(len-1,j,j==num[len]);  
    //        ans%=mod;  
        }  
        for (i=len-1;i>0;i--) {  
            for (j=1;j<=9;j++) {  
                ans+=dfs(i-1,j,0);  
    //            ans%=mod;  
            }  
        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
}  
