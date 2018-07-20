#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL mod = 1e9+7;
const int MAXN = 101010;
int T;
LL dp[MAXN], sum[MAXN], ans, pre[MAXN];

LL cal(int x){
    if(!x)
        return 1;
    return pre[x - 1];
}
char ch[MAXN];
int main(){
    pre[0] = 1;
    for(int i = 1; i < MAXN; i ++)
        pre[i] = (pre[i-1] * 2) % mod;
    scanf("%d", &T);
    while(T--){
        ans = 0;
        scanf("%s", ch + 1);
        long int len = strlen(ch+1);
        for(int i = 1; i < len; i ++){
            dp[i] = dp[i-1] * 10 + (i - 1 + cal(i-1)) * (ch[i] - '0') ;
            dp[i] %= mod;
            ans += dp[i] * pre[len-i-1];
            ans %= mod;
        }
        ans = ans + dp[len-1]*10 + cal(len) * (ch[len] - '0');
        ans %= mod;
        printf("%lld\n", ans);
    }
}
