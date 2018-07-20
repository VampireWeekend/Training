#include<bits/stdc++.h>
using namespace std;
const int maxn = 2048;
const int inf = 1e9+9;
struct node{
    int len, last;
    node(int l = 0, int v = 0) : len(l), last(v) {}
}dp[maxn][maxn][2], tem;

bool check(node tx, node ty, bool right){
    if(tx.len == ty.len){
        return !right ? tx.last > ty.last : tx.last < ty.last;
    }
    return tx.len < ty.len;
}

int n, m;
int a[maxn], b[maxn];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d", &b[i]);
    }

    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= m; j ++){
            dp[i][j][0] = node(0, -inf);
            dp[i][j][1] = node(0, inf);
        }
    }

    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= m; j ++){
            for(int k = 0; k < 2; k ++){
                
                if(check(dp[i+1][j+1][k], dp[i][j][k], k))
                    dp[i+1][j+1][k] = dp[i][j][k];
                
                if(check(dp[i][j+1][k], dp[i][j][k], k))
                    dp[i][j+1][k] = dp[i][j][k];

                if(check(dp[i+1][j][k], dp[i][j][k], k))
                    dp[i+1][j][k] = dp[i][j][k];
                
                if(a[i+1] == b[j+1]){
                    if(k && dp[i][j][k].last > a[i+1]){
                        tem = node(dp[i][j][k].len+1, a[i+1]);
                        if(check(dp[i+1][j+1][!k], tem, !k))
                            dp[i+1][j+1][!k] = tem;
                    }
                    else if(!k && dp[i][j][k].last < a[i+1]){
                        tem = node(dp[i][j][k].len+1, a[i+1]);
                        if(check(dp[i+1][j+1][!k], tem, !k))
                            dp[i+1][j+1][!k] = tem;
                    }
                }
            }
        }
    }

    printf("%d", max(dp[n][m][0].len,dp[n][m][1].len));
    return 0;
}
