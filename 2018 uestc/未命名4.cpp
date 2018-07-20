#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001010;
int T, tem, ans;
char ch[MAXN];
int main(){
    scanf("%d", &T);
    while(T--){
        tem = ans = 0;
        int len;
        scanf("%d%s", &len, ch+1);
        for(int i = 1; i <= len; i ++){
            if(ch[i] == '0')
                tem ++;
            else{
                if(tem > 0){
                    ans ++;
                    tem --;
                }
            }
        }
        double prin = len-2*ans;
        printf("%.4lf\n", prin);
    }
    return 0;
}
