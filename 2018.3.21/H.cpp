#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[1100], dp[1100][3], n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &arr[i]);
        dp[i][0] = dp[i][1] = dp[i][2] = 1;    
    }
    
    for(int i = 2; i <= n; i ++){
        for(int j = i-1; j; j --){
            if(arr[i] > arr[j]){
               dp[i][1] = max(dp[i][1], max(dp[j][2]+1, dp[j][0]+1));
            }
            if(arr[i] < arr[j]){
                dp[i][0] = max(dp[i][0], max(dp[j][2]+1, dp[j][1]+1));
             }
            if(arr[i] == arr[j]){
                int tem = max(dp[j][0] + 1, dp[j][1] + 1);
                tem = max(tem, dp[j][2]+1);
                dp[i][2] = max(dp[i][2], tem);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        ans = max(ans, max(dp[i][0], dp[i][1]));
        ans = max(ans, dp[i][2]);
    }
    printf("%d", max(0, n-ans));
}
